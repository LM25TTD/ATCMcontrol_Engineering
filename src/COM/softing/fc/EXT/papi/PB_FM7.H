/*****************************************************************************/
/*                  FM7-USER-INTERFACE DEFINES and TYPES                     */
/*                                                                           */
/*  Filename    : PB_FM7.H                                                   */
/*  Version     : 5.21.0.00.release                                          */
/*  Date        : 27-February-1998                                           */
/*                                                                           */
/*  Description : This file contains the types and defines of the FM7-User-  */
/*                Interface                                                  */
/*                                                                           */
/*****************************************************************************/

#ifndef __PB_FM7__
#define __PB_FM7__


#pragma warning (disable : 4103)     /* used #pragma pack to change alignment */
#ifdef WIN32
#pragma pack(push,2)
#else
#pragma pack(2)
#endif
#pragma warning (default : 4103)


/****************************************************************************/
/*************    FM7-SERVICE-IDENTIFIERS                ********************/
/****************************************************************************/

/*---FM7-Service-Identifiers ---------------------------------------------  */
#define FM7_INITIATE               0
#define FM7_ABORT                 38

#define FM7_READ_CRL_REM           1
#define FM7_INIT_LOAD_CRL_REM      2
#define FM7_LOAD_CRL_REM           3
#define FM7_TERM_LOAD_CRL_REM      4
#define FM7_SET_VALUE_REM          5
#define FM7_READ_VALUE_REM         6
#define FM7_LSAP_STATUS_REM        7
#define FM7_IDENT_REM              8

#define FM7_READ_CRL_LOC          11
#define FM7_INIT_LOAD_CRL_LOC     12
#define FM7_LOAD_CRL_LOC          13
#define FM7_TERM_LOAD_CRL_LOC     14
#define FM7_SET_VALUE_LOC         15
#define FM7_READ_VALUE_LOC        16
#define FM7_LSAP_STATUS_LOC       17
#define FM7_IDENT_LOC             18
#define FM7_EVENT                 19
#define FM7_RESET                 20
#define FM7_EXIT                  21
#define FM7_SET_BUSPARAMETER      22
#define FM7_READ_BUSPARAMETER     24
#define FM7_GET_LIVE_LIST         26

#if (PB_VER < 500)
#define FMA7_INITIATE             FM7_INITIATE
#define FMA7_READ_KBL_REM         FM7_READ_CRL_REM
#define FMA7_INIT_LOAD_KBL_REM    FM7_INIT_LOAD_CRL_REM
#define FMA7_LOAD_KBL_REM         FM7_LOAD_CRL_REM
#define FMA7_TERM_LOAD_KBL_REM    FM7_TERM_LOAD_CRL_REM
#define FMA7_SET_VALUE_REM        FM7_SET_VALUE_REM
#define FMA7_READ_VALUE_REM       FM7_READ_VALUE_REM
#define FMA7_LSAP_STATUS_REM      FM7_LSAP_STATUS_REM
#define FMA7_IDENT_REM            FM7_IDENT_REM
#define FMA7_ABORT                FM7_ABORT

#define FMA7_READ_KBL_LOC         FM7_READ_CRL_LOC
#define FMA7_INIT_LOAD_KBL_LOC    FM7_INIT_LOAD_CRL_LOC
#define FMA7_LOAD_KBL_LOC         FM7_LOAD_CRL_LOC
#define FMA7_TERM_LOAD_KBL_LOC    FM7_TERM_LOAD_CRL_LOC
#define FMA7_SET_VALUE_LOC        FM7_SET_VALUE_LOC
#define FMA7_READ_VALUE_LOC       FM7_READ_VALUE_LOC
#define FMA7_LSAP_STATUS_LOC      FM7_LSAP_STATUS_LOC
#define FMA7_IDENT_LOC            FM7_IDENT_LOC

#define FMA7_EVENT                FM7_EVENT
#define FMA7_RESET                FM7_RESET

#define FMA7_PROFIBUS_EXIT        FM7_EXIT
#define FMA7_EXIT                 FM7_EXIT
#define FMA7_SET_BUSPARAMETER     FM7_SET_BUSPARAMETER
#define FMA7_SET_STATISTIC_CTR    23
#define FMA7_READ_BUSPARAMETER    FM7_READ_BUSPARAMETER
#define FMA7_READ_STATISTIC_CTR   25
#define FMA7_GET_LIVE_LIST        FM7_GET_LIVE_LIST
#define FMA7_SET_CONFIGURATION    27
#define FMA7_EXCEPTION            28
#endif


/****************************************************************************/
/*************   FM7-STRING-LENGTH-CONSTANTS             ********************/
/****************************************************************************/

#define MAX_CRL_EXTENSION_LENGTH       _NAME_LENGTH(CRL_EXTENSION_LENGTH+1)
#define MAX_CRL_SYMBOL_LENGTH          _NAME_LENGTH(CRL_SYMBOL_LENGTH)

#if (PB_VER < 500)
#define MAX_KBL_EXTENSION_LENGTH       MAX_CRL_EXTENSION_LENGTH
#define MAX_KBL_SYMBOL_LENGTH          MAX_CRL_SYMBOL_LENGTH
#endif


#define MAX_IDENT_STRING_LENGTH        _NAME_LENGTH(IDENT_STRING_LENGTH)


/****************************************************************************/
/* FM7-Context-Management                                                  */
/****************************************************************************/

#define DETAIL_LENGTH 16      /* length of abort detail                     */
#define FEAT_SUPP_LEN  6      /* length of supported feature field          */


/****************************************************************************/
/* Initiate Service                                                         */
/****************************************************************************/

typedef struct _T_FM7_INIT_REQ
{
  USIGN8  snd_len_low;                        /* max FM7 PDU size to send with low priority    */
  USIGN8  rcv_len_low;                        /* max FM7 PDU size to receive with low priority */
  USIGN8  supported_services[FEAT_SUPP_LEN];  /* supported FM7 services                        */
} T_FM7_INIT_REQ;

#if (PB_VER < 500)
typedef T_FM7_INIT_REQ     T_FMA_INIT_REQ;
#endif


typedef struct _T_FM7_INIT_ERR_CNF
{
  USIGN16 class_code;                         /* error code and class                           */
  USIGN8  snd_len_low;                        /* max FM7 PDU size to send with low priority    */
  USIGN8  rcv_len_low;                        /* max FM7 PDU size to receive with low priority */
  USIGN8  supported_services[FEAT_SUPP_LEN];  /* supported FM7 services                        */
} T_FM7_INIT_ERR_CNF;

#if (PB_VER < 500)
typedef T_FM7_INIT_ERR_CNF T_FMA_INIT_ERR_CNF;
#endif


/****************************************************************************/
/* Abort Service                                                            */
/****************************************************************************/

typedef struct _T_FM7_ABORT_REQ
{
  PB_BOOL  local;                   /* local or remote detected             */
  USIGN8   abort_id;                /* identifier (USR,LLI_USR,LLI,FDL)     */
  USIGN8   reason;                  /* abort reason code                    */
  USIGN8   detail_length;           /* length of detail information         */
  USIGN8   detail[DETAIL_LENGTH];   /* detail information about the reason  */
} T_FM7_ABORT_REQ;

#if (PB_VER < 500)
typedef T_FM7_ABORT_REQ     T_FMA_ABORT_REQ;
#endif



/****************************************************************************/
/* CRL-Management                                                           */
/****************************************************************************/

/* --- special values of segment address ---------------------------------- */
#define NO_SEGMENT              255

/* --- special values of station address ---------------------------------- */
#define GLOBAL_ADDRESS           127
#define ALL                     0xFF

/* --- special LSAP values ------------------------------------------------ */
#define BRCT_SAP                 63
#define DEFAULT_SAP             128

/* --- LLI-SAP ------------------------------------------------------------ */
#define FMS_SAP                0x00
#define FM7_SAP                0x01

#if (PB_VER < 500)
#define FMA7_SAP               FM7_SAP
#endif

/* --- connection type (CR-Type/LLI-Warning/LLI-Event/Role-in-Type) ------- */
/* --- CR-Types ----------------------------------------------------------- */
#define MMAC                   0x00
#define MSAC                   0x01
#define MSAC_SI                0x05
#define MSCY                   0x03
#define MSCY_SI                0x07
#define BRCT                   0x08
#define MULT                   0x0A
#define MSCY_D                 0x0B
#define MSCY_DSI               0x0F

#if (PB_VER < 500)
#define MMAZ                   MMAC
#define MSAZ                   MSAC
#define MSAZ_SI                MSAC_SI
#define MSZY                   MSCY
#define MSZY_SI                MSCY_SI
#endif

/* --- LLI-Warning -------------------------------------------------------- */
#define LLI_W                  0x40

/* --- LLI-Event ---------------------------------------------------------- */
#define LLI_E                  0x80

/* --- Role-in-Type ------------------------------------------------------- */
#define MM_RES                 0x10
#define MM_REQ                 0x20
#define MM_REQ_RES             0x30

#define MS_RES                 0x10
#define MS_REQ                 0x20

#define CL_RCV                 0x10
#define CL_REQ                 0x20

/* --- connection-attribute (connection-attribute) ----------------------- */
/* --- connection-attribute ---------------------------------------------- */
#define D_CONN                 0x00
#define I_CONN                 0x01
#define O_CONN                 0x02


/*--- CRL-Header -----------------------------------------------------------*/
typedef struct _T_CRL_HDR
{
  INT16          nr_of_entries;             /* number of CRL enries         */
  USIGN8         poll_sap;                  /* poll list SAP                */
  USIGN8         symbol_length;             /* max symbol lenght in CRL     */
  USIGN32        ass_abt_ci;                /* ASS / ABT controll intervall */
  PB_BOOL        vfd_pointer_supported;     /* VFD pointer supported        */
  USIGN8         dummy;                     /* alignment byte               */
} T_CRL_HDR;

#if (PB_VER < 500)
typedef T_CRL_HDR T_KBL_HDR;
#endif

/*--- CRL-Static-Entry -----------------------------------------------------------*/
typedef struct _T_CRL_STATIC
{
   USIGN8    loc_lsap;                       /* local LSAP                        */
   USIGN8    rem_add;                        /* remote address                    */
   USIGN8    rem_segm;                       /* remote segment                    */
   USIGN8    rem_lsap;                       /* remote LSAP                       */
   USIGN8    conn_type;                      /* connection type                   */
   USIGN8    lli_sap;                        /* LLI-SAP                           */
   USIGN8    multiplier;                     /* multiplier in cyclic connections  */
   USIGN8    conn_attr;                      /* connection attribute              */
   USIGN8    max_scc;                        /* max. of send confirmed counter    */
   USIGN8    max_rcc;                        /* max. of receive confirmed counter */
   USIGN8    max_sac;                        /* max. of send acknowledged counter */
   USIGN8    max_rac;                        /* max. of receive acknowledged ctr  */
   USIGN32   ci;                             /* controll intervall                */
   USIGN8    max_pdu_snd_high;               /* max. length of FMS-PDU send high  */
   USIGN8    max_pdu_snd_low;                /* max. length of FMS-PDU send low   */
   USIGN8    max_pdu_rcv_high;               /* max. length of FMS-PDU rcv high   */
   USIGN8    max_pdu_rcv_low;                /* max. length of FMS-PDU rcv low    */
   USIGN8    feature_supp[FEAT_SUPP_LEN];    /* FMS features supported            */
   STRINGV   symbol[MAX_CRL_SYMBOL_LENGTH];  /* symbolic name                     */
   USIGN32   vfd_pointer;                    /* vfd number                        */
   USIGN8    extension[MAX_CRL_EXTENSION_LENGTH]; /* CRL-Extension                */
} T_CRL_STATIC;

#if (PB_VER < 500)
typedef T_CRL_STATIC T_KBL_STATIC;
#endif

/*--- CRL-Dynamic-Entry ----------------------------------------------------*/
typedef struct _T_CRL_DYNAMIC
{
  USIGN8         rem_add;                   /* current remote address       */
  USIGN8         rem_segm;                  /* current remote segment       */
  USIGN8         rem_lsap;                  /* current remote LSAP          */
  USIGN8         scc;                       /* send confirmed counter       */
  USIGN8         rcc;                       /* receive confirmed counter    */
  USIGN8         sac;                       /* send acknowledged counter    */
  USIGN8         rac;                       /* receive acknowledged counter */
  PB_BOOL        poll_entry_enabled;        /* poll entry flag              */
  USIGN8         master_role;               /* current master role          */
  USIGN8         dummy;                     /* alignment byte               */
} T_CRL_DYNAMIC;

#if (PB_VER < 500)
typedef T_CRL_DYNAMIC T_KBL_DYNAMIC;
#endif


/****************************************************************************/
/*  Load-CRL Services    (Local and Remote)                                 */
/****************************************************************************/

/*--- Load-CRL-Service -----------------------------------------------------*/
typedef struct _T_LOAD_CRL_REQ
{
  USIGN16         desired_cr;            /* desired communication reference */
  union
  {
    T_CRL_HDR     crl_hdr;               /* CRL-Header-Entry                */
    T_CRL_STATIC  crl_static;            /* CRL-Static-Entry                */
  } id;
} T_LOAD_CRL_REQ;

#if (PB_VER < 500)
typedef struct _T_LOAD_KBL_REQ
{
  USIGN16         desired_cr;            /* desired communication reference */
  union
  {
    T_KBL_HDR     kbl_hdr;               /* CRL-Header-Entry                */
    T_KBL_STATIC  kbl_static;            /* CRL-Static-Entry                */
  } id;
} T_LOAD_KBL_REQ;
#endif


/****************************************************************************/
/* Read-CRL Service  (Local and Remote)                                     */
/****************************************************************************/
/* --- crl-stati of the LLI state machine --------------------------------- */

#define CLOSED                      0

/* --- Associate ---------------------------------------------------------- */
#define ASS_REQ_ACT_SAP             1
#define ASS_SEND_UPDATE             2
#define ASS_POLL_LIST_ON            3
#define ASS_REQ_WAIT_FOR_CON        4
#define ASS_REQ_WAIT_FOR_RES        5
#define ASS_POLL_LIST_OFF           6

#define ASS_RES_DEACT_SAP           7
#define ASS_RES_ACT_SAP             8
#define ASS_WAIT_LOC_RES            9
#define ASS_SEND_RES_PDU           10
#define ASS_REPLY_UPDATE           11

/* --- Abort -------------------------------------------------------------- */
#define ABT_UPDATE                 12
#define ABT_POLL_LIST_ON           13
#define ABT_SEND_PDU               14
#define ABT_POLL_LIST_OFF          15
#define ABT_ACT_SAP                16
#define ABT_DEACT_SAP              17

/* --- Open Connection ---------------------------------------------------- */
#define OPEN                       18
#define OP_POLL_LIST_ON            19
#define OP_POLL_LIST_OFF           20

/* --- DTC Requester (acyclic) -------------------------------------------- */
#define DTC_WAIT_FOR_REQ            0
#define DTC_SEND_UPDATE             1
#define DTC_WAIT_FOR_CON            2
#define DTC_WAIT_FOR_RES            3

/* --- DTC Responder  (acyclic) ------------------------------------------- */
#define DTC_WAIT_FOR_REQ_PDU        0
#define DTC_WAIT_FOR_LOC_RES        1
#define DTC_REPLY_UPDATE            2
#define DTC_SEND_RES                3

/* --- DTC Requester (cyclic) --------------------------------------------- */
#define DTZ_WAIT_FOR_REQ            0
#define DTZ_SEND_UPDATE             1
#define DTZ_WAIT_FOR_CON            2
#define DTZ_WAIT_FOR_RES            3
#define DTZ_WAIT_FOR_CYC_RES        4

/* --- DTC Responder  (cyclic) -------------------------------------------- */
#define DTZ_WAIT_FOR_REQ_PDU        0
#define DTZ_WAIT_FOR_FMS_RES        1
#define DTZ_REPLY_UPDATE            2
#define DTZ_SEND_RES                3

/* --- DTA Requester ------------------------------------------------------ */
#define DTA_WAIT_FOR_REQM           0
#define DTA_SEND_UPDATE             1
#define DTA_WAIT_FOR_CON            2

#define DTA_WAIT_FOR_REQS           3
#define DTA_REPLY_UPDATE            4
#define DTA_WAIT_FOR_IND            5

/* --- DTA Responder ------------------------------------------------------ */
#define DTA_WAIT_FOR_REQ_PDU        0

#define DTA_H_WAIT_FOR_BUFFER_FREE  1
#define DTA_H_REPLY_UPDATE          2
#define DTA_H_SEND_ACK              3

#define DTA_L_WAIT_FOR_BUFFER_FREE  4
#define DTA_L_UPDATE                5
#define DTA_L_SEND_ACK              6

/* --- IDLE Requester ----------------------------------------------------- */
#define IDLE_WAIT_FOR_REQM          0
#define IDLE_WAIT_FOR_CON           1
#define IDLE_SEND_UPDATE            2

#define IDLE_WAIT_FOR_REQS          3
#define IDLE_REPLY_UPDATE           4
#define IDLE_WAIT_FOR_IND           5

/* --- DTU Requester ------------------------------------------------------ */
#define CONLS_REQ                   0
#define CONLS_WAIT_FOR_CON          1

/* --- DTU Receiver ------------------------------------------------------- */
#define CONLS_SERVER                0



typedef struct _T_READ_CRL_REQ
{
  USIGN16         desired_cr;           /* desired communication reference  */
} T_READ_CRL_REQ;

#if (PB_VER < 500)
typedef T_READ_CRL_REQ  T_READ_KBL_REQ;
#endif

/*--- CRL-Entry Data-Type --------------------------------------------------*/
typedef struct _T_CRL_ENTRY
{
   T_CRL_STATIC   crl_static;                   /* CRL-Static-Entry         */
   T_CRL_DYNAMIC  crl_dynamic;                  /* CRL-Dynamic-Entry        */
   USIGN8         dummy;                        /* alignment                */
   USIGN8         crl_status_len;               /* length of CRL-Status     */
/* USIGN8         crl_status[crl_status_len];      CRL-Status               */
} T_CRL_ENTRY;

#if (PB_VER < 500)
typedef struct _T_KBL_ENTRY
{
   T_KBL_STATIC   kbl_static;                   /* CRL-Static-Entry         */
   T_KBL_DYNAMIC  kbl_dynamic;                  /* CRL-Dynamic-Entry        */
   USIGN8         dummy;                        /* alignment                */
   USIGN8         kbl_status_len;               /* length of CRL-Status     */
/* USIGN8         kbl_status[crl_status_len];      CRL-Status               */
} T_KBL_ENTRY;
#endif


typedef struct _T_READ_CRL_CNF
{
  USIGN16          desired_cr;           /* desired communication reference */
  union
  {
    T_CRL_HDR      crl_hdr;              /* CRL-header                      */
    T_CRL_ENTRY    crl_entry;            /* CRL-Entry                       */
  } id;
} T_READ_CRL_CNF;

#if (PB_VER < 500)
typedef struct _T_READ_KBL_CNF
{
  USIGN16          desired_cr;           /* desired communication reference */
  union
  {
    T_KBL_HDR      kbl_hdr;              /* CRL-header                      */
    T_KBL_ENTRY    kbl_entry;            /* CRL-Entry                       */
  } id;
} T_READ_KBL_CNF;
#endif

/****************************************************************************/
/* SET- and READ-BUSPARAMETER SERVICES                                      */
/****************************************************************************/

/****************************************************************************/
/* Set-Busparameter Service (only local)                                    */
/****************************************************************************/

/* --- Baudrate ------------------------------------------------------------ */
#define KBAUD_9_6                  0x00
#define KBAUD_19_2                 0x01
#define KBAUD_45_45                0x0B
#define KBAUD_93_75                0x02
#define KBAUD_187_5                0x03
#define KBAUD_500                  0x04
#define KBAUD_750                  0x05
#define MBAUD_1_5                  0x06
#define MBAUD_3                    0x07
#define MBAUD_6                    0x08
#define MBAUD_12                   0x09


#if (PB_VER < 500)
#define C_KBAUD_9_6                KBAUD_9_6
#define C_KBAUD_19_2               KBAUD_19_2
#define C_KBAUD_45_45              KBAUD_45_45
#define C_KBAUD_93_75              KBAUD_93_75
#define C_KBAUD_187_5              KBAUD_187_5
#define C_KBAUD_500                KBAUD_500
#define C_KBAUD_750                KBAUD_750
#define C_MBAUD_1_5                MBAUD_1_5
#define C_MBAUD_3                  MBAUD_3
#define C_MBAUD_6                  MBAUD_6
#define C_MBAUD_12                 MBAUD_12
#endif

/* --- Medium-Redundancy -------------------------------------------------- */
#define NO_REDUNDANCY              0x00
#define BUS_A_HIGHPRIOR            0x01
#define BUS_B_HIGHPRIOR            0x02
#define REDUNDANCY                 0x03

#if (PB_VER < 500)
#define C_NO_REDUNDANCY            NO_REDUNDANCY
#define C_BUS_A_HIGHPRIOR          BUS_A_HIGHPRIOR
#define C_BUS_B_HIGHPRIOR          BUS_B_HIGHPRIOR
#define C_REDUNDANCY               REDUNDANCY
#endif

/* --- In-Ring-Desired ---------------------------------------------------- */
#define IN_RING_DESIRED            PB_TRUE
#define NOT_IN_RING_DESIRED        PB_FALSE

#if (PB_VER < 500)
#define C_IN_RING_DESIRED          IN_RING_DESIRED
#define C_NOT_IN_RING_DESIRED      NOT_IN_RING_DESIRED
#endif

typedef struct _T_SET_BUSPARAMETER_REQ
{
  USIGN8         loc_add;            /* local station                 */
  USIGN8         loc_segm;           /* local segment                 */
  USIGN8         baud_rate;          /* baud rate                     */
  USIGN8         medium_red;         /* medium redundancy             */
  USIGN16        tsl;                /* slot time                     */
  USIGN16        min_tsdr;           /* min. station delay time resp. */
  USIGN16        max_tsdr;           /* max. station delay time resp. */
  USIGN8         tqui;               /* quiet time                    */
  USIGN8         tset;               /* setup time                    */
  USIGN32        ttr;                /* target token rotation time    */
  USIGN8         g;                  /* gap update factor             */
  PB_BOOL        in_ring_desired;    /* active or passive station     */
  USIGN8         hsa;                /* highest station address       */
  USIGN8         max_retry_limit;    /* max. retry limit              */
  USIGN16        reserved;           /* not used                      */
  USIGN8         ident[202];         /* for internal use              */
} T_SET_BUSPARAMETER_REQ;


/****************************************************************************/
/* Read-Busparameter Service (only local)                                   */
/****************************************************************************/

typedef struct _T_READ_BUSPARAMETER_CNF
{
  USIGN8         loc_add;                  /* local station                 */
  USIGN8         loc_segm;                 /* local segment                 */
  USIGN8         baud_rate;                /* baud rate                     */
  USIGN8         medium_red;               /* medium redundancy             */
  USIGN16        tsl;                      /* slot time                     */
  USIGN16        min_tsdr;                 /* min. station delay time resp. */
  USIGN16        max_tsdr;                 /* max. station delay time resp. */
  USIGN8         tqui;                     /* quiet time                    */
  USIGN8         tset;                     /* setup time                    */
  USIGN32        ttr;                      /* target token rotation time    */
  USIGN8         g;                        /* gap update factor             */
  PB_BOOL        in_ring_desired;          /* active or passive station     */
  USIGN8         hsa;                      /* highest station address       */
  USIGN8         max_retry_limit;          /* max. retry limit              */
  USIGN16        reserved;                 /* not used                      */
  USIGN8         ident[202];               /* FDL-Ident-String              */
} T_READ_BUSPARAMETER_CNF;


/****************************************************************************/
/* SET- and READ-VALUE SERVICES                                             */
/****************************************************************************/

/* --- FDL-Variable-Identifiers ------------------------------------------- */
#define ID_TS                      1
#define ID_BAUD_RATE               2
#define ID_MEDIUM_RED              3
#define ID_HW_RELEASE              4
#define ID_SW_RELEASE              5
#define ID_TSL                     6
#define ID_MIN_TSDR                7
#define ID_MAX_TSDR                8
#define ID_TQUI                    9
#define ID_TSET                   10
#define ID_TTR                    11
#define ID_G                      12
#define ID_IN_RING_DESIRED        13
#define ID_HSA                    14
#define ID_MAX_RETRY_LIMIT        15
#define ID_TRR                    16
#define ID_LAS                    17
#define ID_GAPL                   18

/* --- Statistic-Counter-Identifiers -------------------------------------- */
#define ID_FRAME_SENT_COUNT       20
#define ID_RETRY_COUNT            21
#define ID_SD_COUNT               22
#define ID_SD_ERROR_COUNT         23


/****************************************************************************/
/* Set-Value Service  (Local and Remote)                                    */
/****************************************************************************/

#if (PB_VER < 500)
typedef struct _T_STATISTICS_BLOCK
{
  USIGN32      frame_send_count;        /* frame sent counter               */
  USIGN32      sd_count;                /* valid start delimiter counter    */
  USIGN16      retry_count;             /* retry frame sent counter         */
  USIGN16      sd_error_count;          /* invalid start delimiter counter  */
} T_STATISTICS_BLOCK;
#endif

typedef struct _T_SET_VALUE_REQ
{
   USIGN8   id;                                      /* value identifier    */
   USIGN8   length;                                  /* # of values in byte */
/* USIGN8   value[length];                              list of values      */
} T_SET_VALUE_REQ;



/****************************************************************************/
/* Read-Value Service  (Local and Remote)                                   */
/****************************************************************************/
#if (PB_VER < 500)
typedef struct _T_READ_STATISTIC_CTR_CNF
{
  USIGN32      frame_send_count;        /* frame sent counter               */
  USIGN32      sd_count;                /* valid start delimiter counter    */
  USIGN16      retry_count;             /* retry frame sent counter         */
  USIGN16      sd_error_count;          /* invalid start delimiter counter  */
} T_READ_STATISTIC_CTR_CNF;
#endif


typedef struct _T_READ_VALUE_REQ
{
  USIGN8   id;                                        /* value identifier   */
  USIGN8   dummy;                                     /* alignment          */
} T_READ_VALUE_REQ;


typedef struct _T_READ_VALUE_CNF
{
   USIGN8   id;                                      /* value identifier    */
   USIGN8   length;                                  /* # of values in byte */
/* USIGN8   value[length];                              list of values      */
} T_READ_VALUE_CNF;



/****************************************************************************/
/* Ident Service  (Local and Remote)                                        */
/****************************************************************************/

/* --- instance identier ----------------------------------------------------*/
#define ID_FM7                     0
#define ID_FMS                     1
#define ID_LLI                     2
#define ID_FDL                     3
#define ID_STATION                 4

#if (PB_VER < 500)
#define ID_FMA7                    ID_FM7
#define ID_PHY                     5
#endif

typedef struct _T_IDENT_REQ
{
  USIGN8   instance_id;                      /* instance identifier         */
  USIGN8   dummy;                            /* alignment byte              */
} T_IDENT_REQ;



#if (PB_VER >= 500)
typedef struct _T_CHARACTERISTICS
{
  USIGN8     profile_number[2];              /* profile number              */
  USIGN8     functions_supp[3];              /* functions supported         */
  USIGN8     dummy1;                         /* alignment byte              */
  USIGN8     max_pdu_len;                    /* max. PDU length             */
  USIGN8     dummy2;                         /* alignment byte              */
  USIGN8     fms_features_supp[6];           /* FMS features supported      */
  USIGN8     fm7_services_supp[6];           /* FM7 features supported      */
  USIGN8     max_sap_value;                  /* max. LSAP number            */
  USIGN8     max_no_of_saps;                 /* max. number of LSAPs        */
  USIGN16    max_comref;                     /* max communication reference */
  USIGN16    max_crl_len;                    /* max count of CRL-Entries    */
  USIGN32    total_len_of_pdu;               /* total length of PDUs        */
  USIGN16    no_of_parallel_serv;            /* number of parallel serv.    */
  USIGN16    max_od_index;                   /* max. OD-Index               */
  USIGN16    max_od_entries;                 /* max. OD-Entries             */
  USIGN8     max_vfd;                        /* max. VFDs                   */
  USIGN8     max_las_entries;                /* max. no. of LAS entries     */
  USIGN8     min_tsdr;                       /* min. station delay time     */
  USIGN8     trdy;                           /* ready time                  */
  USIGN8     tsdi;                           /* station delay initiatior    */
  USIGN8     max_tsdr;                       /* station delay responder     */
  USIGN8     tset;                           /* setup time                  */
  USIGN8     tqui;                           /* quiet time                  */
  USIGN8     supported_data_types[4];        /* supported data types        */
  USIGN8     supported_access_rights[3];     /* supported access rights     */
  USIGN8     supported_var_types;            /* supported variable types    */
  USIGN8     special_functions[2];           /* special functions           */
  USIGN8     max_od_symbol_length;           /* max length of symbol in OD  */
  USIGN8     max_crl_symbol_length;          /* max length of symbol in CRL */
} T_CHARACTERISTICS;
#else
typedef struct _T_CHARACTERISTICS
{
  USIGN8     profile_number[2];              /* profile number              */
  USIGN8     functions_supp[3];              /* functions supported         */
  USIGN8     dummy1;                         /* alignment byte              */
  USIGN8     max_pdu_len;                    /* max. PDU length             */
  USIGN8     dummy2;                         /* alignment byte              */
  USIGN8     fms_features_supp[6];           /* FMS features supported      */
  USIGN8     fma7_services_supp[6];          /* FM7 features supported      */
  USIGN8     max_sap_value;                  /* max. LSAP number            */
  USIGN8     max_no_of_saps;                 /* max. number of LSAPs        */
  USIGN16    max_comref;                     /* max communication reference */
  USIGN16    max_kbl_len;                    /* max count of CRL-Entries    */
  USIGN32    total_len_of_pdu;               /* total length of PDUs        */
  USIGN16    no_of_parallel_serv;            /* number of parallel serv.    */
  USIGN16    max_ov_index;                   /* max. OD-Index               */
  USIGN16    max_ov_entries;                 /* max. OD-Entries             */
  USIGN8     max_vfd;                        /* max. VFDs                   */
  USIGN8     max_las_entries;                /* max. no. of LAS entries     */
  USIGN8     min_tsdr;                       /* min. station delay time     */
  USIGN8     trdy;                           /* ready time                  */
  USIGN8     tsdi;                           /* station delay initiatior    */
  USIGN8     max_tsdr;                       /* station delay responder     */
  USIGN8     tset;                           /* setup time                  */
  USIGN8     tqui;                           /* quiet time                  */
  USIGN8     supported_data_types[4];        /* supported data types        */
  USIGN8     supported_access_rights[3];     /* supported access rights     */
  USIGN8     supported_var_types;            /* supported variable types    */
  USIGN8     special_functions[2];           /* special functions           */
  USIGN8     max_ov_symbol_length;           /* max length of symbol in OD  */
  USIGN8     max_kbl_symbol_length;          /* max length of symbol in CRL */
} T_CHARACTERISTICS;
#endif


typedef struct _T_IDENT_CNF
{
  USIGN8            instance_id;                               /* instance ident  */
  USIGN8            dummy;                                     /* alignment       */
  STRINGV           vendor_name[MAX_IDENT_STRING_LENGTH];      /* vendor name     */
  STRINGV           controller_type[MAX_IDENT_STRING_LENGTH];  /* controller type */
  STRINGV           hw_release[MAX_IDENT_STRING_LENGTH];       /* HW release      */
  STRINGV           sw_release[MAX_IDENT_STRING_LENGTH];       /* SW release      */
  T_CHARACTERISTICS characteristics;
} T_IDENT_CNF;



/****************************************************************************/
/* LSAP-Status Service  (Local and Remote)                                  */
/****************************************************************************/

typedef struct _T_LSAP_STATUS_REQ
{
  USIGN8    lsap;                             /* desired LSAP               */
  USIGN8    dummy;                            /* alignment byte             */
} T_LSAP_STATUS_REQ;


typedef struct _T_LSAP_STATUS_CNF
{
  USIGN8    access;                           /* station address or all     */
  USIGN8    addr_extension;                   /* segment number             */
  USIGN8    sda;                              /* SDA                        */
  USIGN8    sdn;                              /* SDN                        */
  USIGN8    srd;                              /* SRD                        */
  USIGN8    csrd;                             /* CSRD                       */
} T_LSAP_STATUS_CNF;


/****************************************************************************/
/* Get-Live-List Service  (Local and Remote)                                */
/****************************************************************************/

typedef struct _T_LIVE_LIST
{
  USIGN8     station;                        /* station number              */
  USIGN8     status;                         /* current station of station  */
} T_LIVE_LIST;


typedef struct _T_GET_LIVE_LIST_CNF
{
   USIGN8      dummy;                        /* alignment                   */
   USIGN8      no_of_elements;               /* # of live list elements     */
/* T_LIVE_LIST live_list[no_of_elements];       list of live list elements  */
} T_GET_LIVE_LIST_CNF;


/****************************************************************************/
/* FM7 Fault-Management                                                    */
/****************************************************************************/

/****************************************************************************/
/* FM7-Event-Service (FM2-Event and LLI-Fault-Indications)                  */
/****************************************************************************/
/* NOTE: instance identifier see IDENT service ---------------------------- */
/*       reason-codes and additional details are defined in PB_ERR.H    --- */

typedef struct _T_FM7_EVENT_IND
{
  USIGN16    comm_ref;                         /* communication reference   */
  USIGN8     instance_id;                      /* LLI, FDL, PHY             */
  USIGN8     reason;                           /* reason code               */
  USIGN8     add_detail;                       /* additional detail         */
  USIGN8     dummy;                            /* alignment                 */
} T_FM7_EVENT_IND;

#if (PB_VER < 500)
typedef T_FM7_EVENT_IND  T_FMA7_EVENT_IND;
#endif


#if (PB_VER < 500)
/****************************************************************************/
/* FMA7-Configuration-Management                                            */
/****************************************************************************/

/*****************************************************************************/
/* Set-Configuration Service (only local)                                    */
/*****************************************************************************/

typedef struct T_SET_CONFIGURATION_REQ
{
  USIGN16 max_nr_of_fal_msg_buffers;    /* max # of Layer7-Message-Buffers      (all CR)   */
  USIGN16 max_nr_of_fdl_msg_buffers;    /* max # of Layer2-Message-Buffers      (all CR)   */
  USIGN16 max_nr_of_data_buffers;       /* max # of PDU-Buffers                 (all CR)   */
  USIGN16 max_nr_of_api_data_buffers;   /* max # of abort/poll/idle PDU-Buffers (all CR)   */
  USIGN16 max_nr_of_sap_buffers;        /* max # of SAP-Buffers                 (all CR)   */
  USIGN16 max_nr_of_poll_list_entries;  /* max # of Poll-List-Entries           (all CR)   */
  USIGN16 max_data_buffer_size;         /* max size of FMS-/FMA7-PDU-Buffer                */
} T_SET_CONFIGURATION_REQ;
#endif


#pragma warning (disable : 4103)     /* used #pragma pack to reset alignment */
#ifdef WIN32
#pragma pack(pop)
#else
#pragma pack()
#endif
#pragma warning (default : 4103)


#endif
