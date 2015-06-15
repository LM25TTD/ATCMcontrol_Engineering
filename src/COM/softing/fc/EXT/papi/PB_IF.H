/*****************************************************************************/
/*                   PROFIBUS APPLICATION PROGRAM INTERFACE                  */
/*                                                                           */
/*  Filename    : PB_IF.H                                                    */
/*  Version     : 5.27.0.00.release                                          */
/*  Date        : 30-June-2004                                               */
/*                                                                           */
/*  Description : This file contains the extern function declarations,       */
/*                defines and types of the PROFIBUS Communication Interface  */
/*                                                                           */
/*****************************************************************************/

#ifndef __PB_IF__
#define __PB_IF__


#pragma warning (disable : 4103)     /* used #pragma pack to change alignment */
#ifdef WIN32
#pragma pack(push,2)
#else
#pragma pack(2)
#endif
#pragma warning (default : 4103)


/**********************************************************************************/
/* INTERFACE DEFINES                                                              */
/**********************************************************************************/
/* contants for DeviceTypes -(only used for WinNT/Win2K-Interface) -------------- */
/* --- DP Devices --------------------------------------------------------------- */
#define DEVICE_DP_MANAGEMENT     1
#define DEVICE_DP_SERVICE        2
#define DEVICE_DP_SLAVE_DATA     3
#define DEVICE_DP_MSAC           9

/* --- FDL Devices -------------------------------------------------------------- */
#define DEVICE_FDL_MANAGEMENT    4
#define DEVICE_FDL_SAP           5

/* --- FMS Devices -------------------------------------------------------------- */
#define DEVICE_FMS_MANAGEMENT    6
#define DEVICE_FMS_CR            7

/* --- Basic Management Device -------------------------------------------------- */
#define DEVICE_BASIC_MANAGEMENT  8


/* --- contants for IRQ values --------------------------------                   */
#define REQ_IRQ                  0xF0                  /* IND/CON IRQ is received */
#define ACK_IRQ                  0x0F                      /* acknowledge REQ/RES */
#define DP_SLAVE_IO_REQ_IRQ      0xE0              /* MASTER: DP-SLAVE-IO IND/REQ */
#define DP_SLAVE_IO_ACK_IRQ      0x0E  /* MASTER: DP-SLAVE-IO acknowldege IND/REQ */
#define DP_DATA_STOP_REQ_IRQ     0xD0  /* MASTER: data transfer stop REQ received */
#define DP_DATA_STOP_ACK_IRQ     0x0D   /* MASTER: data transfer stop Acknowldege */
#define TRC_REQ_IRQ              0xC0                    /* TRACE REQ is received */
#define TRC_ACK_IRQ              0x0C                        /* TRACE acknowledge */
#define EXCEPTION_REQ_IRQ        0xB0                        /* Exception Request */
#define EXCEPTION_ACK_IRQ        0x0B                    /* Exception Acknowledge */
#define DPS_SLAVE_INP_REQ_IRQ    0xA0            /* SLAVE: DP-SLAVE-INPUT request */
#define DPS_SLAVE_INP_ACK_IRQ    0x0A        /* SLAVE: DP-SLAVE-INPUT Acknowldege */
#define DPS_SLAVE_OUTP_REQ_IRQ   0x90           /* SLAVE: DP-SLAVE-OUTPUT request */
#define DPS_SLAVE_OUTP_ACK_IRQ   0x09       /* SLAVE: DP-SLAVE-OUTPUT Acknowldege */

/* --- contants to receive an indication or confirmation ------------------------ */
#define CON_IND_RECEIVED    0x0001              /* ind. or con. has been received */
#define NO_CON_IND_RECEIVED 0x0000                   /* nothing has been received */

/* --- values > CON_IND_RECEIVED are error returns (see pb_err.h)  -------------- */

/* --- OK return value ---------------------------------------------------------- */
#define E_OK                0                                        /* no errors */
/* --- values != E_OK are error returns (see pb_err.h) -------------------------- */

/* --- service result ----------------------------------------------------------- */
#define NEG                 0x01                  /* result for negative response */
#define POS                 0x00                  /* result for positive response */

/* --- service priority --------------------------------------------------------- */
#define LOW                 0x00                                 /* high priority */
#define HIGH                0x01                                  /* low priority */


/* --- service primitives ------------------------------------------------------- */
#define REQ                 0x00                             /* request primitive */
#define CON                 0x01                        /* confirmation primitive */
#define IND                 0x02                          /* indication primitive */
#define RES                 0x03                            /* response primitive */
#define RET                 0x04      /* return primitive not used by application */

/* --- layer identifiers -------------------------------------------------------- */
#define USR                 0x00                               /* identifier USER */
#define FMS                 0x01                                /* identifier FMS */
#define LLI                 0x02                                /* identifier LLI */
#define FDL                 0x03                                /* identifier FDL */
#define FM7                 0x04                                /* identifier FM7 */
#define FMB                 0x05                                /* identifier FMB */
#define FMS_USR             0x06                           /* identifier FMS-USER */
#define FM7_USR             0x07                           /* identifier FM7-USER */
#define FMB_USR             0x08                           /* identifier FMB-USER */
#define DPS                 0x09                                /* identifier DPS */
#define DPS_USR             0x0A                           /* identifier DPS-USER */
#define DP                  0x0B                                 /* identifier DP */
#define DP_USR              0x0C                            /* identifier DP-USER */
#define FDLIF               0x0D                              /* identifier FDLIF */
#define FDLIF_USR           0x0E                         /* identifier FDLIF-USER */

#define PAPI                0xF0               /* identifier Application-Layer-IF */

#if (PB_VER < 500)
#define FMA7                FM7                                /* identifier FMA7 */
#define FMA2                FMB                                /* identifier FMA2 */
#define FMA7_USR            FM7_USR                       /* identifier FMA7-USER */
#endif


/* --- identifiers for data description interface ------------------------------- */
/* --- 0x00 - 0x3F used by FMS -- (no identifiers defined) ---------------------- */

/* --- 0x40 - 0x7F reserved by management -- (no identifiers defined) ----------- */

/* --- 0x80 - 0x9F reserved by DP ----------------------------------------------- */
/* --- DP-MASTER ---------------------------------------------------------------- */
#define ID_DP_SLAVE_IO_IMAGE         0x80     /* MASTER: image for slave io datas */
#define ID_DP_STATUS_IMAGE           0x81       /* MASTER: image for status datas */
#define ID_DP_SLAVE_IO_CONFIG_IMAGE  0x82     /* MASTER: DPRAM layout of slave io */

/* --- DP-SLAVE ----------------------------------------------------------------- */
#define ID_DPS_SLAVE_INPUT_IMAGE     0x90   /* SLAVE: image for slave input datas */
#define ID_DPS_SLAVE_OUTPUT_IMAGE    0x91  /* SLAVE: image for slave output datas */

/* --- 0xA0 - 0xEF reserved for future use --- (no identifiers defined) --------- */

/* --- 0xF0 - 0xFF reserved for diagonsis  -------------------------------------- */
#define ID_EXCEPTION_IMAGE           0xF0             /* image for exeption datas */
#define ID_FW_VERS_IMAGE             0xF1           /* image for firmware version */
#define ID_SERIAL_DEVICE_NUMBER      0xF2      /* image for serial device number  */
#define ID_TRACE_IMAGE               0xF3                /* image for TRACE datas */

/* --- idebtifier for end of data description list ------------------------------ */
#define EOF_DATA_DESCR_LIST          0x00         /* end of data description list */


/**********************************************************************************/
/* PROFI SERVICE DESCRIPTION BLOCK                                                */
/**********************************************************************************/

typedef struct _T_PROFI_SERVICE_DESCR
{
  USIGN16     comm_ref;                                /* communication reference */
  USIGN8      layer;                                          /* layer identifier */
  USIGN8      service;                                      /* service identifier */
  USIGN8      primitive;                                     /* service primitive */
  INT8        invoke_id;                                             /* invoke id */
  INT16       result;                              /* service result (POS or NEG) */
} T_PROFI_SERVICE_DESCR;


#ifdef WIN16
/**********************************************************************************/
/* PROFI INITIALIZATION DATA STRUCTURE                                            */
/**********************************************************************************/
typedef struct _T_PROFI_INIT
{
  USIGN32      dpr_address;                                        /* DPR address */
  INT16        io_port_address;                                /* IO port address */
  PB_BOOL      load_firmware;   /* PB_TRUE  for PROFI-IF
                                   PB_FALSE for PROFIboard,PROFIcard and PROFI104 */
  USIGN8       time_out;                          /* time out interval in seconds */
  CSTRING      *loader_file;                       /* loader file (PROFI-IF only) */
  CSTRING      *firmware_file;                    /* firmware file (PROFI-IF only */
  USIGN8       host_type;                                     /* for internal use */
  USIGN8       irq_vector;                                    /* IRQ line to host */
  USIGN8       dpr_access_mode;                 /* DPR access mode (8/16 Bit ...) */
  USIGN8       address_mode;                                 /* host address mode */
  USIGN8       poll_int_mode;                             /* host POLL / IRQ mode */
  USIGN8       cntrl_type;                                    /* for internal use */
  USIGN8       token_drive;           /* indicates the token drive (only PROFI-IF)*/
  USIGN8       reserved_1;                                            /* reserved */
  USIGN16      reserved_2;                                            /* reserved */
  USIGN16      reserved_3;                                            /* reserved */
 } T_PROFI_INIT;

/* --- macro to set T_PROFI_INIT data structure with default values ------------  */
#define _SET_PROFI_INIT_DEF_PARAM(init_param,a,b)                            \
             init_param.dpr_address      = a;                                \
             init_param.load_firmware    = PB_FALSE;                         \
             init_param.io_port_address  = b;                                \
             init_param.irq_vector       = (USIGN8)   0x00;                  \
             init_param.dpr_access_mode  = (USIGN8)   0x03;                  \
             init_param.address_mode     = (USIGN8)   0x0C;                  \
             init_param.poll_int_mode    = (USIGN8)   0x00;                  \
             init_param.time_out         = (USIGN8)   0x03
#endif


/************************************************************************/
/* Global function declarations using for 16/32BIT PROFIBUS API and for */
/* compatibility mode using WIN-NT PROFIBUS API                         */
/************************************************************************/

#ifndef PB_API_FUNC_NOT_USED

#ifdef __cplusplus
  extern "C" {
#endif


#ifndef UNDER_RTSS
#ifdef  WIN32
FUNCTION extern INT16 CALL_CONV profi_set_default
         (
           IN USIGN8  Board,
           IN USIGN8  Channel,
           IN USIGN32 ReadTimeout,
           IN USIGN32 WriteTimeout
         )
/*----------------------------------------------------------------------------
FUNCTIONAL_DESCRIPTION

This function is used to initialize the WIN32 PROFIBUS-API. The function function
has to be called before any other function of PROFIBUS-API is called.

IN:  Board          -> number of the PROFIBUS board (0..9)
IN:  Channel        -> channel number (0)
IN:  ReadTimeout    -> receive timeout in ms (WAIT_FOREVER for infinite wait)
IN:  Writetimeout   -> send timeout in ms (WAIT_FOREVER for infinite wait)

Possible return values:
- E_OK                             -> Interface is initialized
- E_IF_NO_CNTRL_RES                -> controller does not respond
- E_IF_INVALID_CNTRL_TYPE_VERSION  -> invalid controller type or software version
- E_IF_INIT_INVALID_PARAMETER      -> invalid initialize parameter
- E_IF_INVALID_VERSION             -> invalid version
- E_IF_NO_CNTRL_PRESENT            -> no controller present
- E_IF_INIT_FAILED                 -> initialization failed

-----------------------------------------------------------------------------*/
;

FUNCTION extern INT16 CALL_CONV profi_init
         (
           IN USIGN8  Board,
           IN USIGN32 ReadTimeout,
           IN USIGN32 WriteTimeout
         )
/*----------------------------------------------------------------------------
FUNCTIONAL_DESCRIPTION

This function is used to initialize the WIN32 PROFIBUS-API. The function function
has to be called before any other function of PROFIBUS-API is called.

IN:  Board          -> number of the PROFIBUS board (0..9)
IN:  Channel        -> channel number (0)
IN:  ReadTimeout    -> receive timeout in ms (WAIT_FOREVER for infinite wait)
IN:  Writetimeout   -> send timeout in ms (WAIT_FOREVER for infinite wait)

Possible return values:
- E_OK                             -> Interface is initialized
- E_IF_NO_CNTRL_RES                -> controller does not respond
- E_IF_INVALID_CNTRL_TYPE_VERSION  -> invalid controller type or software version
- E_IF_INIT_INVALID_PARAMETER      -> invalid initialize parameter
- E_IF_INVALID_VERSION             -> invalid version
- E_IF_NO_CNTRL_PRESENT            -> no controller present
- E_IF_INIT_FAILED                 -> initialization failed

-----------------------------------------------------------------------------*/
;
#endif


FUNCTION extern INT16 CALL_CONV init_profibus
        (
          IN  USIGN32  DprAdress,
          IN  USIGN16  IoPortAdress,
          IN  PB_BOOL  Dummy
        )

/*----------------------------------------------------------------------------
FUNCTIONAL_DESCRIPTION

This function is used initialize the PROFIBUS-API with default values and start
the PROFIBUS controller. The function function has to be called before any other
function of PROFIBUS-API is called.

IN:  DprAdress         -> dummy
IN:  IoPortAdress      -> dummy
IN:  Dummy             -> dummy

Possible return values:

- E_OK                             -> Interface is initialized
- E_IF_NO_CNTRL_RES                -> controller does not respond
- E_IF_INVALID_CNTRL_TYPE_VERSION  -> invalid controller type or software version
- E_IF_INIT_INVALID_PARAMETER      -> invalid initialize parameter
- E_IF_INVALID_VERSION             -> invalid version
- E_IF_NO_CNTRL_PRESENT            -> no controller present
- E_IF_INIT_FAILED                 -> initialization failed
-----------------------------------------------------------------------------*/
;



FUNCTION extern INT16 CALL_CONV profi_end(VOID)

/*----------------------------------------------------------------------------
FUNCTIONAL_DESCRIPTION

This function is used to shutdown the PROFIBUS-API and shutdown the PROFIBUS
controller.

Possible return values:
- E_OK

-----------------------------------------------------------------------------*/
;



FUNCTION extern INT16 CALL_CONV profi_snd_req_res
         (
          IN T_PROFI_SERVICE_DESCR * pSdb,
          IN VOID                  * pData,
          IN PB_BOOL                 dummy
         )

/*----------------------------------------------------------------------------
FUNCTIONAL_DESCRIPTION

This function is used to send a Service-Request or a Service-Response
to the PROFIBUS controller.

IN:  pSdb                  -> pointer to SERVICE-DESCRIPTION-BLOCK
IN:  pData                 -> pointer to service specific data
IN:  dummy                 -> dummy


Possible return values:

- E_OK                           -> no error occured

- E_IF_INVALID_LAYER             -> invalid layer
- E_IF_INVALID_SERVICE           -> invalid service identifier
- E_IF_INVALID_PRIMITIVE         -> invalid service primitive
- E_IF_RESOURCE_UNAVAILABLE      -> no resource available
- E_IF_NO_PARALLEL_SERVICES      -> no parallel services allowed
- E_IF_SERVICE_CONSTR_CONFLICT   -> service temporarily not executable
- E_IF_SERVICE_NOT_SUPPORTED     -> service not supported in subset
- E_IF_SERVICE_NOT_EXECUTABLE    -> service not executable

- E_IF_NO_CNTRL_RES              -> controller does not respond  (CMI_TIMEOUT)
- E_IF_INVALID_DATA_SIZE         -> not enough CMI memory available for REQ or RES
- E_IF_INVALID_VERSION           -> invalid version (only PROFDI-IF)
- E_IF_INVALID_PARAMETER         -> invalid parameter in REQ or RES
- E_IF_PAPI_NOT_INITIALIZED      -> API not initialized
----------------------------------------------------------------------------*/
;



FUNCTION extern INT16 CALL_CONV profi_rcv_con_ind
         (
          OUT   T_PROFI_SERVICE_DESCR * pSdb,
          OUT   VOID                  * pData,
          INOUT USIGN16               * pDataLength
         )

/*----------------------------------------------------------------------------
FUNCTIONAL_DESCRIPTION

This function is used to receive a Service-Indication or a Service-Confirmation
from the PROFIBUS controller.


OUT:    pSdb             -> pointer to SERVICE-DESCRIPTION-BLOCK
OUT:    pData            -> pointer to data buffer
INOUT:  pDataLength      -> IN:   length of data buffer
                            OUT:  length of received data
Possible return values:

- CON_IND_RECEIVED          -> a confirmation or indication has been received
- NO_CON_IND_RECEIVED       -> no confirmation or indication has been received

- E_IF_FATAL_ERROR          -> unrecoverable error in PROTOCOL SW
- E_IF_INVALID_DATA_SIZE    -> size of data block provided not sufficient
- E_IF_PAPI_NOT_INITIALIZED -> API not initialized
----------------------------------------------------------------------------*/
;


FUNCTION extern INT16 CALL_CONV profi_set_data
        (
          IN  USIGN8    DataId,
          IN  USIGN16   Offset,
          IN  USIGN16   DataLength,
          IN  VOID    * pData
        )

/*-----------------------------------------------------------------------------
FUNCTIONAL_DESCRIPTION

This function is used to write data to CMI data area

IN:   DataId         -> data image identifier
                         - ID_DP_SLAVE_IO_IMAGE     (DPM: image for slave io data)
                         - ID_DP_STATUS_IMAGE       (DPM: image for status data)

IN:   Offset         -> write at offset in data image
IN:   DataLength     -> length of  data to write
IN:   pData          -> pointer to data to write


possible return values:
- E_OK                          -> OK
- E_IF_SERVICE_CONSTR_CONFLICT  -> service not executable at time
- E_IF_SERVICE_NOT_SUPPORTED    -> service not supported
- E_IF_INVALID_DATA_SIZE        -> invalid user data size
- E_IF_PAPI_NOT_INITIALIZED     -> API not initialized

-----------------------------------------------------------------------------*/
;



FUNCTION extern INT16 CALL_CONV profi_get_data
        (
          IN     USIGN8     DataId,
          IN     USIGN16    Offset,
          INOUT  USIGN16  * pDataLength,
          OUT    VOID     * pData
        )

/*-----------------------------------------------------------------------------
FUNCTIONAL_DESCRIPTION

This function is used to read  data from CMI data area

IN:    DataId        -> data image identifier
                         - ID_DP_SLAVE_IO_IMAGE        (DPM: image for slave io data)
                         - ID_DP_STATUS_IMAGE          (DPM: image for status data)

IN:    Offset        -> read at offset in data image
INOUT: pDataLength      IN:  length of data buffer
                        OUT: length of received data
OUT:   pData         -> pointer to data buffer

possible return values:
- E_OK                          -> OK
- E_IF_SERVICE_CONSTR_CONFLICT  -> service not executable at time
- E_IF_SERVICE_NOT_SUPPORTED    -> service not supported
- E_IF_INVALID_DATA_SIZE        -> invalid user data size
- E_IF_PAPI_NOT_INITIALIZED     -> API not initialized
- E_IF_OS_ERROR                 -> NT system error
-----------------------------------------------------------------------------*/
;




FUNCTION extern INT16 CALL_CONV profi_set_dps_input_data
        (
          IN    USIGN8  * pData,
          IN    USIGN8    DataLength,
          OUT   USIGN8  * pState
        )

/*-----------------------------------------------------------------------------
FUNCTIONAL_DESCRIPTION

This function is used to write DP Slave input data to DPS_SLAVE_INPUT_IMAGE

IN:   pData      -> pointer to new input data
IN:   DataLength -> number bytes of input data
OUT:  pState     -> pointer to a status variable for the recent input data status

possible return values:
- E_OK                          -> OK
- E_IF_INVALID_DATA_SIZE        -> data_size does not match the expected input data size
- E_IF_NO_CNTRL_RES             -> timeout controller does not response
- E_IF_PAPI_NOT_INITIALIZED     -> API not initialized

-----------------------------------------------------------------------------*/
;




FUNCTION extern INT16 CALL_CONV profi_get_dps_input_data
        (
          OUT   USIGN8 * pData,
          INOUT USIGN8 * pDataLength,
          OUT   USIGN8 * pState
        )

/*-----------------------------------------------------------------------------
FUNCTIONAL_DESCRIPTION

This function is used to read data CMI DPS_SLAVE_INPUT_IMAGE

OUT:    pData       -> destination buffer for input data
INOUT:  pDataLength -> sizeof destination buffer and number of bytes read
OUT:    pState      -> status of input data if read successfully

possible return values:
- E_OK                          -> OK
- E_IF_INVALID_DATA_SIZE        -> invalid user data size
- E_IF_PAPI_NOT_INITIALIZED     -> API not initialized

-----------------------------------------------------------------------------*/
;





FUNCTION extern INT16 CALL_CONV profi_get_dps_output_data
        (
          OUT   USIGN8 * pData,
          INOUT USIGN8 * pDataLength,
          OUT   USIGN8 * pState
        )

/*-----------------------------------------------------------------------------
FUNCTIONAL_DESCRIPTION

This function is used to read data from DPS_SLAVE_OUTPUT_IMAGE.

OUT:    pData       -> destination buffer for output data
INOUT:  pDataLength -> sizeof destination buffer and number of bytes read
OUT:    pState      -> status of output data if read successfully

possible return values:
- E_OK                          -> OK
- E_IF_SERVICE_NOT_SUPPORTED    -> service not supported
- E_IF_SERVICE_CONSTR_CONFLICT  -> service not executable at time
- E_IF_INVALID_DATA_SIZE        -> invalid user data size
- E_IF_PAPI_NOT_INITIALIZED     -> API not initialized

-----------------------------------------------------------------------------*/
;




FUNCTION extern INT16 CALL_CONV profi_get_versions
         (
           OUT CSTRING * pPapiVersion,
           OUT CSTRING * pFirmwareVersion
         )
/*----------------------------------------------------------------------------
FUNCTIONAL_DESCRIPTION

This function is used to get the vesrion strings of PAPI and firmware.

OUT:    pPapiVersion      -> data buffer for PAPI version string
OUT:    pFirmwareVersion  -> data buffer for firmware version string

NOTE: There must be at least 100 Bytes (VERSION_STRING_LENGTH) free space for
      each INOUT buffer.

Possible return values:
- E_OK

-----------------------------------------------------------------------------*/
;



FUNCTION extern INT16 CALL_CONV profi_get_serial_device_number
         (
           OUT USIGN32 * pSerialDeviceNumber
         )
/*----------------------------------------------------------------------------
FUNCTIONAL_DESCRIPTION

This function is used to get the serial device number of the PROFIBUS
controller

OUT:  pSerialDeviceNumber -> serial device number

Possible return values:
- E_OK
- E_IF_PAPI_NOT_INITIALIZED      -> API not initialized

-----------------------------------------------------------------------------*/
;




FUNCTION extern INT16 CALL_CONV profi_get_last_error(VOID)

/*----------------------------------------------------------------------------
FUNCTIONAL_DESCRIPTION

This function is returns the additional last error code for INTERFACE-ERRORs
controller

Possible return values:
- additional last error code

-----------------------------------------------------------------------------*/
;

#else

FUNCTION GLOBAL INT16 CALL_CONV profi_rtx_init
         (
           IN USIGN8  Board,
           IN USIGN32 ReadTimeout,
           IN USIGN32 WriteTimeout,
           IN USIGN32 InterruptThreadPriority
         )
/*----------------------------------------------------------------------------
FUNCTIONAL_DESCRIPTION

This function is used to initialize the PROFIBUS WinXP/Win2K RTAPI. The function
has to be called before any otherfunction of PROFIBUS-API is called.

IN:  Board                   -> number of the PROFIBUS board (0..7)
IN:  Channel                 -> channel number (0)
IN:  ReadTimeout             -> receive timeout in ms (WAIT_FOREVER for infinite wait)
IN:  Writetimeout            -> send timeout in ms (WAIT_FOREVER for infinite wait)
IN:  InterruptThreadPriority -> 0.127


Possible return values:
- E_OK                             -> Interface is initialized
- E_IF_NO_CNTRL_RES                -> controller does not respond
- E_IF_INVALID_CNTRL_TYPE_VERSION  -> invalid controller type or software version
- E_IF_INIT_INVALID_PARAMETER      -> invalid initialize parameter
- E_IF_INVALID_VERSION             -> invalid version
- E_IF_NO_CNTRL_PRESENT            -> no controller present
- E_IF_INIT_FAILED                 -> initialization failed

-----------------------------------------------------------------------------*/
;

FUNCTION extern INT16 CALL_CONV profi_rtx_end(VOID)

/*----------------------------------------------------------------------------
FUNCTIONAL_DESCRIPTION

This function is used to shutdown the PROFIBUS WinXP/Win2K RTAPI and shutdown the
PROFIBUS controller.

Possible return values:
- E_OK

-----------------------------------------------------------------------------*/
;



FUNCTION extern INT16 CALL_CONV profi_rtx_snd_req_res
         (
          IN T_PROFI_SERVICE_DESCR * pSdb,
          IN VOID                  * pData,
          IN PB_BOOL                 dummy
         )

/*----------------------------------------------------------------------------
FUNCTIONAL_DESCRIPTION

This function is used to send a Service-Request or a Service-Response
via PROFIBUS WinXP/Win2K RTAPI to the PROFIBUS controller.

IN:  pSdb                  -> pointer to SERVICE-DESCRIPTION-BLOCK
IN:  pData                 -> pointer to service specific data
IN:  dummy                 -> dummy


Possible return values:

- E_OK                           -> no error occured

- E_IF_INVALID_LAYER             -> invalid layer
- E_IF_INVALID_SERVICE           -> invalid service identifier
- E_IF_INVALID_PRIMITIVE         -> invalid service primitive
- E_IF_RESOURCE_UNAVAILABLE      -> no resource available
- E_IF_NO_PARALLEL_SERVICES      -> no parallel services allowed
- E_IF_SERVICE_CONSTR_CONFLICT   -> service temporarily not executable
- E_IF_SERVICE_NOT_SUPPORTED     -> service not supported in subset
- E_IF_SERVICE_NOT_EXECUTABLE    -> service not executable

- E_IF_NO_CNTRL_RES              -> controller does not respond  (CMI_TIMEOUT)
- E_IF_INVALID_DATA_SIZE         -> not enough CMI memory available for REQ or RES
- E_IF_INVALID_VERSION           -> invalid version (only PROFDI-IF)
- E_IF_INVALID_PARAMETER         -> invalid parameter in REQ or RES
- E_IF_PAPI_NOT_INITIALIZED      -> API not initialized
----------------------------------------------------------------------------*/
;



FUNCTION extern INT16 CALL_CONV profi_rtx_rcv_con_ind
         (
          OUT   T_PROFI_SERVICE_DESCR * pSdb,
          OUT   VOID                  * pData,
          INOUT USIGN16               * pDataLength
         )

/*----------------------------------------------------------------------------
FUNCTIONAL_DESCRIPTION

This function is used to receive a Service-Indication or a Service-Confirmation
via PROFIBUS WinXP/Win2K RTAPI from the PROFIBUS controller.


OUT:    pSdb             -> pointer to SERVICE-DESCRIPTION-BLOCK
OUT:    pData            -> pointer to data buffer
INOUT:  pDataLength      -> IN:   length of data buffer
                            OUT:  length of received data
Possible return values:

- CON_IND_RECEIVED          -> a confirmation or indication has been received
- NO_CON_IND_RECEIVED       -> no confirmation or indication has been received

- E_IF_FATAL_ERROR          -> unrecoverable error in PROTOCOL SW
- E_IF_INVALID_DATA_SIZE    -> size of data block provided not sufficient
- E_IF_PAPI_NOT_INITIALIZED -> API not initialized
- E_IF_OS_ERROR             -> OS error
----------------------------------------------------------------------------*/
;


FUNCTION extern INT16 CALL_CONV profi_rtx_set_data
        (
          IN  USIGN8    DataId,
          IN  USIGN16   Offset,
          IN  USIGN16   DataLength,
          IN  VOID    * pData
        )

/*-----------------------------------------------------------------------------
FUNCTIONAL_DESCRIPTION

This function is used to write data to CMI data area via PROFIBUS WinXP/Win2K RTAPI

IN:   DataId         -> data image identifier
                         - ID_DP_SLAVE_IO_IMAGE     (DPM: image for slave io data)

IN:   Offset         -> write at offset in data image
IN:   DataLength     -> length of  data to write
IN:   pData          -> pointer to data to write


possible return values:
- E_OK                          -> OK
- E_IF_SERVICE_CONSTR_CONFLICT  -> service not executable at time
- E_IF_SERVICE_NOT_SUPPORTED    -> service not supported
- E_IF_INVALID_DATA_SIZE        -> invalid user data size
- E_IF_PAPI_NOT_INITIALIZED     -> API not initialized
- E_IF_INVALID_DP_STATE         -> DP not in operate mode

-----------------------------------------------------------------------------*/
;



FUNCTION extern INT16 CALL_CONV profi_rtx_get_data
        (
          IN     USIGN8     DataId,
          IN     USIGN16    Offset,
          INOUT  USIGN16  * pDataLength,
          OUT    VOID     * pData
        )

/*-----------------------------------------------------------------------------
FUNCTIONAL_DESCRIPTION

This function is used to read data from CMI data area via PROFIBUS WinXP/Win2K RTAPI

IN:    DataId        -> data image identifier
                         - ID_DP_SLAVE_IO_IMAGE        (DPM: image for slave io data)
                         - ID_DP_STATUS_IMAGE          (DPM: image for status data)

IN:    Offset        -> read at offset in data image
INOUT: pDataLength      IN:  length of data buffer
                        OUT: length of received data
OUT:   pData         -> pointer to data buffer

possible return values:
- E_OK                          -> OK
- E_IF_SERVICE_CONSTR_CONFLICT  -> service not executable at time
- E_IF_SERVICE_NOT_SUPPORTED    -> service not supported
- E_IF_INVALID_DATA_SIZE        -> invalid user data size
- E_IF_PAPI_NOT_INITIALIZED     -> API not initialized
- E_IF_INVALID_DP_STATE         -> DP not in operate mode
-----------------------------------------------------------------------------*/
;




FUNCTION extern INT16 CALL_CONV profi_rtx_set_dps_input_data
        (
          IN    USIGN8  * pData,
          IN    USIGN8    DataLength,
          OUT   USIGN8  * pState
        )

/*-----------------------------------------------------------------------------
FUNCTIONAL_DESCRIPTION

This function is used to write DP Slave input data to DPS_SLAVE_INPUT_IMAGE via
PROFIBUS WinXP/Win2K RTAPI

IN:   pData      -> pointer to new input data
IN:   DataLength -> number bytes of input data
OUT:  pState     -> pointer to a status variable for the recent input data status

possible return values:
- E_OK                          -> OK
- E_IF_INVALID_DATA_SIZE        -> data_size does not match the expected input data size
- E_IF_NO_CNTRL_RES             -> timeout controller does not response
- E_IF_PAPI_NOT_INITIALIZED     -> API not initialized

-----------------------------------------------------------------------------*/
;




FUNCTION extern INT16 CALL_CONV profi_rtx_get_dps_input_data
        (
          OUT   USIGN8 * pData,
          INOUT USIGN8 * pDataLength,
          OUT   USIGN8 * pState
        )

/*-----------------------------------------------------------------------------
FUNCTIONAL_DESCRIPTION

This function is used to read data CMI DPS_SLAVE_INPUT_IMAGE via PROFIBUS
WinXP/Win2K RTAPI

OUT:    pData       -> destination buffer for input data
INOUT:  pDataLength -> sizeof destination buffer and number of bytes read
OUT:    pState      -> status of input data if read successfully

possible return values:
- E_OK                          -> OK
- E_IF_INVALID_DATA_SIZE        -> invalid user data size
- E_IF_PAPI_NOT_INITIALIZED     -> API not initialized

-----------------------------------------------------------------------------*/
;





FUNCTION extern INT16 CALL_CONV profi_rtx_get_dps_output_data
        (
          OUT   USIGN8 * pData,
          INOUT USIGN8 * pDataLength,
          OUT   USIGN8 * pState
        )

/*-----------------------------------------------------------------------------
FUNCTIONAL_DESCRIPTION

This function is used to read data from DPS_SLAVE_OUTPUT_IMAGE via PROFIBUS
WinXP/Win2K RTAPI.

OUT:    pData       -> destination buffer for output data
INOUT:  pDataLength -> sizeof destination buffer and number of bytes read
OUT:    pState      -> status of output data if read successfully

possible return values:
- E_OK                          -> OK
- E_IF_INVALID_DATA_SIZE        -> invalid user data size
- E_IF_PAPI_NOT_INITIALIZED     -> API not initialized

-----------------------------------------------------------------------------*/
;




FUNCTION extern INT16 CALL_CONV profi_rtx_get_versions
         (
           OUT CSTRING * pPapiVersion,
           OUT CSTRING * pFirmwareVersion
         )
/*----------------------------------------------------------------------------
FUNCTIONAL_DESCRIPTION

This function is used to get the vesrion strings of PAPI and firmware.

OUT:    pPapiVersion      -> data buffer for PAPI version string
OUT:    pFirmwareVersion  -> data buffer for firmware version string

NOTE: There must be at least 100 Bytes (VERSION_STRING_LENGTH) free space for
      each INOUT buffer.

Possible return values:
- E_OK

-----------------------------------------------------------------------------*/
;



FUNCTION extern INT16 CALL_CONV profi_rtx_get_serial_device_number
         (
           OUT USIGN32 * pSerialDeviceNumber
         )
/*----------------------------------------------------------------------------
FUNCTIONAL_DESCRIPTION

This function is used to get the serial device number of the PROFIBUS
controller

OUT:  pSerialDeviceNumber -> serial device number

Possible return values:
- E_OK
- E_IF_PAPI_NOT_INITIALIZED      -> API not initialized

-----------------------------------------------------------------------------*/
;




FUNCTION extern INT16 CALL_CONV profi_rtx_get_last_error(VOID)

/*----------------------------------------------------------------------------
FUNCTIONAL_DESCRIPTION

This function is returns the additional last error code for INTERFACE-ERRORs
controller

Possible return values:
- additional last error code

-----------------------------------------------------------------------------*/
;

#endif


#ifndef UNDER_RTSS
#ifdef  WIN32
/**********************************************************************************/
/* extern function declarations using for enhanced WinNT/Win2K PROFIBUS Interface */
/**********************************************************************************/


FUNCTION extern HANDLE CALL_CONV profi_open_basic_management
         (
           IN USIGN8 Board,
           IN USIGN8 Channel,
           IN INT32  DesiredAccess
         )
/*----------------------------------------------------------------------------
FUNCTIONAL_DESCRIPTION

This function is used to initialize the enhanced mode of the PROFIBUS API.

It opens the the BASIC MANAGEMENT DEVICE and updates the PROFIBUS firmware onto
PROFIBUS controller if necessary.

IN:  Board           -> number of the PROFIBUS board (0..9)
IN:  Channel         -> channel number
IN:  DesiredAccess   -> GENERIC_READ  specifies the read access to the device
                        GENERIC_WRITE specifies the write access to the device

Possible return values:
- open handle of BASIC MANAGEMENT DEVICE if function succeeds successfully
- INVALID_HANDLE_VALUE  if function fails

-----------------------------------------------------------------------------*/
;



FUNCTION extern HANDLE CALL_CONV profi_open
         (
           IN HANDLE  hBasicMgmtDevice,
           IN INT32   DeviceType,
           IN USIGN32 Index,
           IN INT32   DesiredAccess
         )
/*----------------------------------------------------------------------------
FUNCTIONAL_DESCRIPTION

This function is used to open a PROFIBUS device specified by 'device_type'.

IN:  hBasicMgmtDevice  -> basic management device handle
IN:  DeviceType        -> type of the device to open
                          DEVICE_DP_MANAGEMENT  -> DP management device
                          DEVICE_DP_SERVICE     -> DP service device
                          DEVICE_DP_SLAVE_DATA  -> DP slave data device
                          DEVICE_DP_MSAC        -> DP master slave acyclic device
                          DEVICE_FDL_MANAGEMENT -> FDL management device
                          DEVICE_FDL_SAP        -> FDL SAP device
                          DEVICE_FMS_MANAGEMENT -> FMS management device
                          DEVICE_FMS_CR         -> FMS CR device
IN:  Index             -> index of the device to open
                          1..128           DP service-, DP slave data- and DP/V1 service devices
                          0..63,DEFAUT_SAP FDL SAP device
                          1..64            FMS CR device
IN:  DesiredAccess     -> GENERIC_READ  specifies the read access to the device
                          GENERIC_WRITE specifies the write access to the device

Possible return values:
- open handle of the specified device if function succeeds successfuly
- INVALID_HANDLE_VALUE  if function fails

-----------------------------------------------------------------------------*/
;



FUNCTION extern BOOL CALL_CONV profi_close
         (
           IN HANDLE hDevice
         )
/*----------------------------------------------------------------------------
FUNCTIONAL_DESCRIPTION

This function is used to close a device opened with 'profi_open_basic_management'
function or 'profi_open' function.

IN:  hDevice   -> handle of the device to close

Possible return values:
- TRUE        -> device is closed
- FALSE       -> device can not be closed

-----------------------------------------------------------------------------*/
;



FUNCTION extern INT16 CALL_CONV profi_read_service
         (
           IN    HANDLE                  hDevice,
           OUT   T_PROFI_SERVICE_DESCR * pSdb,
           OUT   VOID                  * pData,
           INOUT USIGN16               * pDataLength
         )
/*----------------------------------------------------------------------------
FUNCTIONAL_DESCRIPTION

This function is used to receive a Service-Indication or a Service-Confirmation
from a PROFIBUS service device.

IN:     hDevice           -> device handle
OUT:    pSdb              -> pointer to SERVICE-DESCRIPTION-BLOCK
OUT:    pData             -> pointer to data buffer
INOUT:  pDatalen          -> IN:   length of data buffer
                             OUT:  length of received data
Possible return values:

- CON_IND_RECEIVED                 -> a confirmation or indication has been received
- NO_CON_IND_RECEIVED              -> no confirmation or indication has been received
- E_IF_NO_CNTRL_RES                -> controller does not respond
- E_IF_FATAL_ERROR                 -> unrecoverable error in PROTOCOL SW
- E_IF_CMI_ERROR                   -> serious CMI error
- E_IF_INVALID_DATA_SIZE           -> size of data block provided not sufficient
- E_IF_OS_ERROR                    -> NT system error
- E_IF_RESOURCE_UNAVAILABLE        -> no resource available
-----------------------------------------------------------------------------*/
;




FUNCTION extern INT16 CALL_CONV profi_write_service
         (
           IN HANDLE                  hDevice,
           IN T_PROFI_SERVICE_DESCR * pSdb,
           IN VOID                  * pData
         )
/*----------------------------------------------------------------------------
FUNCTIONAL_DESCRIPTION

This function is used to send a Service-Request or a Service-Response
to a PROFIBUS service device.

IN:  hDevice                  -> device handle
IN:  pSdp                     -> pointer to SERVICE-DESCRIPTION-BLOCK
IN:  pData                    -> pointer to service specific data


Possible return values:

- E_OK                           -> no error occured

- E_IF_INVALID_LAYER             -> invalid layer
- E_IF_INVALID_SERVICE           -> invalid service identifier
- E_IF_INVALID_PRIMITIVE         -> invalid service primitive
- E_IF_RESOURCE_UNAVAILABLE      -> no resource available
- E_IF_NO_PARALLEL_SERVICES      -> no parallel services allowed
- E_IF_SERVICE_CONSTR_CONFLICT   -> service temporarily not executable
- E_IF_SERVICE_NOT_SUPPORTED     -> service not supported in subset
- E_IF_SERVICE_NOT_EXECUTABLE    -> service not executable

- E_IF_NO_CNTRL_RES              -> controller does not respond  (CMI_TIMEOUT)
- E_IF_INVALID_DATA_SIZE         -> not enough CMI memory available for REQ or RES
- E_IF_INVALID_PARAMETER         -> invalid wrong parameter in REQ or RES
- E_IF_CMI_ERROR                 -> serious CMI error
- E_IF_INVALID_CMI_CALL          -> invalid CMI call
- E_IF_OS_ERROR                  -> NT system error

-----------------------------------------------------------------------------*/
;



FUNCTION extern INT16 CALL_CONV profi_read_multi
         (
           OUT   T_PROFI_SERVICE_DESCR * pSdb,
           OUT   VOID                  * pData,
           INOUT USIGN16               * pDataLength,
           IN    USIGN16                 NrOfHandles,
           IN    HANDLE                * phDevices
          )
/*----------------------------------------------------------------------------
FUNCTIONAL_DESCRIPTION

This function is used to receive a Service-Indication or a Service-Confirmation
from one ore more PROFIBUS service devices.

OUT:    pSdb           -> pointer to SERVICE-DESCRIPTION-BLOCK
OUT:    pData          -> pointer to data buffer
INOUT:  pDataLength    -> IN:   length of data buffer
                          OUT:  length of received data
IN:     NrOfHandles    -> number of device handles
IN:     phDevices      -> pointer to list of device handles

Possible return values:

- CON_IND_RECEIVED                 -> a confirmation or indication has been received
- NO_CON_IND_RECEIVED              -> no confirmation or indication has been received
- E_IF_NO_CNTRL_RES                -> controller does not respond
- E_IF_FATAL_ERROR                 -> unrecoverable error in PROTOCOL SW
- E_IF_CMI_ERROR                   -> serious CMI error
- E_IF_INVALID_DATA_SIZE           -> size of data block provided not sufficient
- E_IF_OS_ERROR                    -> NT system error
- E_IF_RESOURCE_UNAVAILABLE        -> no resource available

-----------------------------------------------------------------------------*/
;




FUNCTION extern INT16 CALL_CONV profi_read_data
         (
           IN    HANDLE    hDevice,
           OUT   VOID    * pData,
           OUT   USIGN16 * pDataLength
         )
/*----------------------------------------------------------------------------
FUNCTIONAL_DESCRIPTION

This function is used to read DP-Slave-I/O-Data from a DP SLAVE DATA DEVICE.

IN:     hDevice           -> device handle
OUT:    pData             -> pointer to data buffer
OUT:    pDataLength       -> IN:   length of data buffer
                             OUT:  length of received data

Possible return values:
- E_OK                             -> no error occured
- E_IF_INVALID_DP_STATE            -> DP is not in operational state
- E_IF_SLAVE_ERROR                 -> no valid communication with DP-Slave
- E_IF_SLAVE_DIAG_DATA             -> new DP diagnostics data available
- E_IF_INVALID_CMI_CALL            -> invalid offset inside data image
- E_IF_CMI_ERROR                   -> serious CMI error
- E_IF_INVALID_DATA_SIZE           -> size of data block provided not sufficient
- E_IF_SERVICE_CONSTR_CONFLICT     -> service not executable at time
- E_IF_OS_ERROR                    -> NT system error

-----------------------------------------------------------------------------*/
;



FUNCTION extern INT16 CALL_CONV profi_write_data
         (
           IN HANDLE    hDevice,
           IN VOID    * pData,
           IN USIGN16   DataLength
         )
/*----------------------------------------------------------------------------
FUNCTIONAL_DESCRIPTION

This function is used to write DP-Slave-I/O-Data to a DP SLAVE DATA DEVICE.

IN:  hDevice            -> device handle
IN:  pData              -> pointer to data buffer
IN:  DataLength         -> length of data to write

Possible return values:
- E_OK                             -> no error occured
- E_IF_INVALID_DP_STATE            -> DP is not in operational state
- E_IF_SLAVE_ERROR                 -> no valid communication with DP-Slave
- E_IF_SLAVE_DIAG_DATA             -> new DP diagnostics data available
- E_IF_INVALID_CMI_CALL            -> invalid offset inside data image
- E_IF_CMI_ERROR                   -> serious CMI error
- E_IF_INVALID_DATA_SIZE           -> size of data block provided not sufficient
- E_IF_SERVICE_CONSTR_CONFLICT     -> service not executable at time
- E_IF_OS_ERROR                    -> NT system error

-----------------------------------------------------------------------------*/
;




FUNCTION extern INT16 CALL_CONV profi_read_dps_data
         (
           IN    HANDLE   hDevice,
           OUT   USIGN8 * pData,
           INOUT USIGN8 * pDataLength,
           OUT   USIGN8 * pState
         )
/*----------------------------------------------------------------------------
FUNCTIONAL_DESCRIPTION

This function is used to read data from CMI DPS_SLAVE_INPUT_IMAGE or
DPS_SLAVE_OUTPUT_IMAGE.

IN:     hDevice     -> device handle
OUT:    pData       -> destination buffer for input data
INOUT:  pDataLength -> IN:  length of destination buffer
                       OUT: number of bytes read
OUT:    pState      -> status of input or output data if read or write was successfully


Possible return values:
- E_OK                             -> no error occured
- E_IF_INVALID_CMI_CALL            -> invalid offset inside data image
- E_IF_CMI_ERROR                   -> serious CMI error
- E_IF_INVALID_DATA_SIZE           -> size of data block provided not sufficient
- E_IF_SERVICE_CONSTR_CONFLICT     -> service not executable at time
- E_IF_OS_ERROR                    -> NT system error

-----------------------------------------------------------------------------*/
;



FUNCTION extern INT16 CALL_CONV profi_write_dps_data
        (
          IN    HANDLE    hDevice,
          IN    USIGN8  * pData,
          IN    USIGN8    DataLength,
          OUT   USIGN8  * pState
        )

/*-----------------------------------------------------------------------------
FUNCTIONAL_DESCRIPTION

This function is used to write DP-Slave input data to DPS_SLAVE_INPUT_IMAGE

IN:   hDevice    -> device handle
IN:   pData      -> pointer to new input data
IN:   DataLength -> number bytes of input data
OUT:  pState     -> pointer to a status variable for the recent input data status

possible return values:
- E_OK                          -> OK
- E_IF_INVALID_DATA_SIZE        -> data_size does not match the expected input data size
- E_IF_OS_ERROR                 -> NT system error

-----------------------------------------------------------------------------*/
;



FUNCTION extern BOOL CALL_CONV profi_get_cntrl_info
         (
           IN  USIGN8   Board,
           OUT char*    pFirmwareVersion,
           OUT USIGN32* pSerialDeviceNumber
         )
/*----------------------------------------------------------------------------
FUNCTIONAL_DESCRIPTION

This function is used to get the version of the firmware and the serial
device number of PROFIBUS controller.

IN:     Board                -> board number
OUT:    pFirmwareVersion     -> data buffer for firmware version string
OUT:    pSerialDeviceNumber  -> serial device number

NOTE: There must be at least 100 Bytes (VERSION_STRING_LENGTH) free space for
      firmware version buffer.

Possible return values:
- TRUE   -> function returns sucessfully
- FALSE  -> function returns not successfully

-----------------------------------------------------------------------------*/
;



FUNCTION extern BOOL CALL_CONV profi_set_timeout
         (
           IN HANDLE  hBasicMgmtDevice,
           IN USIGN32 ReadTimeout,
           IN USIGN32 WriteTimeout
         )
/*----------------------------------------------------------------------------
FUNCTIONAL_DESCRIPTION

This function is used to set send and receive TIMEOUTs for SEND/RECEIVE interface
functions

IN:  hBasicMgmtDevice  -> basic management device handle
IN:  ReadTimeout       -> receive timeout in ms (WAIT_FOREVER for infinite wait)
IN:  WriteTimeout      -> send timeout in ms (WAIT_FOREVER for infinite wait)

Possible return values:
- TRUE   -> function returns sucessfully
- FALSE  -> function returns not successfully

-----------------------------------------------------------------------------*/
;



FUNCTION extern BOOL CALL_CONV profi_get_timeout
         (
           IN  HANDLE   hBasicMgmtDevice,
           OUT USIGN32* pReadTimeout,
           OUT USIGN32* pWriteTimeout
         )
/*----------------------------------------------------------------------------
FUNCTIONAL_DESCRIPTION

This function is used to get the set send and receive TIMEOUTs for SEND/RECEIVE
interface functions

IN:   hBasicMgmtDevice  -> basic management device handle
OUT:  pReadTimeout      -> pointer to receive timeout in ms (WAIT_FOREVER for infinite wait)
OUT:  pWriteTimeout     -> pointer to send timeout in ms (WAIT_FOREVER for infinite wait)

Possible return values:
- TRUE   -> function returns sucessfully
- FALSE  -> function returns not successfully

-----------------------------------------------------------------------------*/
;



FUNCTION extern BOOL CALL_CONV profi_set_queue_size
         (
           IN HANDLE  hBasicMgmtDevice,
           IN USIGN32 QueueSize
         )
/*----------------------------------------------------------------------------
FUNCTIONAL_DESCRIPTION

This function is used to set the max. receive queue size for the PROFIBUS driver.

IN:  hBasicMgmtDevice  -> basic management device handle
IN:  QueueSize         -> max. receive queue size

Possible return values:
- TRUE   -> function returns sucessfully
- FALSE  -> function returns not successfully

-----------------------------------------------------------------------------*/
;



FUNCTION extern BOOL CALL_CONV profi_get_queue_size
         (
           IN  HANDLE   hBasicMgmtDevice,
           OUT USIGN32* pQueueSize
         )
/*----------------------------------------------------------------------------
FUNCTIONAL_DESCRIPTION

This function is used to get the set max. receive queue size for the PROFIBUS driver.

IN:  hBasicMgmtDevice  -> basic management device handle
OUT: pQueueSize        -> pointer to max. receive queue size

Possible return values:
- TRUE   -> function returns sucessfully
- FALSE  -> function returns not successfully

-----------------------------------------------------------------------------*/
;




FUNCTION extern BOOL CALL_CONV profi_get_overrun_count
         (
           IN  HANDLE   hBasicMgmtDevice,
           OUT USIGN32* pOverrunCount
         )
/*----------------------------------------------------------------------------
FUNCTIONAL_DESCRIPTION


IN:  hBasicMgmtDevice  -> basic management device handle
OUT: pOverrunCount     -> pointer to overrun counts

Possible return values:
- TRUE   -> function returns sucessfully
- FALSE  -> function returns not successfully

-----------------------------------------------------------------------------*/
;

#endif
#endif
#endif

#ifdef __cplusplus
 }
#endif



#pragma warning (disable : 4103)     /* used #pragma pack to reset alignment */
#ifdef WIN32
#pragma pack(pop)
#else
#pragma pack()
#endif
#pragma warning (default : 4103)


#endif

