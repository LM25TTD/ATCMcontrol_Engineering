/*****************************************************************************/
/*           PROFIBUS CONFIGURATION AND IMPLEMENTATION DEFINITIONS           */
/*                                                                           */
/*  Filename    : PB_CONF.H                                                  */
/*  Version     : 5.27.0.00.release                                          */
/*  Date        : 30-June-2004                                               */
/*                                                                           */
/*  Description : This file contains the PROFIBUS configuration and          */
/*                implementation definitions using Windows ME/98/95,         */
/*                Windows XP/2000/NT or Windows XP/2000 with RTX operating   */
/*                system                                                     */
/*                                                                           */
/*****************************************************************************/

#ifndef __PB_CONF__
#define __PB_CONF__

/*****************************************************************************/
/* COMPILER SWITCHES FOR COMPABLITY                                          */
/*****************************************************************************/


#ifndef PB_VER
#define PB_VER  527
#endif


/*****************************************************************************/
/* COMPILER SWITCHES DEPENDING ON OPERATING SYSTEM                           */
/*****************************************************************************/

#undef FAR
#undef HUGE

#if defined (WIN32) || defined (_WIN32)                /* compiling as WIN32 */
   #undef  DOS16
   #undef  WIN32
   #undef  EXPORT
   #define WIN32
   #define EXPORT  __export
   #define FAR
   #define HUGE
   #define CALL_CONV  APIENTRY               /* call convention using WIN32 */

   #ifdef UNDER_RTSS
      #undef  CALL_CONV
      #define CALL_CONV  _stdcall            /* call convention using Windows RTX */
   #endif

   #ifdef PB_API_FUNC_NOT_USED
      #undef  CALL_CONV
      #define CALL_CONV                      /* call convention using NT-DDK */
   #endif
#else                                                  /* compiling as WIN16 */
   #if defined (WIN_DLL) || defined (_WINDOWS) || defined (_WINDLL)
       #undef  DOS16
       #undef  WIN16
       #define WIN16
   #endif

   #if defined (WIN16) || defined (_WIN16)
       #undef  DOS16
       #undef  WIN16
       #undef  EXPORT
       #undef  PASCAL
       #define WIN16
       #define EXPORT  __export
       #define FAR      _far
       #define PASCAL   _pascal
       #define CDECL    _cdecl
       #define HUGE   _huge
       #define CALL_CONV FAR pascal         /* calling convention using WIN16 */
   #else
       #error 16-BIT DOS compilation not supported !!!!
   #endif
#endif


/*****************************************************************************/
/*              SUPPORTED SERVICES                                           */
/*****************************************************************************/
#define FMS_SERVICES_SUPPORTED
#define DP_SERVICES_SUPPORTED
#define DPS_SERVICES_SUPPORTED


/*****************************************************************************/
/*                        Implementation Constants                           */
/*                                                                           */
/* The constants given below define the sizes of various data structures in  */
/* the protocol software and thus influence memory consumption.              */
/*                                                                           */
/* NOTE: Do not change the following constants without recompiling the       */
/*       the protocol software on the communication controller               */
/*****************************************************************************/

#define VERSION_STRING_LENGTH        100  /* length of version string buffer */

/* -- constants of internal sizes of byte arrays --------------------------- */

#define VFD_STRING_LENGTH             32     /* max length of the VFD string */
#define IDENT_STRING_LENGTH           32   /* max length of the Ident string */

#define ACCESS_NAME_LENGTH            32    /* max length for name adressing */
#define OBJECT_NAME_LENGTH            32        /* max length of object name */
#define EXTENSION_LENGTH              32   /* max length of object extension */
#define EXECUTION_ARGUMENT_LENGTH     32     /* max length of exec. argument */
#define ERROR_DESCR_LENGTH            32     /* max length of error descript.*/
#define CRL_SYMBOL_LENGTH             32    /* max length of crl symbol name */
#define CRL_EXTENSION_LENGTH           2      /* max length of crl extension */

#if (PB_VER < 500)
#define KBL_SYMBOL_LENGTH             CRL_SYMBOL_LENGTH
#define KBL_EXTENSION_LENGTH          CRL_EXTENSION_LENGTH
#endif

#define MAX_FMS_PDU_LENGTH      241    /* max size of the FMS/FM7-PDU-Buffer */
#define MAX_VAR_LIST_ELEMENTS    50   /* max count of variable list elements */
#define MAX_DOM_LIST_ELEMENTS    50     /* max count of domain list elements */
#define MAX_VAR_RECORD_ELEMENTS  10          /* max count of record elements */

#define MAX_COMREF            64   /* max supported communication references */
#define MAX_VFD                5                       /* max supported VFDs */

#if (PB_VER < 500)
#define MAX_KBL_LEN            MAX_COMREF              /* max entries in CRL */
#define MAX_PARA_LOC_SERVICES  5           /* max parallel local FMS-Services*/
#endif

/*****************************************************************************/
/* USEFUL MACROS                                                             */
/*****************************************************************************/

/*****************************************************************************/
/* MACRO TO CALCULATE MAX_xxxx_NAME_LENGTH                                   */
/*                                                                           */
/* This macro calculates the internal sizes of byte arrays in a way that the */
/* desired alignment on byte, word or long word boundaries is achieved.      */
/* The alignment is specified by the constant ALIGNMENT (e. g. longword = 4) */
/*                                                                           */
/*****************************************************************************/

#define ALIGNMENT                  0x02        /* alignment on word boundary */

#define _NAME_LENGTH(length) ((length) + ALIGNMENT - ((length) % ALIGNMENT))

#endif
