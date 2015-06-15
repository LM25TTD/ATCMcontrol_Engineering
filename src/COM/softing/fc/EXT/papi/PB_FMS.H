/*****************************************************************************/
/*                  FMS-USER-INTERFACE DEFINES and TYPES                     */
/*                                                                           */
/*  Filename    : PB_FMS.H                                                   */
/*  Version     : 5.21.0.00.release                                          */
/*  Date        : 27-February-1998                                           */
/*                                                                           */
/*  Description : This file contains the types and defines of the FMS-User-  */
/*                Interface                                                  */
/*                                                                           */
/*****************************************************************************/

#ifndef __PB_FMS__
#define __PB_FMS__


#pragma warning (disable : 4103)     /* used #pragma pack to change alignment */
#ifdef WIN32
#pragma pack(push,2)
#else
#pragma pack(2)
#endif
#pragma warning (default : 4103)



/*****************************************************************************/
/*                                                                           */
/*                             D E F I N E S                                 */
/*                                                                           */
/*****************************************************************************/


/*****************************************************************************/
/*************   FMS STRING LENGTH CONSTANTS             *********************/
/*****************************************************************************/

#define MAX_VFD_STRING_LENGTH           _NAME_LENGTH(VFD_STRING_LENGTH)

#define MAX_ACCESS_NAME_LENGTH          _NAME_LENGTH(ACCESS_NAME_LENGTH)
#define MAX_OBJECT_NAME_LENGTH          _NAME_LENGTH(OBJECT_NAME_LENGTH)
#define MAX_EXTENSION_LENGTH            _NAME_LENGTH(EXTENSION_LENGTH)
#define MAX_EXECUTION_ARGUMENT_LENGTH   _NAME_LENGTH(EXECUTION_ARGUMENT_LENGTH)


/*****************************************************************************/
/*************   FMS SERVICE IDENTIFIERS                 *********************/
/*****************************************************************************/

/* --- remote FMS services ------------------------------------------------- */
#define FMS_INITIATE                   0

#define FMS_STATUS                     2
#define FMS_IDENTIFY                   3
#define FMS_READ                       4
#define FMS_WRITE                      5
#define FMS_GET_OD                     6
#define FMS_READ_WITH_TYPE             7
#define FMS_WRITE_WITH_TYPE            8
#define FMS_DEF_VAR_LIST               9
#define FMS_DEL_VAR_LIST              10
#define FMS_INIT_DOWNL_SEQ            11
#define FMS_DOWNL_SEG                 12
#define FMS_TERM_DOWNL_SEQ            13
#define FMS_INIT_UPL_SEQ              14
#define FMS_UPL_SEG                   15
#define FMS_TERM_UPL_SEQ              16
#define FMS_REQ_DOM_DOWNL             17
#define FMS_REQ_DOM_UPL               18
#define FMS_PI_CREATE                 19
#define FMS_PI_DELETE                 20
#define FMS_PI_START                  21
#define FMS_PI_STOP                   22
#define FMS_PI_RESUME                 23
#define FMS_PI_RESET                  24
#define FMS_PI_KILL                   25
#define FMS_ALT_EVN_CND_MNT           26
#define FMS_ACK_EVN_NOTIFY            27
#define FMS_PHYS_READ                 28
#define FMS_PHYS_WRITE                29
#define FMS_INIT_PUT_OD               30
#define FMS_PUT_OD                    31
#define FMS_TERM_PUT_OD               32
#define FMS_GEN_INIT_DOWNL_SEQ        61
#define FMS_GEN_DOWNL_SEG             62
#define FMS_GEN_TERM_DOWNL_SEQ        63

#define FMS_INFO_RPT                  33
#define FMS_UNSOLICITEDSTATUS         34
#define FMS_EVN_NOTIFY                35
#define FMS_INFO_RPT_WITH_TYPE        36
#define FMS_EVN_NOTIFY_WITH_TYPE      37

#define FMS_ABORT                     38
#define FMS_REJECT                    39

/* --- FMS features -------------------------------------------------------- */
#define FMS_GET_OD_LONG               40
#define FMS_NAME_ADDRESSING           41

/* --- local FMS services -------------------------------------------------- */
#define FMS_OD_READ_LOC               42
#define FMS_INIT_LOAD_OD_LOC          43
#define FMS_LOAD_OD_LOC               44
#define FMS_TERM_LOAD_OD_LOC          45
#define FMS_CREATE_VFD_LOC            46
#define FMS_VFD_SET_PHYS_STATUS_LOC   47
#define FMS_PI_SET_STATE_LOC          48
#define FMS_VAR_DATA_EVENT_LOC        49

#if (PB_VER < 500)
#define INITIATE                       0

#define STATUS                         2
#define IDENTIFY                       3
#define READ                           4
#define WRITE                          5
#define GETOV                          6
#define READWITHTYPE                   7
#define WRITEWITHTYPE                  8
#define DEFINEVARIABLELIST             9
#define DELETEVARIABLELIST            10
#define INITIATEDOWNLOADSEQUENCE      11
#define DOWNLOADSEGMENT               12
#define TERMINATEDOWNLOADSEQUENCE     13
#define INITIATEUPLOADSEQUENCE        14
#define UPLOADSEGMENT                 15
#define TERMINATEUPLOADSEQUENCE       16
#define REQUESTDOMAINDOWNLOAD         17
#define REQUESTDOMAINUPLOAD           18
#define CREATEPROGRAMINVOCATION       19
#define DELETEPROGRAMINVOCATION       20
#define START                         21
#define STOP                          22
#define RESUME                        23
#define RESET                         24
#define KILL                          25
#define ALTEREVENTCONDITIONMONITORING 26
#define ACKNOWLEDGEEVENTNOTIFICATION  27
#define PHYS_READ                     28
#define PHYS_WRITE                    29
#define INITIATE_PUT_OV               30
#define PUT_OV                        31
#define TERMINATE_PUT_OV              32

#define INFORMATIONREPORT             33
#define UNSOLICITEDSTATUS             34
#define EVENTNOTIFICATION             35
#define INFORMATIONREPORTWITHTYPE     36
#define EVENTNOTIFICATIONWITHTYPE     37

#define ABORT                         38
#define REJECT                        39

/* --- FMS features -------------------------------------------------------- */
#define GET_OV_LONG                   40
#define NAME_ADDRESSING               41

/* --- local FMS services -------------------------------------------------- */
#define OV_READ_LOC                   42
#define INITIATE_LOAD_OV_LOC          43
#define LOAD_OV_LOC                   44
#define TERMINATE_LOAD_OV_LOC         45
#define CREATE_VFD_LOC                46
#define VFD_SET_PHYS_STATUS_LOC       47
#define PI_SET_STATE_LOC              48
#endif


/*****************************************************************************/
/*************   ACCESS SPECIFICATION                    *********************/
/*****************************************************************************/

/* --- codes for object access mode, to be used as tag in T_ACC_SPEC-------- */
/* --- fixed size ---------------------------------------------------------- */
#define ACCESS_INDEX                   0    /* access by index               */
#define ACCESS_NAME                    1    /* acess by name                 */
#define ACCESS_NAME_LIST               2    /* acess by name list            */

/* --- codes for object access mode, to be used as tag in T_DYN_ACC_SPEC --- */
/* --- dynamic size -------------------------------------------------------- */
#define DYN_ACCESS_INDEX               3    /* access by index               */
#define DYN_ACCESS_NAME                4    /* acess by name                 */

/* --- codes for named access specification, to be used for od services only */
/* --- fixed size ---------------------------------------------------------- */
#define  INDEX_ACCESS                  1    /* access by index               */
#define  VAR_NAME_ACCESS               2    /* access by variable name       */
#define  VAR_LIST_NAME_ACCESS          3    /* access by variable list name  */
#define  DOMAIN_NAME_ACCESS            4    /* access by domain name         */
#define  PI_NAME_ACCESS                5    /* access by pi name             */
#define  EVENT_NAME_ACCESS             6    /* access by event name          */
#define  START_INDEX_ACCESS            7    /* access by start index         */


/*****************************************************************************/
/*************   FMS CONTEXT MANAGEMENT                  *********************/
/*****************************************************************************/

#define DETAIL_LENGTH                 16      /* length of abort detail      */
#define FEAT_SUPP_LEN                  6      /* length of supp. feat. field */

/*****************************************************************************/
/*************   VFD SUPPORT MANAGEMENT                  *********************/
/*****************************************************************************/

/* --- logical status of the communcation ---------------------------------- */
#define STATE_CHANGES_ALLOWED          0
#define LIMITED_SERVICES_PERMITTED     2

/* --- physical status of the application device --------------------------- */
#define OPERATIONAL                    0
#define PARTIALLY_OPERATIONAL          1
#define INOPERABLE                     2
#define NEEDS_COMMISSIONING            3


/*****************************************************************************/
/*************   OD-MANAGEMENT                           *********************/
/*****************************************************************************/

/* --- OD-states ----------------------------------------------------------- */
#define OD_LOADABLE                    2
#define OD_READY                       3
#define OD_LOADING_NON_INTERACTING     4
#define OD_LOADING_INTERACTING         5
#define OD_NOT_EXISTENT                6

#if (PB_VER < 500)
#define OV_LOADABLE                    OD_LOADABLE
#define OV_READY                       OD_READY
#define OV_LOADING_NON_INTERACTING     OD_LOADING_NON_INTERACTING
#define OV_LOADING_INTERACTING         OD_LOADING_INTERACTING
#define OV_NOT_EXISTENT                OD_NOT_EXISTENT
#endif

/* --- indices in OD type description for standard data types -------------- */
#define OD_BOOL                        1
#define OD_INT8                        2
#define OD_INT16                       3
#define OD_INT32                       4
#define OD_USIGN8                      5
#define OD_USIGN16                     6
#define OD_USIGN32                     7
#define OD_FLOAT                       8
#define OD_VSTRING                     9
#define OD_OSTRING                    10
#define OD_DATE_TYPE                  11
#define OD_TIME_OF_DAY                12
#define OD_TIME_DIFF                  13
#define OD_BSTRING                    14


#if defined (DOS16) || defined (WIN16)
#define BOOLEAN                       OD_BOOL
#define INTEGER8                      OD_INT8
#define INTEGER16                     OD_INT16
#define INTEGER32                     OD_INT32
#define UNSIGNED8                     OD_USIGN8
#define UNSIGNED16                    OD_USIGN16
#define UNSIGNED32                    OD_USIGN32
#define FLOATING_POINT                OD_FLOAT
#define VISIBLE_STRING                OD_VSTRING
#define OCTET_STRING                  OD_OSTRING
#define DATE_TYPE                     OD_DATE_TYPE
#define TIME_OF_DAY                   OD_TIME_OF_DAY
#define TIME_DIFFERENCE               OD_TIME_DIFF
#define BIT_STRING                    OD_BSTRING
#endif


/* --- codes of FMS objects ------------------------------------------------ */
#define  NULL_OBJECT                   0    /* null object                   */
#define  OD_OBJECT                     1    /* OD object                     */
#define  OV_OBJECT                     1    /* OD object                     */
#define  DOMAIN_OBJECT                 2    /* domain object                 */
#define  INVOCATION_OBJECT             3    /* program invocation object     */
#define  EVENT_OBJECT                  4    /* event object                  */
#define  TYPE_OBJECT                   5    /* basic data type description   */
#define  TYPE_STRUCT_OBJECT            6    /* structured data type descript.*/
#define  SIMPLE_VAR_OBJECT             7    /* simple variable object        */
#define  ARRAY_OBJECT                  8    /* array object                  */
#define  RECORD_OBJECT                 9    /* record object                 */
#define  VAR_LIST_OBJECT              10    /* variable list object          */
#define  VAR_OBJECT                   11    /* class of all variable objects */
#define  ALL_OBJECT                   12    /* super class of all objects    */


/* --- OD loading selection -------------------------------------------------*/
#define CONSEQUENCE_0                  0
#define CONSEQUENCE_1                  1
#define CONSEQUENCE_2                  2

/*****************************************************************************/
/*************   VARIABLE ACCESS                         *********************/
/*****************************************************************************/

/* --- tag values for type description (T_TYPE_DESCR)----------------------- */
#define SIMPLE_TYPE                    1
#define ARRAY_TYPE                     2
#define RECORD_TYPE                    3


/*****************************************************************************/
/*************   DOMAIN-MANAGEMENT                       *********************/
/*****************************************************************************/

/* --- domain states ------------------------------------------------------- */
#define  DOM_EXISTENT               0x01
#define  DOM_LOADING                0x02
#define  DOM_INCOMPLETE             0x03
#define  DOM_COMPLETE               0x04
#define  DOM_READY                  0x05
#define  DOM_IN_USE                 0x06

#if defined (DOS16) || defined (WIN16)
#define  EXISTENT                   DOM_EXISTENT
#define  LOADING                    DOM_LOADING
#define  INCOMPLETE                 DOM_INCOMPLETE
#define  COMPLETE                   DOM_COMPLETE
#define  READY                      DOM_READY
#define  IN_USE                     DOM_IN_USE
#endif

/* --- upload states ------------------------------------------------------- */
#define  DOM_NON_EXISTENT           0x00
#define  DOM_UPLOADING              0x01
#define  DOM_UPLOADED               0x02

#if defined (DOS16) || defined (WIN16)
#define  NON_EXISTENT               0x00
#define  UPLOADING                  DOM_UPLOADING
#define  UPLOADED                   DOM_UPLOADED
#endif


/*****************************************************************************/
/*************   PROGRAM INVOCATION MANAGEMENT           *********************/
/*****************************************************************************/


/* --- program invocation states ------------------------------------------- */
#define   PI_NON_EXISTENT           0x00
#define   PI_UNRUNNABLE             0x01
#define   PI_IDLE                   0x02
#define   PI_RUNNING                0x03
#define   PI_STOPPED                0x04
#define   PI_STARTING               0x05
#define   PI_STOPPING               0x06
#define   PI_RESUMING               0x07
#define   PI_RESETTING              0x08

#if defined (DOS16) || defined (WIN16)
#define   NON_EXISTENT              0x00
#define   UNRUNNABLE                PI_UNRUNNABLE
#define   IDLE                      PI_IDLE
#define   RUNNING                   PI_RUNNING
#define   STOPPED                   PI_STOPPED
#define   STARTING                  PI_STARTING
#define   STOPPING                  PI_STOPPING
#define   RESUMING                  PI_RESUMING
#define   RESETTING                 PI_RESETTING
#endif



/*****************************************************************************/
/*                                                                           */
/*                       D A T A   S T R U C T U R E S                       */
/*                                                                           */
/*****************************************************************************/

/*****************************************************************************/
/*************   ACCESS CONTROL                          *********************/
/*****************************************************************************/

typedef struct _T_ACCESS
{
  USIGN8     pass_word;                 /* password                          */
  USIGN8     acc_groups;                /* access groups                     */
  USIGN16    acc_right;                 /* access rights                     */
} T_ACCESS;


/*****************************************************************************/
/*************   ACCESS SPECIFICATION                    *********************/
/*****************************************************************************/

/* --- standard access specification data structure (fixed size) ----------- */
typedef struct _T_ACC_SPEC
{
  USIGN8     tag;                       /* id of the access specification    */
  USIGN8     dummy;                     /* alignment byte                    */
  union
  {
    USIGN16  index;                          /* access by index              */
    STRINGV  name[MAX_ACCESS_NAME_LENGTH];   /* access by symbolic name      */
  } id;
} T_ACC_SPEC;


/* --- dynamic access specification data structure (used in T_PI_CR8_REQ
       and in T_VAR_DEFINE_VAR_LIST_REQ data structure (dynamic size) ----- */
typedef struct _T_DYN_ACC_SPEC
{
   USIGN8     tag;                    /* id of the access specification      */
   USIGN8     length;                 /* length of access specification      */
/* USIGN8     acc_spec[length]           access specification (index / name) */
} T_DYN_ACC_SPEC;


/*****************************************************************************/
/*************   FMS CONTEXT MANAGEMENT                  *********************/
/*****************************************************************************/

/* --- Initiate-Service -----------------------------------------------------*/
typedef struct _T_CTXT_INIT_REQ
{
  USIGN8    profile_number[2];          /* profile number                    */
  PB_BOOL   protection;                 /* access protection                 */
  USIGN8    password;                   /* password                          */
  USIGN8    access_groups;              /* access groups                     */
  USIGN8    dummy;                      /* alignment byte                    */
  INT16     od_version;                 /* od version                        */
  USIGN8    snd_len_h;                  /* max pdu size to send (high prio)  */
  USIGN8    snd_len_l;                  /* max pdu size to send (low prio)   */
  USIGN8    rcv_len_h;                  /* max pdu size to receive (high)    */
  USIGN8    rcv_len_l;                  /* max pdu size to receive (low)     */
  USIGN8    supported_features[FEAT_SUPP_LEN];   /* supported features       */
} T_CTXT_INIT_REQ;


typedef struct _T_CTXT_INIT_CNF
{
  USIGN8    profile_number[2];          /* profile number                    */
  INT16     od_version;                 /* od version                        */
  PB_BOOL   protection;                 /* access protection                 */
  USIGN8    password;                   /* password                          */
  USIGN8    access_groups;              /* access groups                     */
  USIGN8    dummy;                      /* alignment byte                    */
} T_CTXT_INIT_CNF;


typedef struct _T_CTXT_INIT_ERR_CNF
{
  USIGN16 class_code;                   /*  error class, error code          */
  USIGN8  snd_len_h;                    /*  max pdu size to send (high prio) */
  USIGN8  snd_len_l;                    /*  max pdu size to send (low prio)  */
  USIGN8  rcv_len_h;                    /*  max pdu size to receive (high)   */
  USIGN8  rcv_len_l;                    /*  max pdu size to receive (low)    */
  USIGN8  supported_features[FEAT_SUPP_LEN];   /*  supported features        */
} T_CTXT_INIT_ERR_CNF;


/*--- abort service ---------------------------------------------------------*/
typedef struct _T_CTXT_ABORT_REQ
{
  PB_BOOL  local;                       /* local or remote detected          */
  USIGN8   abort_id;                    /* abort identifier USR, FMS, ...    */
  USIGN8   reason;                      /* abort reason code                 */
  USIGN8   detail_length;               /* length of abort detail            */
  USIGN8   detail[DETAIL_LENGTH];       /* detail information                */
} T_CTXT_ABORT_REQ;


/*--- reject service --------------------------------------------------------*/
typedef struct _T_CTXT_REJECT_IND
{
  PB_BOOL   detected_here;              /* local or remote detected          */
  USIGN8    orig_invoke_id;             /* original invoke ID                */
  USIGN8    pdu_type;                   /* reject PDU types                  */
  USIGN8    reject_code;                /* reject code                       */
} T_CTXT_REJECT_IND;



/*****************************************************************************/
/*************   VARIABLE ACCESS MANAGEMENT              *********************/
/*****************************************************************************/

typedef struct _T_SIMPLE_TYPE
{
   USIGN16    data_type_index;          /* index of data type                */
   USIGN8     length;                   /* size of data type                 */
   USIGN8     dummy;                    /* alignment byte                    */
}  T_SIMPLE_TYPE;


typedef struct _T_ARRAY_TYPE
{
   USIGN16    data_type_index;          /* index of data type                */
   USIGN8     length;                   /* size of data type                 */
   USIGN8     no_of_elements;           /* number of data types              */
}  T_ARRAY_TYPE;


typedef struct _T_RECORD_TYPE
{
   USIGN8        no_of_elements;                  /* number of record elem.  */
   USIGN8        dummy;                           /* alignment byte          */
   T_SIMPLE_TYPE simple[MAX_VAR_RECORD_ELEMENTS]; /* list of simple types    */
}  T_RECORD_TYPE;


typedef struct _T_TYPE_DESCR
{
   USIGN8     tag;                      /* type description identifier       */
   USIGN8     dummy;                    /* alignment byte                    */
   union
   {
     T_SIMPLE_TYPE  simple;             /* simple type                       */
     T_ARRAY_TYPE   array;              /* array type                        */
     T_RECORD_TYPE  record;             /* record type                       */
   } id;
}  T_TYPE_DESCR;



/*--- VARIABLE-OBJECT-DESCRIPTIONS ------------------------------------------------*/

/*--- Simple-Variable-Object-Description ------------------------------------------*/
typedef struct _T_SIMPLE_VAR_OBJECT
{
   USIGN16    index;                             /* logical address of the object  */
   USIGN8     obj_code;                          /* object code                    */
   USIGN8     length;                            /* length of object in octets     */
   USIGN16    index_of_type;                     /* logical address of the type    */
   T_ACCESS   access;                            /* access right structure         */
   USIGN32    local_address;                     /* local address                  */
   STRINGV    name[MAX_OBJECT_NAME_LENGTH];      /* name                           */
   USIGN8     extension[MAX_EXTENSION_LENGTH];   /* extension                      */
}  T_SIMPLE_VAR_OBJECT;


/*--- Array-Variable-Object-Description -------------------------------------------*/
typedef struct _T_ARRAY_OBJECT
{
   USIGN16    index;                             /* logical address of the object  */
   USIGN8     obj_code;                          /* object code                    */
   USIGN8     length;                            /* length of an element in octets */
   USIGN16    index_of_type;                     /* logical address of the type    */
   USIGN8     nof_elements;                      /* number of array elements       */
   USIGN8     dummy;                             /* alignment byte                 */
   T_ACCESS   access;                            /* access right structure         */
   USIGN32    local_address;                     /* local address                  */
   STRINGV    name[MAX_OBJECT_NAME_LENGTH];      /* name                           */
   USIGN8     extension[MAX_EXTENSION_LENGTH];   /* extension                      */
}  T_ARRAY_OBJECT;

/*--- Record-Variable-Object-Description ------------------------------------------*/
typedef struct _T_RECORD_OBJECT
{
   USIGN16     index;                            /* index                          */
   USIGN8      obj_code;                         /* object code                    */
   USIGN8      no_of_address;                    /* number of local address        */
   USIGN16     index_of_type;                    /* logical address of the type    */
   T_ACCESS    access;                           /* access right structure         */
   STRINGV     name[MAX_OBJECT_NAME_LENGTH];     /* name                           */
   USIGN8      extension[MAX_EXTENSION_LENGTH];  /* extension                      */
   USIGN32     reserved;                         /* for internal use               */
/* USIGN32     local_address_list[no_of_address];   local address list             */
} T_RECORD_OBJECT;


/*--- Variable-List-Object-Description --------------------------------------------*/
typedef struct _T_VAR_LIST_OBJECT
{
   USIGN16     index;                             /* logical address of the object */
   USIGN8      obj_code;                          /* object code                   */
   USIGN8      no_of_var;                         /* number of variables           */
   T_ACCESS    access;                            /* access right                  */
   PB_BOOL     deletable;                         /* TRUE - deletable; else FALSE  */
   USIGN8      dummy;                             /* alignment-byte                */
   STRINGV     name[MAX_OBJECT_NAME_LENGTH];      /* name                          */
   USIGN8      extension[MAX_EXTENSION_LENGTH];   /* extension                     */
   USIGN32     reserved;                          /* for internal use              */
/* USIGN16     var_list[no_of_var];                  list of variables             */
} T_VAR_LIST_OBJECT;



/* --- Read-Service ---------------------------------------------------------------*/
typedef struct _T_VAR_READ_REQ
{
   T_ACC_SPEC acc_spec;                        /* access specification             */
   USIGN8     subindex;                        /* subindex                         */
   USIGN8     dummy;                           /* alignment byte                   */
} T_VAR_READ_REQ;


typedef struct _T_VAR_READ_CNF
{
   USIGN8  dummy;                              /* alignment byte                   */
   USIGN8  length;                             /* length of values in bytes        */
/* USIGN8  value[lenght];                         list of data                     */
} T_VAR_READ_CNF;



/*--- Read-With-Type-Service ------------------------------------------------------*/
typedef struct _T_VAR_READ_WITH_TYPE_REQ
{
   T_ACC_SPEC acc_spec;                        /* access specification             */
   USIGN8     subindex;                        /* subindex                         */
   USIGN8     dummy;                           /* alignment byte                   */
} T_VAR_READ_WITH_TYPE_REQ;



typedef struct _T_VAR_READ_WITH_TYPE_CNF
{
   USIGN8       no_of_type_descr;                     /* number of typedescription */
   USIGN8       length;                               /* # of values in bytes      */
/* T_TYPE_DESCR type_descr_list[no_of_type_descr];       list of type description  */
/* USIGN8       value[length];                           list of data              */
} T_VAR_READ_WITH_TYPE_CNF;



/*--- Write-Service ---------------------------------------------------------------*/
typedef struct _T_VAR_WRITE_REQ
{
   T_ACC_SPEC acc_spec;                             /* access specification        */
   USIGN8     subindex;                             /* subindex                    */
   USIGN8     length;                               /* # number of values in bytes */
/* USIGN8     value[length];                           list of values              */
} T_VAR_WRITE_REQ;



/*--- Write-With-Type-Service -----------------------------------------------------*/
typedef struct _T_VAR_WRITE_WITH_TYPE_REQ
{
   T_ACC_SPEC   acc_spec;                           /* access specification        */
   USIGN8       subindex;                           /* subindex                    */
   USIGN8       dummy;                              /* alignment byte              */
   USIGN8       no_of_type_descr;                   /* number of type descriptions */
   USIGN8       length;                             /* # of values in bytes        */
/* T_TYPE_DESCR type_descr_list[no_of_type_descr];     list of type descriptions   */
/* USIGN8       value[length];                         list of datas               */
} T_VAR_WRITE_WITH_TYPE_REQ;



/*--- Information-Report-Service --------------------------------------------------*/
typedef struct _T_VAR_INFO_RPT_REQ
{
   USIGN8     priority;                               /* priority                  */
   USIGN8     subindex;                               /* subindex                  */
   T_ACC_SPEC acc_spec;                               /* access specification      */
   USIGN8     dummy;                                  /* alignment-byte            */
   USIGN8     length;                                 /* # of values in bytes      */
/* USIGN8     value[length];                             list of data              */
} T_VAR_INFO_RPT_REQ;


/*--- Information-Report-With-Type-Service ----------------------------------------*/
typedef struct _T_VAR_INFO_RPT_WITH_TYPE_REQ
{
   USIGN8       priority;                             /* priority                  */
   USIGN8       subindex;                             /* subindex                  */
   T_ACC_SPEC   acc_spec;                             /* access specification      */
   USIGN8       no_of_type_descr;                     /* number of typedescription */
   USIGN8       length;                               /* # of values in bytes      */
/* T_TYPE_DESCR type_descr_list[no_of_type_descr];       list of type description  */
/* USIGN8       value[length];                           list of data              */
} T_VAR_INFO_RPT_WITH_TYPE_REQ;


/*--- Define-Variable-List-Service ------------------------------------------------*/
typedef struct _T_VAR_DEFINE_VAR_LIST_REQ
{
   T_ACCESS       access;                              /* access rights             */
   STRINGV        name[MAX_OBJECT_NAME_LENGTH];        /* variable list name        */
   USIGN8         extension[MAX_EXTENSION_LENGTH];     /* extension                 */
   USIGN16        index;                               /* index of variable list    */
   USIGN8         dummy;                               /* alignment byte            */
   USIGN8         no_of_var;                           /* number of variables       */
#if (PB_VER >= 500)
/* T_DYN_ACC_SPEC var_list[no_of_var];                    list of variables         */
#else
/* T_ACC_SPEC     var_list[no_of_var];                    list of variables         */
#endif
} T_VAR_DEFINE_VAR_LIST_REQ;

typedef struct _T_VAR_DEFINE_VAR_LIST_CNF
{
   USIGN16     index;                                 /* index of variable list    */
} T_VAR_DEFINE_VAR_LIST_CNF;


/*--- Delete-Variable-List-Service ------------------------------------------------*/
typedef struct _T_VAR_DELETE_VAR_LIST_REQ
{
   T_ACC_SPEC  acc_spec;                              /* access specification      */
} T_VAR_DELETE_VAR_LIST_REQ;


/*--- Physical-Read-Service -------------------------------------------------------*/
typedef struct _T_VAR_PHYS_READ_REQ
{
   USIGN32       int_addr;                       /* physical address to be read    */
   USIGN8        length;                         /* length in octets               */
   USIGN8        dummy;                          /* alignment byte                 */
} T_VAR_PHYS_READ_REQ;


typedef struct _T_VAR_PHYS_READ_CNF
{
    USIGN8   dummy;                              /* alignment byte                 */
    USIGN8   length;                             /* length of values in bytes      */
/*  USIGN8   data[length];                          list of data                   */
} T_VAR_PHYS_READ_CNF;


/*--- Physical-Write-Service ------------------------------------------------------*/
typedef struct _T_VAR_PHYS_WRITE_REQ
{
   USIGN32  int_addr;                            /* physical address to be write   */
   USIGN8   dummy;                               /* length in octets               */
   USIGN8   length;                              /* length in octets               */
/* USIGN8   data[length];                           list of datas                  */
} T_VAR_PHYS_WRITE_REQ;


/*--- Data-Event service ----------------------------------------------------------*/
typedef struct _T_VAR_DATA_EVENT_IND
{
   USIGN16 index;                              /* index                            */
   USIGN8  dummy;                              /* alignment byte                   */
   USIGN8  length;                             /* length of values in bytes        */
/* USIGN8  value[lenght];                         list of data                     */
} T_VAR_DATA_EVENT_IND;



/*****************************************************************************/
/*************   EVENT-MANAGEMENT                        *********************/
/*****************************************************************************/


/*--- Event-Object-Description ----------------------------------------------*/
typedef struct _T_EVENT_OBJECT
{
  USIGN16     index_event;                        /* index                   */
  USIGN8      obj_code;                           /* object code             */
  USIGN8      data_length;                        /* size of event data      */
  USIGN16     index_event_data;                   /* index of event-data     */
  T_ACCESS    access;                             /* access protection       */
  PB_BOOL     enabled;                            /* =>TRUE event is enabled */
  USIGN8      dummy;                              /* alignment byte          */
  STRINGV     name[MAX_OBJECT_NAME_LENGTH];       /* symbolic name           */
  USIGN8      extension[MAX_EXTENSION_LENGTH];    /* extension               */
} T_EVENT_OBJECT;


/*--- Event-Notification-Service --------------------------------------------*/
typedef  struct _T_EVENT_NOTIFY_REQ
{
   USIGN8      priority;                  /* priority                        */
   USIGN8      event_number;              /* event number                    */
   T_ACC_SPEC  acc_spec;                  /* access specification            */
   USIGN8      dummy;                     /* alignment                       */
   USIGN8      data_length;               /* # of event datas in byte        */
/* USIGN8      event_data[data_length];      list of event_datas             */
} T_EVENT_NOTIFY_REQ;


/*--- Event-Notification-With-Type-Service ----------------------------------*/
typedef  struct _T_EVENT_NOTIFY_WITH_TYPE_REQ
{
   USIGN8         priority;               /* priority                        */
   USIGN8         event_number;           /* event number                    */
   T_ACC_SPEC     acc_spec;               /* access specification            */
   T_TYPE_DESCR   type_descr;             /* type description                */
   USIGN8         dummy;                  /* alignment                       */
   USIGN8         data_length;            /* length of event data            */
/* USIGN8         event_data[data_length];   list of event_datas             */
} T_EVENT_NOTIFY_WITH_TYPE_REQ;



/*--- Alter-Event-Condition-Monitoring --------------------------------------*/
typedef  struct _T_ALT_EVN_CND_MNT_REQ
{
   T_ACC_SPEC  acc_spec;                  /* access specification            */
   PB_BOOL     enabled;                   /* enable or disable the event     */
   USIGN8      dummy;                     /* alignment byte                  */
} T_ALT_EVN_CND_MNT_REQ;



/*--- Acknowledge-Event-Notification ----------------------------------------*/
typedef  struct _T_ACK_EVN_NOTIFY_REQ
{
   T_ACC_SPEC  acc_spec;                          /* access specification    */
   USIGN8      event_number;                      /* event count number      */
   USIGN8      dummy;                             /* alignment byte          */
} T_ACK_EVN_NOTIFY_REQ;



/*****************************************************************************/
/*************   DOMAIN - MANAGEMENT                     *********************/
/*****************************************************************************/

/*--- Domain-Object-Description ---------------------------------------------*/
typedef struct _T_DOM_OBJECT
{
   USIGN16    index;                              /* index                   */
   USIGN8     obj_code;                           /* object code             */
   USIGN8     state;                              /* domain state            */
   USIGN8     upload_state;                       /* upload state            */
   INT8       counter;                            /* in use counter          */
   USIGN16    max_octets;                         /* max domain length       */
   T_ACCESS   access;                             /* access protection       */
   USIGN32    local_address;                      /* local address           */
   STRINGV    name[MAX_OBJECT_NAME_LENGTH];       /* symbolic name           */
   USIGN8     extension[MAX_EXTENSION_LENGTH];    /* extension               */
} T_DOM_OBJECT;


/*--- Domain-Download-Services ----------------------------------------------*/
/*--- Generic-Domain-Download-Services --------------------------------------*/
/*--- Domain-Upload-Services   ----------------------------------------------*/

typedef struct _T_DOM_REQ
{
   T_ACC_SPEC  acc_spec;                 /* access specification             */
} T_DOM_REQ;


typedef struct _T_DNL_UPL_SEG_CNF
{
   PB_BOOL  more_follows;                /* more_follows                     */
   USIGN8   data_len;                    /* data length                      */
/* USIGN8   data[data_len];                 list of data                     */
} T_DNL_UPL_SEG_CNF;


typedef struct _T_GEN_DNL_SEG_REQ
{
   T_ACC_SPEC  acc_spec;                   /* access specification          */
   PB_BOOL     more_follows;               /* more_follows                  */
   USIGN8      data_len;                   /* data length                   */
/* USIGN8      data[data_len];                list of data                  */
} T_GEN_DNL_SEG_REQ;


typedef struct _T_TERM_DNL_REQ
{
   T_ACC_SPEC  acc_spec;                    /* access specification          */
   PB_BOOL     final_result;                /* final result                  */
   USIGN8      dummy;                       /* alignment                     */
} T_TERM_DNL_REQ;


typedef struct _T_GEN_TERM_DNL_CNF
{
   PB_BOOL     final_result;                /* final result                  */
   USIGN8      dummy;                       /* alignment                     */
} T_GEN_TERM_DNL_CNF;


typedef struct _T_REQUEST_DOM_REQ
{
   T_ACC_SPEC  acc_spec;                    /* access specification          */
   USIGN8      dummy;                       /* alignment                     */
   USIGN8      add_info_length;             /* length of add. information    */
/* STRINGV     add_info[add_info_length];      additional information        */
} T_REQUEST_DOM_REQ;


/*****************************************************************************/
/*************   PROGRAM-INVOCATION-MANAGEMENT           *********************/
/*****************************************************************************/


/*--- Program-Invocation-Object ---------------------------------------------*/
typedef  struct _T_PI_OBJECT
{
   USIGN16    index;                                  /* pi_index in OD      */
   USIGN8     obj_code;                               /* object code for OD  */
   USIGN8     cnt_dom;                                /* # domains           */
   T_ACCESS   access;                                 /* access              */
   PB_BOOL    deletable;                              /* deletable           */
   PB_BOOL    reusable;                               /* reusable            */
   USIGN8     pi_state;                               /* state of pi         */
   USIGN8     dummy;                                  /* alignment byte      */
   STRINGV    name[MAX_OBJECT_NAME_LENGTH];           /* symbolic name of pi */
   USIGN8     extension[MAX_EXTENSION_LENGTH];        /* extension           */
   USIGN32    reserved;                               /* for internal use    */
/* USIGN16    dom_list[cnt_dom];                         domain index list   */
} T_PI_OBJECT;




/*--- Create-PI-Service -----------------------------------------------------*/
typedef struct _T_PI_CR8_REQ
{
   T_ACCESS       access;                            /* access rights           */
   USIGN8         cnt_dom;                           /* number of domains       */
   PB_BOOL        reusable;                          /* => TRUE pi is reusable  */
   USIGN16        index;                             /* PI-index                */
   STRINGV        name[MAX_OBJECT_NAME_LENGTH];      /* symbolic name           */
   USIGN8         extension[MAX_EXTENSION_LENGTH];   /* extension               */
#if (PB_VER >= 500)
/* T_DYN_ACC_SPEC dom_list[cnt_dom];                    list of domains         */
#else
/* T_ACC_SPEC     dom_list[cnt_dom];                    list of domains         */
#endif
} T_PI_CR8_REQ;


typedef struct _T_PI_CR8_CNF
{
  USIGN16   index;                            /* index of PI       */
} T_PI_CR8_CNF;


/*--- Delete-PI-Service -----------------------------------------------------*/
typedef  struct _T_PI_DEL_REQ
{
   T_ACC_SPEC   acc_spec;              /* access specification */
} T_PI_DEL_REQ;



/*--- Start-PI-Service ------------------------------------------------------*/
typedef  struct _T_PI_START_REQ
{
   T_ACC_SPEC   acc_spec;                                /* access specific. */
   USIGN8       exec_arg[MAX_EXECUTION_ARGUMENT_LENGTH]; /* execution arg.   */
} T_PI_START_REQ;


/*--- Stop-PI-Service -------------------------------------------------------*/
typedef  struct _T_PI_STOP_REQ
{
   T_ACC_SPEC   acc_spec;                                /* access specific. */
} T_PI_STOP_REQ;


/*--- Resume-PI-Service -----------------------------------------------------*/
typedef  struct _T_PI_RESUME_REQ
{
   T_ACC_SPEC   acc_spec;                                /* access specific. */
   USIGN8       exec_arg[MAX_EXECUTION_ARGUMENT_LENGTH]; /* execution arg.   */
} T_PI_RESUME_REQ;


/*--- Reset-PI-Service ------------------------------------------------------*/
typedef  struct _T_PI_RESET_REQ
{
   T_ACC_SPEC   acc_spec;                                /* access specific. */
} T_PI_RESET_REQ;


/*--- Kill-PI-Service -------------------------------------------------------*/
typedef  struct _T_PI_KILL_REQ
{
   T_ACC_SPEC   acc_spec;                                /* access specific. */
} T_PI_KILL_REQ;


/*--- PI-SET-STATE-Service ( only local Service ) ---------------------------*/
typedef struct _T_PI_SET_STATE_REQ
{
  USIGN32      vfd_number;                          /* vfd number           */
  T_ACC_SPEC   acc_spec;                            /* access specification */
  USIGN8       state;                               /* new PI state         */
  USIGN8       dummy;                               /* alignment byte       */
} T_PI_SET_STATE_REQ;


typedef struct _T_PI_SET_STATE_CNF
{
  USIGN32      vfd_number;                          /* vfd number           */
} T_PI_SET_STATE_CNF;



/********************************************************************************/
/*************   OD-MANAGEMENT                           ************************/
/********************************************************************************/

/* --- OD-Object-Description ---------------------------------------------------*/
typedef struct _T_OD_OBJ_DESCR_HDR
{
   USIGN16  index;             /* index = 0                                     */
   USIGN8   obj_code;          /* object-code = 1                               */
   PB_BOOL  flag;              /* => TRUE  write protected                      */
   USIGN8   length;            /* size of names (0-32)                          */
   PB_BOOL  protection;        /* access protection supported                   */
   INT16    version;           /* version */
   INT16    len_st_od;         /* length of the static type description         */
   USIGN16  first_index_s_od;  /* start index of the static object description  */
   INT16    len_s_od;          /* length of the static object description       */
   USIGN16  first_index_dv_od; /* start index of the dyn. var. list description */
   INT16    len_dv_od;         /* length of the  dyn. variable list description */
   USIGN16  first_index_dp_od; /* start index of the dyn. pi description        */
   INT16    len_dp_od;         /* length of the dyn. pi description             */
   USIGN32  int_addr;          /* internal address of OD description            */
   USIGN32  int_addr_st_od;    /* internal address of the static type descr.    */
   USIGN32  int_addr_s_od;     /* internal address of the static object descr.  */
   USIGN32  int_addr_dv_od;    /* internal address of the dyn. var. list descr. */
   USIGN32  int_addr_dp_od;    /* internal address of the dyn. pi description   */
} T_OD_OBJ_DESCR_HDR;

#if (PB_VER < 500)
typedef struct T_OV_OBJ_DESCR_HDR
{
  USIGN16  index;             /* index = 0                                   */
  USIGN8   obj_code;          /* object-code = 1                             */
  BOOL     flag;              /* => TRUE  write protected                    */
  USIGN8   length;            /* size of names (0-32)                        */
  BOOL     protection;        /* access protection supported                 */
  INT16    version;           /* version                                     */
  INT16    len_st_ov;         /* length of the static type description       */
  USIGN16  first_index_s_ov;  /* start index of the static object descr.     */
  INT16    len_s_ov;          /* length of the static object description     */
  USIGN16  first_index_dv_ov; /* start index of the dyn. var. list descr.    */
  INT16    len_dv_ov;         /* length of the  dyn. variable list descr.    */
  USIGN16  first_index_dp_ov; /* start index of the dyn. pi description      */
  INT16    len_dp_ov;         /* length of the dyn. pi description           */
  USIGN32  int_addr;          /* internal address of ov description          */
  USIGN32  int_addr_st_ov;    /* internal address of the static type descr.  */
  USIGN32  int_addr_s_ov;     /* internal address of the static object descr.*/
  USIGN32  int_addr_dv_ov;    /* internal address of the dyn. var. list descr*/
  USIGN32  int_addr_dp_ov;    /* internal address of the dyn. pi description */
} T_OV_OBJ_DESCR_HDR;
#endif

/* --- OD-Null-Object-Description -------------------------------------------*/
typedef struct _T_OD_NULL_OBJECT
{
   USIGN16  index;                             /* index                      */
   USIGN8   obj_code;                          /* object code                */
   USIGN8   dummy;                             /* alignment reasons          */
} T_OD_NULL_OBJECT;

#if (PB_VER < 500)
typedef T_OD_NULL_OBJECT  T_OV_NULL_OBJECT;
#endif

/* --- OD-Static-Type-Object-Description ------------------------------------*/
typedef struct _T_OD_ST_DT_DESCR
{
   USIGN16  index;                              /* index                     */
   USIGN8   obj_code;                           /* object code               */
   USIGN8   dummy;                              /* alignment byte            */
   STRINGV  meaning[MAX_OBJECT_NAME_LENGTH];    /* meaning of the type       */
} T_OD_ST_DT_DESCR;

#if (PB_VER < 500)
typedef T_OD_ST_DT_DESCR  T_OV_ST_DT_DESCR;
#endif


/* --- OD-Static-Structure-Object-Description -------------------------------*/
typedef struct _T_OD_DT_LIST
{
   USIGN16   index_of_type;               /* logical address of the type     */
   USIGN8    length;                      /* length of the element in octets */
   USIGN8    dummy;                       /* alignment byte                  */
} T_OD_DT_LIST;

#if (PB_VER < 500)
typedef T_OD_DT_LIST  T_OV_DT_LIST;
#endif


typedef struct _T_OD_ST_DS_DESCR
{
   USIGN16       index;                   /* index                           */
   USIGN8        obj_code;                /* object code                     */
   USIGN8        no_of_elements;          /* number of record elements       */
   USIGN32       reserved;                /* for internal use                */
/* T_OD_DT_LIST  dt_list[no_of_elements];    data type list                  */
} T_OD_ST_DS_DESCR;

#if (PB_VER < 500)
typedef struct _T_OV_ST_DS_DESCR
{
   USIGN16       index;                   /* index                           */
   USIGN8        obj_code;                /* object code                     */
   USIGN8        no_of_elements;          /* number of record elements       */
   USIGN32       reserved;                /* for internal use                */
/* T_OV_DT_LIST  dt_list[no_of_elements];    data type list                  */
} T_OV_ST_DS_DESCR;
#endif


/* --- OD-OBJECT-DESCRIPTION ----------------------------------------------- */
#if (PB_VER >= 500)
typedef struct _T_OBJECT_DESCR
{
   union
   {
     T_OD_OBJ_DESCR_HDR    od_obj_descr;
     T_OD_NULL_OBJECT      null_obj_descr;
     T_OD_ST_DT_DESCR      dt_obj_descr;
     T_OD_ST_DS_DESCR      ds_obj_descr;
     T_SIMPLE_VAR_OBJECT   s_var_obj_descr;
     T_ARRAY_OBJECT        a_var_obj_descr;
     T_RECORD_OBJECT       r_var_obj_descr;
     T_VAR_LIST_OBJECT     vlist_obj_descr;
     T_DOM_OBJECT          dom_obj_descr;
     T_EVENT_OBJECT        evn_obj_descr;
     T_PI_OBJECT           pi_obj_descr;
   } id;
} T_OBJECT_DESCR;
#else
typedef struct _T_OBJECT_DESCR
{
   union
   {
     T_OV_OBJ_DESCR_HDR    ov_obj_descr;
     T_OV_NULL_OBJECT      null_obj_descr;
     T_OV_ST_DT_DESCR      dt_obj_descr;
     T_OV_ST_DS_DESCR      ds_obj_descr;
     T_SIMPLE_VAR_OBJECT   s_var_obj_descr;
     T_ARRAY_OBJECT        a_var_obj_descr;
     T_RECORD_OBJECT       r_var_obj_descr;
     T_VAR_LIST_OBJECT     vlist_obj_descr;
     T_DOM_OBJECT          dom_obj_descr;
     T_EVENT_OBJECT        evn_obj_descr;
     T_PI_OBJECT           pi_obj_descr;
   } id;
} T_OBJECT_DESCR;
#endif

/* --- OD-PACKED-OBJECT-DESCRIPTION ---------------------------------------- */
typedef struct _T_PACKED_OBJECT_DESCR
{
   USIGN8    length;                   /* length of packed object description*/
/* USIGN8    packed_obj_descr[length];    packed object description          */
} T_PACKED_OBJECT_DESCR;


/* --- Get-OD-Service -------------------------------------------------------*/
typedef struct _T_GET_OD_REQ
{
   PB_BOOL    format;              /* TRUE = long format / FALSE = short    */
   USIGN8     dummy;                /* alignment byte                        */
   T_ACC_SPEC acc_spec;             /* access specification                  */
} T_GET_OD_REQ;

#if (PB_VER < 500)
typedef T_GET_OD_REQ  T_GET_OV_REQ;
#endif

typedef struct _T_GET_OD_CNF
{
   PB_BOOL                more_follows;                   /* further object descr. follow */
   USIGN8                 no_of_od_descr;                 /* # of object description      */
/* T_PACKED_OBJECT_DESCR  obj_descr_list[no_of_od_descr];    list of object descriptions  */
} T_GET_OD_CNF;

#if (PB_VER < 500)
typedef struct _T_GET_OV_CNF
{
   PB_BOOL                more_follows;                   /* further object descr. follow */
   USIGN8                 no_of_ov_descr;                 /* # of object description      */
/* T_PACKED_OBJECT_DESCR  obj_descr_list[no_of_ov_descr];    list of object descriptions  */
} T_GET_OV_CNF;
#endif


/* --- Put-OD-Services ------------------------------------------------------*/
typedef struct _T_INIT_PUT_OD_REQ
{
  INT8    consequence;              /* Loading interactive/non-interactive   */
  USIGN8  dummy;                    /* alignment                             */
} T_INIT_PUT_OD_REQ;

#if (PB_VER < 500)
typedef T_INIT_PUT_OD_REQ  T_INIT_PUT_OV_REQ;
#endif

typedef struct _T_PUT_OD_REQ
{
   USIGN8                 dummy;                          /* alignment                   */
   USIGN8                 no_of_od_descr;                 /* # of object description     */
/* T_PACKED_OBJECT_DESCR  obj_descr_list[no_of_od_descr];    list of object descriptions */
} T_PUT_OD_REQ;

#if (PB_VER < 500)
typedef struct _T_PUT_OV_REQ
{
   USIGN8                 dummy;                          /* alignment                   */
   USIGN8                 no_of_ov_descr;                 /* # of object description     */
/* T_PACKED_OBJECT_DESCR  obj_descr_list[no_of_ov_descr];    list of object descriptions */
} T_PUT_OV_REQ;
#endif

/* --- Load-OD-Local-Service ------------------------------------------------*/
typedef struct _T_INIT_LOAD_OD_REQ
{
   USIGN32       vfd_number;
   INT8          consequence;
   USIGN8        dummy;
} T_INIT_LOAD_OD_REQ;

#if (PB_VER < 500)
typedef T_INIT_LOAD_OD_REQ  T_INIT_LOAD_OV_REQ;
#endif

typedef struct _T_INIT_LOAD_OD_CNF
{
   USIGN32       vfd_number;
} T_INIT_LOAD_OD_CNF;

#if (PB_VER < 500)
typedef T_INIT_LOAD_OD_CNF  T_INIT_LOAD_OV_CNF;
#endif

typedef struct _T_LOAD_OD_REQ
{
   USIGN32        vfd_number;
   T_OBJECT_DESCR obj_descr;
} T_LOAD_OD_REQ;

#if (PB_VER < 500)
typedef T_LOAD_OD_REQ  T_LOAD_OV_REQ;
#endif

typedef struct _T_LOAD_OD_CNF
{
   USIGN32        vfd_number;
} T_LOAD_OD_CNF;

#if (PB_VER < 500)
typedef T_LOAD_OD_CNF  T_LOAD_OV_CNF;
#endif

typedef struct _T_TERM_LOAD_OD_REQ
{
   USIGN32       vfd_number;
} T_TERM_LOAD_OD_REQ;

#if (PB_VER < 500)
typedef T_TERM_LOAD_OD_REQ  T_TERM_LOAD_OV_REQ;
#endif

typedef struct _T_TERM_LOAD_OD_CNF
{
   USIGN32       vfd_number;
} T_TERM_LOAD_OD_CNF;

#if (PB_VER < 500)
typedef T_TERM_LOAD_OD_CNF  T_TERM_LOAD_OV_CNF;
#endif


/*--- Read-OD-Local-Service -------------------------------------------------*/
typedef struct _T_OD_READ_LOC_REQ
{
  USIGN32    vfd_number;
  USIGN8     obj_code;
  USIGN8     dummy;
  T_ACC_SPEC acc_spec;
} T_OD_READ_LOC_REQ;

#if (PB_VER < 500)
typedef T_OD_READ_LOC_REQ  T_OV_READ_LOC_REQ;
#endif


typedef struct _T_OD_READ_LOC_CNF
{
  USIGN32            vfd_number;          /* vfd number                      */
  T_OBJECT_DESCR     obj_descr;           /* object description              */
} T_OD_READ_LOC_CNF;

#if (PB_VER < 500)
typedef T_OD_READ_LOC_CNF  T_OV_READ_LOC_CNF;
#endif


/*****************************************************************************/
/*************   VFD-SUPPORT-MANAGEMENT                  *********************/
/*****************************************************************************/

/*--- Create-VFD-Service ----------------------------------------------------*/
typedef struct _T_VFD_CREATE_REQ
{
   USIGN32      vfd_number;                          /* vfd number           */
   STRINGV      vendor_name[MAX_VFD_STRING_LENGTH];  /* vendor name          */
   STRINGV      model_name[MAX_VFD_STRING_LENGTH];   /* model-name           */
   STRINGV      revision[MAX_VFD_STRING_LENGTH];     /* revision no          */
   USIGN8       profile_number[2];                   /* profile number       */
} T_VFD_CREATE_REQ;

typedef struct _T_VFD_CREATE_CNF
{
   USIGN32      vfd_number;                          /* vfd number           */
} T_VFD_CREATE_CNF;


/*--- VFD-Set-Physical-Status -----------------------------------------------*/
typedef struct _T_VFD_SET_PHYS_STATUS_REQ
{
   USIGN32      vfd_number;                      /* vfd number               */
   USIGN8       physical_status;                 /* physical status          */
   USIGN8       dummy;                           /* alignment byte           */
} T_VFD_SET_PHYS_STATUS_REQ;

typedef struct _T_VFD_SET_PHYS_STATUS_CNF
{
   USIGN32      vfd_number;                      /* vfd number               */
} T_VFD_SET_PHYS_STATUS_CNF;


/*--- Status-Service --------------------------------------------------------*/
typedef struct _T_VFD_STATUS_CNF
{
   USIGN8       logical_status;                /* logical status             */
   USIGN8       physical_status;               /* physical status            */
   USIGN8       local_detail[3];               /* local detail               */
   USIGN8       dummy;                         /* alignment byte             */
} T_VFD_STATUS_CNF;


/*--- Unsolicited-Status-Service --------------------------------------------*/
typedef struct _T_VFD_UNSOL_STATUS_REQ
{
   USIGN8       priority;                      /* priority                   */
   USIGN8       logical_status;                /* logical status             */
   USIGN8       physical_status;               /* physical status            */
   USIGN8       dummy1;                        /* alignment byte             */
   USIGN8       local_detail[3];               /* local detail               */
   USIGN8       dummy2;                        /* alignment byte             */
} T_VFD_UNSOL_STATUS_REQ;


/*--- Identify-Service ------------------------------------------------------*/
typedef struct _T_VFD_IDENTIFY_CNF
{
   STRINGV   vendor_name[MAX_VFD_STRING_LENGTH]; /* producer of the device   */
   STRINGV   model_name[MAX_VFD_STRING_LENGTH];  /* model-name of the device */
   STRINGV   revision[MAX_VFD_STRING_LENGTH];    /* revision of the device   */
} T_VFD_IDENTIFY_CNF;



#pragma warning (disable : 4103)     /* used #pragma pack to reset alignment */
#ifdef WIN32
#pragma pack(pop)
#else
#pragma pack()
#endif
#pragma warning (default : 4103)


#endif
