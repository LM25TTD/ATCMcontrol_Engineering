/*****************************************************************************/
/*                                                                           */
/*  Filename    : PB_DPS.H                                                   */
/*  Version     : 5.22.0.00.release                                          */
/*  Date        : 26-February-1999                                           */
/*                                                                           */
/*  Description : This file contains the global defines and types of DPS     */
/*                                                                           */
/*****************************************************************************/

#ifndef __PB_DPS__
#define __PB_DPS__


#pragma warning (disable : 4103)    /* used #pragma pack to change alignment */
#pragma pack(2)
#pragma warning (default : 4103)


/****************************************************************************/
/*** DEFINES ****************************************************************/
/****************************************************************************/

/*--- COMMON DP SLAVE CONSTANTS --------------------------------------------*/

#define DPS_KBAUD_9_6                0x00
#define DPS_KBAUD_19_2               0x01
#define DPS_KBAUD_93_75              0x02
#define DPS_KBAUD_187_5              0x03
#define DPS_KBAUD_500                0x04
#define DPS_KBAUD_RESERVED           0x05
#define DPS_KBAUD_1500               0x06
#define DPS_MBAUD_1_5                0x06
#define DPS_KBAUD_3000               0x07
#define DPS_MBAUD_3                  0x07
#define DPS_KBAUD_6000               0x08
#define DPS_MBAUD_6                  0x08
#define DPS_KBAUD_12000              0x09
#define DPS_MBAUD_12                 0x09
#define DPS_KBAUD_31_25              0x0A
#define DPS_KBAUD_45_45              0x0B
#define DPS_NO_BUS_TRAFFIC           0xFF

#define DPS_MIN_SERVICE_IF_LEN       512 /* required service IF size by DPS */

#define DPS_DEFAULT_MIN_TSDR         11

#define DPS_DEFAULT_IDENT_NUMBER     0x0000
#define DPS_USER_WATCHDOG_DISABLED   0

#define DPS_NON_VOLATILE_SLAVE_ADD   0xFF
#define DPS_DEFAULT_SLAVE_ADD        DP_DEFAULT_SLAVE_ADDRESS

#define DPS_MIN_SLAVE_DIAG_LEN       DP_MIN_SLAVE_DIAG_LEN
#define DPS_MAX_SLAVE_DIAG_LEN       DP_MAX_SLAVE_DIAG_DATA_LEN
#define DPS_MIN_PRM_DATA_LEN         7
#define DPS_MAX_PRM_DATA_LEN         DP_MAX_PRM_DATA_LEN
#define DPS_MIN_CFG_DATA_LEN         1
#define DPS_MAX_CFG_DATA_LEN         DP_MAX_CFG_DATA_LEN
#define DPS_MIN_SSA_DATA_LEN         4


/****************************************************************************/
/*** DPS SERVICE CODES ******************************************************/
/****************************************************************************/

/*--- DPS_SUBTASK ----------------------------------------------------------*/

#define DPS_SUBTASK                  0xE0

#define DPS_SUBTASK_MSG              0x00
#define DPS_SUBTASK_USIF             0x20
#define DPS_SUBTASK_MSAC2            0x40

/*--- DPS_STATE_MACHINE ----------------------------------------------------*/

#define DPS_STATE_MACHINE            0x18

#define DPS_STATE_MACHINE_0          0x00
#define DPS_STATE_MACHINE_1          0x08
#define DPS_STATE_MACHINE_2          0x10
#define DPS_STATE_MACHINE_3          0x08

/*--- DPS_SUBTASK / DPS_STATE_MACHINE --------------------------------------*/

#define DPS_SUBTASK_STATE_MACHINE    (DPS_SUBTASK | DPS_STATE_MACHINE)

#define DPS_SM_MSG_MAIN              (DPS_SUBTASK_MSG | DPS_STATE_MACHINE_0)

#define DPS_SM_USIF_MAIN             (DPS_SUBTASK_USIF | DPS_STATE_MACHINE_0)
#define DPS_SM_USIF_SLAVE            (DPS_SUBTASK_USIF | DPS_STATE_MACHINE_1)
#define DPS_SM_USIF_STATE            (DPS_SUBTASK_USIF | DPS_STATE_MACHINE_2)

#define DPS_SM_MSAC2_MAIN            (DPS_SUBTASK_MSAC2 | DPS_STATE_MACHINE_0)

/*--- DPS_SERVICE_CODE -----------------------------------------------------*/

#define DPS_INIT_SLAVE               (DPS_SM_MSG_MAIN | 0x01)
#define DPS_EXIT_SLAVE               (DPS_SM_MSG_MAIN | 0x02)

#define DPS_EXCEPTION                (DPS_SM_MSG_MAIN | 0x07)

#define DPS_CHK_CFG                  (DPS_SM_USIF_MAIN | 0x01)
#define DPS_SET_PRM                  (DPS_SM_USIF_MAIN | 0x02)
#define DPS_SET_SLAVE_ADD            (DPS_SM_USIF_MAIN | 0x03)

#define DPS_SLAVE_DIAG               (DPS_SM_USIF_SLAVE | 0x01)

#define DPS_GET_STATUS               (DPS_SM_USIF_STATE | 0x01)


/****************************************************************************/
/*** DPS SERVICE CONSTANTS **************************************************/
/****************************************************************************/

/*--- DPS STATUS -----------------------------------------------------------*/

#define DPS_STATE_IDLE                    0xFF
#define DPS_STATE_WAIT_PRM                0x00
#define DPS_STATE_WAIT_CFG                0x01
#define DPS_STATE_DATA_EXCHANGE           0x02
#define DPS_STATE_CONTROLLER_ERROR        0x03

/*--- DPS DIAGNOSTIC BITS --------------------------------------------------*/

#define DPS_DIAG_BIT_EXT_DIAG             0x01
#define DPS_DIAG_BIT_STAT_DIAG            0x02
#define DPS_DIAG_BIT_EXT_DIAG_OVERFLOW    0x04
#define DPS_DIAG_BIT_WAIT_UNTIL_FETCHED   0x80

#define DPS_DIAG_BIT_STATUS_MASK          (DPS_DIAG_BIT_EXT_DIAG |           \
                                           DPS_DIAG_BIT_STAT_DIAG |          \
                                           DPS_DIAG_BIT_EXT_DIAG_OVERFLOW)

#define DPS_DIAG_BIT_MASK                 (DPS_DIAG_BIT_EXT_DIAG |           \
                                           DPS_DIAG_BIT_STAT_DIAG |          \
                                           DPS_DIAG_BIT_EXT_DIAG_OVERFLOW |  \
                                           DPS_DIAG_BIT_WAIT_UNTIL_FETCHED)

/*--- DPS SPC3 SPECIAL USR_PRM_BYTE ----------------------------------------*/

#define DPS_SPC3_USR_PRM_DISABLE_STARTBIT 0x01
#define DPS_SPC3_USR_PRM_DISABLE_STOPBIT  0x02
#define DPS_SPC3_USR_PRM_WD_BASE_1MS      0x04

#define DPS_SPC3_USR_PRM_MASK             (DPS_SPC3_USR_PRM_DISABLE_STARTBIT | \
                                           DPS_SPC3_USR_PRM_DISABLE_STOPBIT |  \
                                           DPS_SPC3_USR_PRM_WD_BASE_1MS)

/*--- DPS INPUT / OUTPUT STATUS --------------------------------------------*/

#define DPS_INPUT_STATE_FREEZE_ENABLED    0x01
#define DPS_INPUT_STATE_FREEZE_COMMAND    0x02

#define DPS_OUTPUT_STATE_SYNC_ENABLED     0x01
#define DPS_OUTPUT_STATE_SYNC_COMMAND     0x02
#define DPS_OUTPUT_STATE_CLEAR_DATA       0x04
#define DPS_OUTPUT_STATE_VALID_DATA       0x08
#define DPS_OUTPUT_STATE_NEW_DATA         0x10
#define DPS_OUTPUT_STATE_GLOBAL_CONTROL   0x20




/****************************************************************************/
/*** DPS SERVICE TYPES ******************************************************/
/****************************************************************************/

/*--------------------------------------------------------------------------*/
/*--- DPS USER INTERFACE STRUCTURES ----------------------------------------*/
/*--------------------------------------------------------------------------*/

typedef struct _T_DPS_INPUT_DATA_HEADER
{
  USIGN8    input_data_len;         /* length of DPS_USR input data, 0..244 */
  USIGN8    input_state;      /* status of input image: DPS_INPUT_STATE_xxx */

  USIGN8    input_data [DP_MAX_INPUT_DATA_LEN];

} T_DPS_INPUT_DATA_HEADER;

/*--------------------------------------------------------------------------*/

typedef struct _T_DPS_OUTPUT_DATA_HEADER
{
  USIGN8    output_data_len;     /* length of DP master output data, 0..244 */
  USIGN8    output_state;   /* status of output image: DPS_OUTPUT_STATE_xxx */

  USIGN8    output_data [DP_MAX_OUTPUT_DATA_LEN];

} T_DPS_OUTPUT_DATA_HEADER;

/*--------------------------------------------------------------------------*/


typedef struct _T_DPS_CON_IND
{
  USIGN16   status;

} T_DPS_CON_IND;

/*--------------------------------------------------------------------------*/
/*--- DPS USIF SERVICE STRUCTURES ------------------------------------------*/
/*--------------------------------------------------------------------------*/

typedef struct _T_DPS_INIT_SLAVE_REQ
{
   USIGN8   slave_add; /* 0..125, DPS_DEFAULT_SLAVE_ADD, DPS_NON_VOLATILE_SLAVE_ADD */
   USIGN8   min_tsdr;   /* min. station delay responder, default 0, 11..255 */

   PB_BOOL  auto_cfg_response; /* CFG check by DPS_USR ? PB_FALSE : PB_TRUE */
   PB_BOOL  auto_prm_response; /* PRM check by DPS_USR ? PB_FALSE : PB_TRUE */
   PB_BOOL  auto_startup_inputs;  /* first input values by DPS at startup ? */

   PB_BOOL  sync_mode_supported;     /* activation of DPS operation modes ? */
   PB_BOOL  freeze_mode_supported;
   PB_BOOL  set_slave_add_supported;         /* activation of DPS service ? */

   USIGN8   max_input_data_len;                 /* 0..DP_MAX_INPUT_DATA_LEN */
   USIGN8   max_output_data_len;               /* 0..DP_MAX_OUTPUT_DATA_LEN */
   USIGN8   max_cfg_data_len;                     /* 1..DP_MAX_CFG_DATA_LEN */
   USIGN8   max_usr_prm_data_len;            /* 0..DP_MAX_USER_PRM_DATA_LEN */
   USIGN8   max_ext_diag_data_len;           /* 0..DP_MAX_EXT_DIAG_DATA_LEN */
   USIGN8   max_address_data_len;                 /* 0..DP_MAX_TELEGRAM_LEN */

   USIGN16  ident_number;             /* 0 == IdentNumber (Default) */

   USIGN16  user_watchdog_timeout;   /* WD timeout [1 ms], 0 == WD disabled */

   USIGN8   reserved [4];              /* reserved for extensions, set to 0 */

   USIGN8   cfg_data_len;     /* length of cfg_data, 1..DP_MAX_CFG_DATA_LEN */
   USIGN8   enhanced_init_data_len;    /* reserved for extensions, set to 0 */

   USIGN8   cfg_data [DP_MAX_CFG_DATA_LEN];             /* initial CFG data */
   USIGN8   enhanced_init_data [DPS_MIN_SERVICE_IF_LEN - DP_MAX_CFG_DATA_LEN - 24];

} T_DPS_INIT_SLAVE_REQ;

/*--------------------------------------------------------------------------*/

typedef struct _T_DPS_INIT_SLAVE_CON
{
  USIGN16   status;                                           /* OK, IV, NO */

  INT16     remaining_frame_memory;     /* left memory for telegram buffers */

} T_DPS_INIT_SLAVE_CON;

/*==========================================================================*/

typedef VOID    T_DPS_EXIT_SLAVE_REQ;              /* no request parameters */

/*--------------------------------------------------------------------------*/

typedef struct _T_DPS_EXIT_SLAVE_CON
{
  USIGN16   status;                                                   /* OK */

} T_DPS_EXIT_SLAVE_CON;

/*==========================================================================*/

typedef VOID    T_DPS_GET_STATUS_REQ;              /* no request parameters */

/*--------------------------------------------------------------------------*/

typedef struct _T_DPS_GET_STATUS_CON_IND
{
  USIGN16   status;                                               /* OK, TO */

  USIGN8    slave_state;      /* operation state of DP slave, DPS_STATE_xxx */
  USIGN8    diag_state;   /* diagnostic state of DP slave, DPS_DIAG_BIT_xxx */

  USIGN16   ident_number;               /* PNO ident number of this station */

  USIGN8    number_inputs;                    /* I/O configuration in bytes */
  USIGN8    number_outputs;

  USIGN8    slave_add;              /* current station address, 0..125, 126 */
  USIGN8    non_volatile_slave_add;        /* via Set_Slave_Add set address */

  USIGN8    master_add;                   /* 0..125 or DP_NO_MASTER_ADDRESS */
  USIGN8    baud_rate;  /* DPS_KBAUD_xxx, DPS_MBAUD_xxx, DPS_NO_BUS_TRAFFIC */

  PB_BOOL   sync_enabled;               /* sync mode enabled by DP master ? */
  PB_BOOL   freeze_enabled;           /* freeze mode enabled by DP master ? */
  PB_BOOL   clear_data;              /* DP master in CLEAR operation mode ? */

  PB_BOOL   prm_await_response;   /* waits for DPS_Set_Prm.res from DPS_USR */
  PB_BOOL   cfg_await_response;   /* waits for DPS_Chk_Cfg.res from DPS_USR */
  PB_BOOL   await_startup_inputs;    /* waits for first inputs from DPS_USR */

  USIGN8    reserved [16];       /* reserved for extensions, ignore 0 value */

} T_DPS_GET_STATUS_CON_IND;

/*==========================================================================*/

typedef struct _T_DPS_SLAVE_DIAG_REQ
{
  USIGN8    diag_state;   /* diagnostic state of DP slave, DPS_DIAG_BIT_xxx */

  USIGN8    ext_diag_data_len;               /* 0..DP_MAX_EXT_DIAG_DATA_LEN */
  USIGN8    ext_diag_data [DP_MAX_EXT_DIAG_DATA_LEN];  /* ext_diag_data_len */

} T_DPS_SLAVE_DIAG_REQ;

/*--------------------------------------------------------------------------*/

typedef struct _T_DPS_SLAVE_DIAG_CON
{
  USIGN16   status;                                           /* OK, IV, NO */

} T_DPS_SLAVE_DIAG_CON;

/*==========================================================================*/

typedef struct _T_DPS_CHK_CFG_IND
{
  USIGN16   status;                                                   /* OK */

  USIGN8    cfg_data_len;               /* CFG from DP master, see EN 50170 */
  PB_BOOL   cfg_await_response;    /* the indication has to be acknowledged */

  USIGN8    cfg_data [DP_MAX_CFG_DATA_LEN];                 /* cfg_data_len */

} T_DPS_CHK_CFG_IND;

/*--------------------------------------------------------------------------*/

typedef struct _T_DPS_CHK_CFG_RES
{
  USIGN16   status;                                               /* OK, NO */

} T_DPS_CHK_CFG_RES;

/*==========================================================================*/

typedef struct _T_DPS_SET_PRM_IND
{
  USIGN16   status;                                                   /* OK */

  USIGN8    user_prm_data_len;               /* 0..DP_MAX_USER_PRM_DATA_LEN */
  PB_BOOL   prm_await_response;    /* the indication has to be acknowledged */

  USIGN8    station_status;                                   /* DP_PRM_xxx */

  USIGN8    wd_fact_1;                            /* watch dog time factors */
  USIGN8    wd_fact_2;      /* WD time = wd_fact_1 * wd_fact_2 * [1ms/10ms] */

  USIGN8    min_tsdr;                    /* minimum station delay responder */

  USIGN16   ident_number;                               /* PNO ident number */
  USIGN8    group_ident;                       /* groups for GLOBAL_CONTROL */

  USIGN8    user_prm_data [DP_MAX_USER_PRM_DATA_LEN];  /* user_prm_data_len */

  /* user_prm_data [0]: special SPC3 user PRM byte ->  DPS_SPC3_USR_PRM_xxx */

} T_DPS_SET_PRM_IND;

/*--------------------------------------------------------------------------*/

typedef struct _T_DPS_SET_PRM_RES
{
  USIGN16   status;                                               /* OK, NO */

} T_DPS_SET_PRM_RES;

/*==========================================================================*/

typedef struct _T_DPS_SET_SLAVE_ADD_IND
{
  USIGN16   status;                                                   /* OK */

  USIGN8    rem_slave_data_len;             /* 0..DP_MAX_REM_SLAVE_DATA_LEN */
  USIGN8    new_slave_add;    /* new slave address set by DP master, 0..125 */

  USIGN16   ident_number;                               /* PNO ident_number */

  PB_BOOL   no_add_chg;         /* PB_TRUE: address change after reset only */
                                                      /* rem_slave_data_len */
  USIGN8    rem_slave_data [DP_MAX_REM_SLAVE_DATA_LEN];

} T_DPS_SET_SLAVE_ADD_IND;

/*==========================================================================*/

#pragma warning (disable : 4103)    /* used #pragma pack to reset alignment */
#pragma pack()
#pragma warning (default : 4103)


#endif /* __PB_DPS__ */
