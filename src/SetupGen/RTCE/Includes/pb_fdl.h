/*****************************************************************************/
/*                  FDL-USER-INTERFACE DEFINES and TYPES                     */
/*                                                                           */
/*  Filename    : PB_FDL.H                                                   */
/*  Version     : 5.21.0.00.release                                          */
/*  Date        : 27-February-1998                                           */
/*                                                                           */
/*  Description : This file contains the types and defines of the FDL-User-  */
/*                Interface                                                  */
/*                                                                           */
/*****************************************************************************/

#ifndef __PB_FDL__
#define __PB_FDL__

#pragma warning (disable : 4103)     /* used #pragma pack to change alignment */
#ifdef WIN32
#pragma pack(push,2)
#else
#pragma pack(2)
#endif
#pragma warning (default : 4103)


/*****************************************************************************/
/***     FDL service identifier                                            ***/
/*****************************************************************************/
#define     FDLIF_SDA                             0
#define     FDLIF_SDN                             1
#define     FDLIF_SRD                             2
#define     FDLIF_REPLY_UPDATE                    3
#define     FDLIF_REPLY_UPDATE_MULTIPLE           4
#define     FDLIF_SET_BUSPARAMETER                5
#define     FDLIF_READ_BUSPARAMETER               6
#define     FDLIF_SAP_ACTIVATE                    7
#define     FDLIF_RSAP_ACTIVATE                   8
#define     FDLIF_SAP_CHANGE_ACCESS               9
#define     FDLIF_SAP_DEACTIVATE                 10
#define     FDLIF_EVENT                          19
#define     FDLIF_EXIT                           21


/*****************************************************************************/
/***     Status of FDL confirmations, indications (error_code)             ***/
/*****************************************************************************/
#define     FDL_UE             0x01        /* neg. ack., remote user error            */
#define     FDL_RR             0x02        /* neg. ack., resource of remote FDL
                                              entity not available or sufficient      */
#define     FDL_RS             0x03        /* neg. ack., service at remote SAP
                                              or remote SAP not activated             */
#define     FDL_RA             0x04        /* neg. ack., access of remote SAP blocked */
#define     FDL_DL             0x08        /* pos. ack. for sent data, reply data
                                              with low priority available             */
#define     FDL_NR             0x09        /* pos. ack. for sent data, no reply data  */
#define     FDL_DH             0x0a        /* pos. ack. for sent data, reply data
                                              with high priority available            */
#define     FDL_RDL            0x0c        /* neg. ack. for sent data, reply data
                                              with low priority available             */
#define     FDL_RDH            0x0d        /* neg. ack. for sent data, reply data
                                              with high priority available            */
#define     FDL_LS             0x10        /* service at local SAP or local SAP not
                                              activated                               */
#define     FDL_NA             0x11        /* no reaction from remote station         */
#define     FDL_DS             0x12        /* local FDL entity disconnected           */
#define     FDL_NO             0x13        /* not ok                                  */
#define     FDL_LR             0x14        /* resource of local FDL not available     */
#define     FDL_IV             0x15        /* invalid parameter in request            */
#define     FDL_LOW_DATA       0x20        /* low priority reply data transmitted     */
#define     FDL_HIGH_DATA      0x21        /* high priority reply data transmitted    */
#define     FDL_NO_DATA        0x22        /* no reply data transmitted               */


/*****************************************************************************/
/***     SAP and address constants                                         ***/
/*****************************************************************************/
#define     BROADCAST                   127         /* broadcast address     */
#define     FDL_DEFAULT_SAP              64         /* number of Default SAP */


/*****************************************************************************/
/***     Constants for specifying baudrate                                 ***/
/*****************************************************************************/
#define     KBAUD_9_6                   0x00
#define     KBAUD_19_2                  0x01
#define     KBAUD_45_45                 0x0B
#define     KBAUD_93_75                 0x02
#define     KBAUD_187_5                 0x03
#define     KBAUD_500                   0x04
#define     KBAUD_750                   0x05
#define     MBAUD_1_5                   0x06
#define     MBAUD_3                     0x07
#define     MBAUD_6                     0x08
#define     MBAUD_12                    0x09

/*****************************************************************************/
/***     Constants for specifying redundancy                               ***/
/*****************************************************************************/
#define     NO_REDUNDANCY               0x00


/*****************************************************************************/
/***     Data Mode for SRD and SDA indications                             ***/
/*****************************************************************************/
#define     NORMAL_MODE                 0x00   /* all faultless telegrams are indicated */
#define     DATA_MODE                   0x08   /* indication only if data transmitted   */


/*****************************************************************************/
/***     Constants for access in SAP block                                 ***/
/*****************************************************************************/
#define     ALL                         0xFF
#define     SEGMENT_VALID               0x80
#define     SEGMENT_INVALID             0x00
#define     SEGMENT_TYP                 0x40

#define     INITIATOR                   0x00
#define     RESPONDER                   0x10
#define     BOTH_ROLES                  0x20
#define     SERVICE_NOT_ACTIVATED       0x30


/* ************************************************************************** */
/* **************          Busparameter block           ********************* */
/* ************************************************************************** */

typedef struct _T_FDLIF_SET_BUSPARAMETER_REQ
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
} T_FDLIF_SET_BUSPARAMETER_REQ;


typedef struct _T_FDLIF_READ_BUSPARAMETER_CNF
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
} T_FDLIF_READ_BUSPARAMETER_CNF;

/* ************************************************************************* */
/* *******************          SAP block          ************************* */
/* ************************************************************************* */

typedef struct _T_FDLIF_SAP_ACTIVATE_REQ
{
    USIGN8          sap_nr;                     /* SAP to be activated                */
    USIGN8          max_l_sdu_length_req;       /* maximum length of request telegram */
    USIGN8          max_l_sdu_length_con_ind;   /* maximum length of con/ind telegram */
    USIGN8          access_sap;                 /* permitted request SAPs             */
    USIGN8          access_station;             /* permitted requestor                */
    USIGN8          sda;                        /* roles in SDA service               */
    USIGN8          sdn;                        /* roles in SDN service               */
    USIGN8          srd;                        /* roles in SRD service               */
    USIGN8          csrd;                       /* not supported                      */
    USIGN8          data_mode;                  /* NORMAL_MODE, DATA_MODE             */
    USIGN8          credits;                    /* number of indication resources     */
    USIGN8          dummy;                      /* alignment byte                     */
} T_FDLIF_SAP_ACTIVATE_REQ;

typedef struct _T_FDLIF_RSAP_ACTIVATE_REQ
{
  USIGN8          sap_nr;                     /* SAP to be activated            */
  USIGN8          max_l_sdu_length_req;       /* maximum length of req telegram */
  USIGN8          max_l_sdu_length_ind;       /* maximum length of ind telegram */
  USIGN8          access_sap;                 /* permitted request SAPs         */
  USIGN8          access_station;             /* permitted requestor            */
  USIGN8          data_mode;                  /* NORMAL_MODE, DATA_MODE         */
  USIGN8          credits;                    /* number of indication resources */
  USIGN8          dummy;                      /* alignmnet byte                 */
} T_FDLIF_RSAP_ACTIVATE_REQ;


typedef struct _T_FDLIF_SAP_CHANGE_REQ
{
    USIGN8          sap_nr;                     /* SAP to be activated    */
    USIGN8          access_sap;                 /* permitted request SAPs */
    USIGN8          access_station;             /* permitted requestor    */
    USIGN8          dummy;                      /* alignment byte         */
} T_FDLIF_SAP_CHANGE_REQ;


typedef struct _T_FDLIF_SAP_DEACTIVATE_REQ
{
    USIGN8          sap_nr;                     /* SAP to be activated */
    USIGN8          dummy;                      /* alignment byte      */
} T_FDLIF_SAP_DEACTIVATE_REQ;


/* ************************************************************************* */
/* *************          Data transfer                ********************* */
/* ************************************************************************* */

typedef struct _T_FDLIF_SDN_SDA_SRD_REQ
{
    USIGN8          ssap;                       /* source SAP                */
    USIGN8          dsap;                       /* destination SAP           */
    USIGN8          rem_add;                    /* address of remote station */
    USIGN8          priority;                   /* priority of request       */
    USIGN8          status;                     /* only used for SRD.IND     */
    USIGN8          length;                     /* length of request data    */
/*  USIGN8          req_data [length]              request data              */
} T_FDLIF_SDN_SDA_SRD_REQ;

typedef struct _T_FDLIF_SRD_CNF
{
    USIGN8          status;                     /* status                    */
    USIGN8          length;                     /* length of request data    */
/*  USIGN8          cnf_data [length];             request data              */
} T_FDLIF_SRD_CNF;


typedef struct _T_FDLIF_RUP_REQ
{
    USIGN8          sap_nr;                     /* number of local SAP       */
    USIGN8          priority;                   /* priority of request       */
    USIGN8          dummy;                      /* alignment byte            */
    USIGN8          length;                     /* length of request data    */
/*  USIGN8          req_data [length];          /* request data              */
} T_FDLIF_RUP_REQ;


/* ************************************************************************* */
/* *************                 Event                 ********************* */
/* ************************************************************************* */
/* the possible events are defined in the header file PB_ERR.H              */

typedef struct _T_FDLIF_EVENT_IND
{
    USIGN8          event;                      /* event                     */
    USIGN8          dummy;                      /* alignment byte            */
} T_FDLIF_EVENT_IND;


#pragma warning (disable : 4103)     /* used #pragma pack to reset alignment */
#ifdef WIN32
#pragma pack(pop)
#else
#pragma pack()
#endif
#pragma warning (default : 4103)


#endif  /* __PB_FDL__ */
