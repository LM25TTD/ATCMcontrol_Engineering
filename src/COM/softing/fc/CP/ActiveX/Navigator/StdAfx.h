#if !defined(AFX_STDAFX_H__B3380728_7157_11D1_A4A8_00A024363DFC__INCLUDED_)
#define AFX_STDAFX_H__B3380728_7157_11D1_A4A8_00A024363DFC__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

// stdafx.h : Include-Datei f�r Standard-System-Include-Dateien,
//      oder h�ufig verwendete, projektspezifische Include-Dateien,
//      die nur in unregelm��igen Abst�nden ge�ndert werden.

#define VC_EXTRALEAN		// Selten benutzte Teile der Windows-Header nicht einbinden

#include <afxctl.h>         // MFC-Unterst�tzung f�r ActiveX-Steuerelemente
#include <afxcmn.h>			// MFC support for Windows Common Control classes 
#include <afxtempl.h>

#pragma warning ( disable : 4100 ) 

// Nachstehende zwei Include-Anweisungen l�schen,  falls die MFC nicht verwendet werden sollen
//  Datenbankklassen
#include <afxdb.h>			// MFC-Datenbankklassen
#include <afxdao.h>			// MFC DAO-Datenbankklassen

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio f�gt zus�tzliche Deklarationen unmittelbar vor der vorhergehenden Zeile ein.

#endif // !defined(AFX_STDAFX_H__B3380728_7157_11D1_A4A8_00A024363DFC__INCLUDED_)
