/*H>> $Header: /4CReleased/V2.20.00/COM/softing/fc/CMN/fc_util/XMLencode.cpp 1     28.02.07 19:00 Ln $
 *----------------------------------------------------------------------------*
 *
 * =FILENAME            $Workfile: XMLencode.cpp $
 *                       $Logfile: /4CReleased/V2.20.00/COM/softing/fc/CMN/fc_util/XMLencode.cpp $
 *
 * =PROJECT             7VH102  ATCMControl
 *
 * =SWKE                4CMN
 *
 * =COMPONENT           BaseLib
 *
 * =CURRENT      $Date: 28.02.07 19:00 $
 *           $Revision: 1 $
 *
 * =ENVIRONMENT             Win32:
 *                      MS Windows NT 4.0
 *                      MSVC++ V6.0 / MFC 6.0 / ATL 3.0 / DAO 3.5
 *                      MS Java 2.0
 *                      MS Visual SourceSafe 5.0/6.0
 *
 * =REFERENCES
 *==
 *----------------------------------------------------------------------------*
 *

 *                http://www.4control.de

 

 *==
 *----------------------------------------------------------------------------*
 * =DESCRIPTION
 *    @DESCRIPTION@
 *==
 *----------------------------------------------------------------------------*
 * =MODIFICATION
 *  09.11.98  Je      File created
 *  see history at end of file !
 *==
 *******************************************************************************
 H<<*/

#include "stdafx.h"
#ifndef UTIL_IMP
#define UTIL_IMP    // declare as dllexports
#endif
#include "UtilIF.h"
#include "assert.h"

//----  Local Defines:   -------------------------------------------*

//----  Static Initializations:   ----------------------------------*
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


static LPCTSTR              s_mapCharToName[256];      // lookup table as fast index
static BOOL                 s_bMapInitialized = FALSE;
static CCriticalSection     s_csEncodeMap;


// used to convert between XML escaped and normal strings
static LPCTSTR  Encode(TCHAR ch);
static TCHAR    Decode(LPCTSTR pszNamed);
static void     CheckInitialized();




//------------------------------------------------------------------*
/**
 * BL_XMLEncodeString
 *  encode special characters in string to XML format
 *
 * @param           sIn             string to encode
 * @param           psEncoded       encoded string
 * @param           encoding        character representationto use
 *                                  use XML_ENCODE_DEFAULT (= XML_ENCODE_UTF_8)
 * @return          
 * @exception       -
 * @see             
*/
UTILIF HRESULT
    UTIL_XMLEncodeString(BSTR sIn, BSTR *psEncoded, XML_CHAR_ENCODING encoding)
{
    if (psEncoded == NULL) {
        return E_POINTER;
    }
    *psEncoded = NULL;

    // currently only one representation is supported !
    if (encoding != XML_ENCODE_UTF_8) {
        return E_FAIL;
    }

    CString strIn = sIn;
    LPCTSTR pszStart = strIn;
    LPCTSTR psz = pszStart;
    CString strEncoded;
    while (*psz != _T('\0'))
    {
        LPCTSTR pszName = Encode(*psz);
        if (pszName != NULL)
        {
            if ((psz - pszStart) > 0) {
                strEncoded += CString(pszStart, psz - pszStart);
            }
            strEncoded += pszName;
            pszStart = ++psz;
        }
        else {
            psz++;
        }
    }
    if (psz > pszStart)
    {
        strEncoded += CString(pszStart, psz - pszStart);
    }

    *psEncoded = strEncoded.AllocSysString();
    if (*psEncoded == NULL) {
        return E_OUTOFMEMORY;
    }

    return S_OK;
}


//------------------------------------------------------------------*
/**
 * BL_XMLDecodeString
 *  decode escaped special characters in string from XML format to binary format
 *
 * @param           sIn             string to decode
 * @param           psDecoded       decoded string
 * @param           encoding        character representationto use
 *                                  use XML_ENCODE_DEFAULT (= XML_ENCODE_UTF_8)
 * @return          
 * @exception       -
 * @see             
*/
UTILIF HRESULT
    UTIL_XMLDecodeString(BSTR sIn, BSTR *psDecoded, XML_CHAR_ENCODING encoding)
{
    if (psDecoded == NULL) {
        return E_POINTER;
    }
    *psDecoded = NULL;

    // currently only one representation is supported !
    if (encoding != XML_ENCODE_UTF_8) {
        return E_FAIL;
    }

    CString strRaw = sIn;
    CString strDecoded;
    // scan thru string for a leading ampersand (&)
    LPCTSTR pszStart = strRaw;
    LPCTSTR psz = pszStart;
    while (*psz != _T('\0'))
    {
        if (*psz == _T('&'))
        {
            // fetch trailing semicolon; should be within 10 characters!!
            int iLock = 10;
            LPCTSTR pszSearch = psz + 1;
            while ((*pszSearch != _T('\0')) && (iLock > 0))
            {
                if (*pszSearch == _T(';'))
                {
                    // got a named character!
                    TCHAR ch = Decode(CString(psz, pszSearch - psz + 1));
                    
                    if ((psz - pszStart) > 0) {
                        strDecoded += CString(pszStart, psz - pszStart);
                    }
                    if(ch)
                    {
                        strDecoded += ch;
                    }
                    else
                    {
                        assert(!"unknown XML char escape");
                        strDecoded += CString(psz, pszSearch - psz + 1);
                    }
                    psz = pszStart = ++pszSearch;
                    break;  // get out of name end search while-loop
                }
                iLock--;
                pszSearch++;
            }
            if (iLock <= 0) {
                // didn't find delimiting ampersand, go on to next character
                psz++;
            }
        }
        else {
            psz++;
        }
    }
    if (psz > pszStart)
    {
        strDecoded += CString(pszStart, psz - pszStart);
    }

    *psDecoded = strDecoded.AllocSysString();
    if (*psDecoded == NULL) {
        return E_OUTOFMEMORY;
    }

    return S_OK;
}

//------------------------------------------------------------------*

static struct _tagTranslation {
    TCHAR   ch;
    LPCTSTR pszNamedEntity;//<- do not use named entity for encoding
                           //reason: java xml parsers don't understand this!
    LPCTSTR pszNamedWithNum;
} s_translation[] = 
{
    _T('\t'), _T("&#09;"), _T("&#09;"),
    _T('\n'), _T("&#10;"), _T("&#10;"),
    _T('\r'), _T("&#13;"), _T("&#13;"),
    _T(' '), _T("&#32;"), _T("&#32;"),
    _T('"'), _T("&quot;"), _T("&#34;"),
    _T('&'), _T("&amp;"),  _T("&#38;"),
    _T('\''), _T("&apos;"), _T("&#39;"),
    _T('<'), _T("&lt;"),   _T("&#60;"),
    _T('>'), _T("&gt;"),   _T("&#62;"),
    _T(']'), _T("&#93;"),  _T("&#93;"),
    _T('['), _T("&#91;"),  _T("&#91;"),
    //(TCHAR)128, _T("&#128;"),  _T("&#128;"),//<-TODO: euro sign how to?
    _T('�'), _T("&iexcl;"),_T("&#161;"),
    _T('�'), _T("&cent;"), _T("&#162;"), 
    _T('�'), _T("&pound;"),_T("&#163;"),  
    _T('�'), _T("&curren;"),_T("&#164;"), 
    _T('�'), _T("&yen;"),   _T("&#165;"), 
    _T('�'), _T("&brvbar;"),_T("&#166;"), 
    _T('�'), _T("&sect;"),  _T("&#167;"), 
    _T('�'), _T("&uml;"),   _T("&#168;"), 
    _T('�'), _T("&copy;"),  _T("&#169;"), 
    _T('�'), _T("&ordf;"),  _T("&#170;"), 
    _T('�'), _T("&laquo;"), _T("&#171;"), 
    _T('�'), _T("&not;"),   _T("&#172;"), 
    _T('�'), _T("&shy;"),   _T("&#173;"), 
    _T('�'), _T("&reg;"),   _T("&#174;"), 
    _T('�'), _T("&macr;"),  _T("&#175;"), 
    _T('�'), _T("&deg;"),   _T("&#176;"), 
    _T('�'), _T("&plusmn;"),_T("&#177;"),  
    _T('�'), _T("&sup2;"),  _T("&#178;"), 
    _T('�'), _T("&sup3;"),  _T("&#179;"),
    _T('�'), _T("&acute;"), _T("&#180;"),
    _T('�'), _T("&micro;"), _T("&#181;"),
    _T('�'), _T("&para;"),  _T("&#182;"),
    _T('�'), _T("&middot;"),_T("&#183;"),
    _T('�'), _T("&cedil;"), _T("&#184;"),
    _T('�'), _T("&sup1;"),  _T("&#185;"),
    _T('�'), _T("&ordm;"),  _T("&#186;"),
    _T('�'), _T("&raquo;"), _T("&#187;"),
    _T('�'), _T("&frac14;"),_T("&#188;"),
    _T('�'), _T("&frac12;"),_T("&#189;"),
    _T('�'), _T("&frac34;"),_T("&#190;"),
    _T('�'), _T("&iquest;"),_T("&#191;"),
    _T('�'), _T("&Agrave;"),_T("&#192;"),
    _T('�'), _T("&Aacute;"),_T("&#193;"),
    _T('�'), _T("&Acirc;"), _T("&#194;"),
    _T('�'), _T("&Atilde;"),_T("&#195;"),
    _T('�'), _T("&Auml;"),  _T("&#196;"),
    _T('�'), _T("&Aring;"), _T("&#197;"),
    _T('�'), _T("&AElig;"), _T("&#198;"),
    _T('�'), _T("&Ccedil;"),_T("&#199;"),
    _T('�'), _T("&Egrave;"),_T("&#200;"),
    _T('�'), _T("&Eacute;"),_T("&#201;"),
    _T('�'), _T("&Ecirc;"), _T("&#202;"),
    _T('�'), _T("&Euml;"),  _T("&#203;"),
    _T('�'), _T("&Igrave;"),_T("&#204;"),
    _T('�'), _T("&Iacute;"),_T("&#205;"),
    _T('�'), _T("&Icirc;"), _T("&#206;"),
    _T('�'), _T("&Iuml;"),  _T("&#207;"),
    _T('�'), _T("&ETH;"),   _T("&#208;"),
    _T('�'), _T("&Ntilde;"),_T("&#209;"),
    _T('�'), _T("&Ograve;"),_T("&#210;"),
    _T('�'), _T("&Oacute;"),_T("&#211;"),
    _T('�'), _T("&Ocirc;"), _T("&#212;"),
    _T('�'), _T("&Otilde;"),_T("&#213;"),
    _T('�'), _T("&Ouml;"),  _T("&#214;"),
    _T('�'), _T("&times;"), _T("&#215;"),
    _T('�'), _T("&Oslash;"),_T("&#216;"),
    _T('�'), _T("&Ugrave;"),_T("&#217;"),
    _T('�'), _T("&Uacute;"),_T("&#218;"), 
    _T('�'), _T("&Ucirc;"), _T("&#219;"),
    _T('�'), _T("&Uuml;"),  _T("&#220;"),
    _T('�'), _T("&Yacute;"),_T("&#221;"),
    _T('�'), _T("&THORN;"), _T("&#222;"),
    _T('�'), _T("&szlig;"), _T("&#223;"),
    _T('�'), _T("&agrave;"),_T("&#224;"),
    _T('�'), _T("&aacute;"),_T("&#225;"),
    _T('�'), _T("&acirc;"), _T("&#226;"),
    _T('�'), _T("&atilde;"),_T("&#227;"), 
    _T('�'), _T("&auml;"),  _T("&#228;"),
    _T('�'), _T("&aring;"), _T("&#229;"),
    _T('�'), _T("&aelig;"), _T("&#230;"),
    _T('�'), _T("&ccedil;"),_T("&#231;"),
    _T('�'), _T("&egrave;"),_T("&#232;"),
    _T('�'), _T("&eacute;"),_T("&#233;"),
    _T('�'), _T("&ecirc;"), _T("&#234;"),
    _T('�'), _T("&euml;"),  _T("&#235;"),
    _T('�'), _T("&igrave;"),_T("&#236;"), 
    _T('�'), _T("&iacute;"),_T("&#237;"),
    _T('�'), _T("&icirc;"), _T("&#238;"),
    _T('�'), _T("&iuml;"),  _T("&#239;"),
    _T('�'), _T("&eth;"),   _T("&#240;"),
    _T('�'), _T("&ntilde;"),_T("&#241;"),
    _T('�'), _T("&ograve;"),_T("&#242;"),
    _T('�'), _T("&oacute;"),_T("&#243;"),
    _T('�'), _T("&ocirc;"), _T("&#244;"),
    _T('�'), _T("&otilde;"),_T("&#245;"),
    _T('�'), _T("&ouml;"),  _T("&#246;"),
    _T('�'), _T("&divide;"),_T("&#247;"),
    _T('�'), _T("&oslash;"),_T("&#248;"),
    _T('�'), _T("&ugrave;"),_T("&#249;"),
    _T('�'), _T("&uacute;"),_T("&#250;"),
    _T('�'), _T("&ucirc;"), _T("&#251;"),
    _T('�'), _T("&uuml;"),  _T("&#252;"),
    _T('�'), _T("&yacute;"),_T("&#253;"),
    _T('�'), _T("&thorn;"), _T("&#254;"),
    _T('�'), _T("&yuml;"),  _T("&#255;"),
    0, NULL, NULL
};



//------------------------------------------------------------------*
/**
 * CheckInitialized     check and initialize encode/decode map,
 *
 * @param            
 * @return           
 * @exception       -
 * @see              
 */
void
    CheckInitialized()
{
    CSingleLock secured(&s_csEncodeMap, TRUE);
    if (!s_bMapInitialized)
    {
#define MUST_BE_ANSI_NOT_UNICODE    sizeof(TCHAR) == 1
        assert(MUST_BE_ANSI_NOT_UNICODE);     // map works for ANSI code only, recode for UNICODE !!!!!
        // build translation map
#define MAX_INDEX   (sizeof(s_mapCharToName) / sizeof(LPCTSTR))
        ::memset(s_mapCharToName, 0, sizeof(s_mapCharToName));
        struct _tagTranslation *pMap = s_translation;
        while (pMap->ch != 0)
        {
            unsigned offs = unsigned((UCHAR) pMap->ch);
#define ERROR_MAP_OFFSET_TOO_LARGE      offs <= 255
            assert(ERROR_MAP_OFFSET_TOO_LARGE);
            if (offs < MAX_INDEX) {
                s_mapCharToName[offs] = pMap->pszNamedWithNum;
            }
            pMap++;
        }
        s_bMapInitialized = TRUE;
    }
}

//------------------------------------------------------------------*
/**
 * Encode
 *
 * @param            
 * @return           
 * @exception        HRESULT
 * @see              
 */
LPCTSTR
    Encode(TCHAR ch)
{
    CheckInitialized();
    // lookup in map
    assert((UCHAR)ch <= MAX_INDEX);
    return s_mapCharToName[(UCHAR)ch];
}

//------------------------------------------------------------------*
/**
 * Decode
 *
 * @param            
 * @return           
 * @exception        HRESULT
 * @see              
 */
TCHAR
    Decode(LPCTSTR pszNamed)
{
    
    //used a number ?
    //&#222
    if(pszNamed[0] && pszNamed[1] && _istascii(pszNamed[2]) && _istdigit(pszNamed[2]))
    {
        unsigned int iascii = _ttoi(pszNamed+2);
        return iascii <=255 ? iascii : 0;
    }
    
    CheckInitialized();

    // %TBD% quick and dirty solution, should be a map !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    struct _tagTranslation *pMap = s_translation;
    TCHAR chRet = _T('\0');
    while (pMap->ch != 0)
    {
        if (_tcscmp(pMap->pszNamedEntity, pszNamed) == 0) {
            chRet = pMap->ch;
            break;
        }
        pMap++;
    }
    return chRet;
}



/*
 *----------------------------------------------------------------------------*
 *  $History: XMLencode.cpp $
 * 
 * *****************  Version 1  *****************
 * User: Ln           Date: 28.02.07   Time: 19:00
 * Created in $/4CReleased/V2.20.00/COM/softing/fc/CMN/fc_util
 * 
 * *****************  Version 2  *****************
 * User: Sis          Date: 29.10.03   Time: 15:56
 * Updated in $/4Control/COM/softing/fc/CMN/fc_util
 * added &apos; to translation map
 * 
 * *****************  Version 1  *****************
 * User: Ln           Date: 28.08.03   Time: 16:33
 * Created in $/4Control/COM/softing/fc/CMN/fc_util
 * 
 * *****************  Version 1  *****************
 * User: Ef           Date: 23.01.01   Time: 17:10
 * Created in $/4Control/COM/softing/fc/CMN/fc_util
 * utils and baselib from V1.3
 * 
 * *****************  Version 8  *****************
 * User: Rf           Date: 13.08.99   Time: 16:38
 * Updated in $/4Control/COM/softing/fc/CMN/UTIL
 * Always use _istascii before specialized _ist...
 * 
 * *****************  Version 7  *****************
 * User: Ef           Date: 5.08.99    Time: 18:06
 * Updated in $/4Control/COM/softing/fc/CMN/UTIL
 * removed the euro sign , this didi not solve the problem in xml
 * attributes,
 * so better don't do it yet. In Cdata section it's worrks anyway
 * 
 * *****************  Version 6  *****************
 * User: Ef           Date: 30.07.99   Time: 20:17
 * Updated in $/4Control/COM/softing/fc/CMN/UTIL
 * escape all white space
 * 
 * *****************  Version 5  *****************
 * User: Ef           Date: 30.07.99   Time: 18:41
 * Updated in $/4Control/COM/softing/fc/CMN/UTIL
 * fixed problem with &quot; and 4CConsole, use &#34; instead on encode,
 * decode understands both.
 * 
 * *****************  Version 4  *****************
 * User: Ef           Date: 25.05.99   Time: 18:34
 * Updated in $/4Control/COM/softing/fc/CMN/UTIL
 * XMLEn/Decode: replace " with &#34; and vice versa
 * 
 * *****************  Version 3  *****************
 * User: Je           Date: 25.11.98   Time: 12:43
 * Updated in $/4Control/COM/softing/fc/CMN/UTIL
 * * fixed d-1114
 * 
 * *****************  Version 2  *****************
 * User: Je           Date: 23.11.98   Time: 12:08
 * Updated in $/4Control/COM/softing/fc/CMN/UTIL
 * * moved XMLEncode/Decode from BaseLib to Util
 * 
 * *****************  Version 1  *****************
 * User: Je           Date: 23.11.98   Time: 11:36
 * Created in $/4Control/COM/softing/fc/CMN/UTIL
 * * moved from baseLib to Util
 * 
 * *****************  Version 2  *****************
 * User: Je           Date: 17.11.98   Time: 15:31
 * Updated in $/4Control/COM/softing/fc/CMN/baselib
 * * encode [ and ] to work around bug in IE4's msXML control
 * 
 * *****************  Version 1  *****************
 * User: Je           Date: 9.11.98    Time: 18:40
 * Created in $/4Control/COM/softing/fc/CMN/baselib
 *==
 *----------------------------------------------------------------------------*
*/

// 09.11.98  Generated by VC++6.0 VBScript '4C Macros.dsm' Version 1.2/Je
// ***************************  E O F  ******************************
// $Workfile: XMLencode.cpp $
