/*****************************************************************************/
/*                     PROFIBUS-TOOLS-INTERFACE                              */
/*                                                                           */
/*  Filename    : PB_TOOLS.H                                                 */
/*  Version     : 5.21.0.00.release                                          */
/*  Date        : 27-February-1998                                           */
/*                                                                           */
/*  Description : This file contains the global function declarations,       */
/*                defines and types of the PROFIBUS-TOOLS-Interface          */
/*****************************************************************************/

#ifndef __PB_TOOLS__
#define __PB_TOOLS__

/****************************************************************************/
/*** DEFINES ****************************************************************/
/****************************************************************************/

/*----- definitions to get default bus parameters --------------------------*/
#define DP_MODE         1
#define FMS_FM7_MODE    2
#define DP_FMS_FM7_MODE 3


/*****************************************************************************/
/* global function declarations                                              */
/*****************************************************************************/


#ifdef __cplusplus
  extern "C" {
#endif



/*----- function prototypes to get default busparameters -------------------*/
#ifdef __PB_DP__
FUNCTION extern PB_BOOL CALL_CONV pbt_get_dp_def_bus_param
    (
    IN  USIGN8                 BaudRate,
    IN  USIGN8                 StationAddr,
    IN  USIGN16                Mode,
    OUT T_DP_BUS_PARA_SET FAR* pBusParameters
    )

/*----------------------------------------------------------------------------
FUNCTIONAL_DESCRIPTION

This function is used to get the default busparameter for DP operation
using ASPC2. (use this function only to version 5.02)

IN:  BaudRate       -> desired baudrate    (see valid baudrates)
IN:  StationAddr    -> desired station address   (0..126)
IN:  Mode:          -> DP_MODE         standalone DP operation
                       DP_FMS_FM7_MODE simultaneous DP/FMS/FM7 operation
OUT: pBusParameters -> pointer to DP bus parameter structure

possible return values:
- PB_TRUE   parameters correctly set
- PB_FALSE  no parameter set available, no parameters set
----------------------------------------------------------------------------*/
;
#endif

#ifdef __PB_FM7__
FUNCTION extern PB_BOOL CALL_CONV  pbt_get_fms_fm7_def_bus_param
    (
    IN  USIGN8                      BaudRate,
    IN  USIGN8                      StationAddr,
    IN  PB_BOOL                     InRingDesired,
    IN  USIGN16                     Mode,
    OUT T_SET_BUSPARAMETER_REQ FAR* pBusParameters
    )

/*----------------------------------------------------------------------------
FUNCTIONAL_DESCRIPTION

This function is used to get the default busparameter for FMS/FM7 operation
using ASPC2. (use this function only to version 5.02)

IN:  BaudRate        -> desired baudrate    (see valid baudrates)
IN:  StationAddr     -> desired station address   (0..126)
IN:  InRingDesired   -> PB_TRUE   active station (master)
                        PB_FALSE  passive station (slave)
IN:  Mode            -> FMS_FM7_MODE    standalone FMS/FM7 operation
                        DP_FMS_FM7_MODE simultaneous DP/FMS/FM7 operation
OUT: bus_param_ptr   -> pointer to FM7 bus parameter structure


possible return values:
- PB_TRUE   parameters correctly set
- PB_FALSE  no parameter set available, no parameters set
----------------------------------------------------------------------------*/
;
#endif

#ifdef __PB_FDL__
FUNCTION extern PB_BOOL CALL_CONV pbt_get_fdlif_def_bus_param
    (
    IN  USIGN8                            BaudRate,
    IN  USIGN8                            StationAddr,
    IN  PB_BOOL                           InRingDesired,
    IN  USIGN16                           Mode,
    OUT T_FDLIF_SET_BUSPARAMETER_REQ FAR* pBusParameters
    )

/*----------------------------------------------------------------------------
FUNCTIONAL_DESCRIPTION

This function is used to get the default busparameter for FDL operation
using ASPC2. (use this function only to version 5.02)

IN:  BaudRate, -> desired baudrate    (see valid baudrates)
IN:  StationAddr, -> desired station address   (0..126)
IN:  InRingDesired -> PB_TRUE   active station (master)
                        PB_FALSE  passive station (slave)
IN:  Mode            -> FMS_FM7_MODE    standalone FMS/FM7 operation
                        DP_MODE         standalone DP operation
                        DP_FMS_FM7_MODE simultaneous DP/FMS/FM7 operation
OUT: pBusParameters  -> pointer to FDLIF bus parameter structure


possible return values:
- PB_TRUE   parameters correctly set
- PB_FALSE  no parameter set available, no parameters set
----------------------------------------------------------------------------*/
;
#endif


#ifdef __PB_FMB__
FUNCTION extern PB_BOOL CALL_CONV pbt_get_fmb_def_bus_param
    (
    IN  USIGN8                          BaudRate,
    IN  USIGN8                          StationAddr,
    IN  PB_BOOL                         InRingDesired,
    IN  USIGN16                         Mode,
    OUT T_FMB_SET_BUSPARAMETER_REQ FAR* pBusParameters
    )

/*----------------------------------------------------------------------------
FUNCTIONAL_DESCRIPTION

This function is used to get the default busparameter for FMB operation
using ASPC2.

IN:  BaudRate        -> desired baudrate    (see valid baudrates)
IN:  StationAddr     -> desired station address   (0..126)
IN:  InRingDesired   -> PB_TRUE   active station (master)
                        PB_FALSE  passive station (slave)
IN:  Mode            -> DP_MODE         standalone DP operation
                        DP_FMS_FM7_MODE simultaneous DP/FMS/FM7 operation
                        FMS_FM7_MODE    standalone FMS/FM7 operation
OUT: pBusParameters  -> pointer to FMB bus parameter structure

possible return values:
- PB_TRUE   parameters correctly set
- PB_FALSE  no parameter set available, no parameters set
----------------------------------------------------------------------------*/
;
#endif



#ifdef __PB_FM7__
FUNCTION extern VOID CALL_CONV ccrl_resrces_init
     (
       IN T_CRL_HDR  FAR* pCrlHdr
     )

/*----------------------------------------------------------------------------
FUNCTIONAL_DESCRIPTION

At first this function has to be called to initialize the internal structures
for calculating the memory requirements.

possible return values:
- NONE

----------------------------------------------------------------------------*/
;




FUNCTION extern USIGN16 CALL_CONV ccrl_resrces_add_entry
     (
       IN    USIGN16                Cr,
       IN    T_CRL_STATIC     FAR*  pCrlStatic,
       OUT   T_FMB_CONFIG_CRL FAR*  pCrlConfig
     )

/*------------------------------------------------------------------------------
FUNCTIONAL_DESCRIPTION

For each CRL entry this function has to be called to evaluate the number of resources.
Two actions are performed by this function. First, it checks the CRL entry.
If the entry is incorrect it tries to correct it. If the entry cannot be corrected
it returns with a negative result. If the entry is OK, this function calculates the
resources. After function return, the output buffer holds the sum of resources that
are needed by all CRL entries that where put into ccrl_resrces_add_entry since last
call of ccrl_resrces_init. The result after the last call of ccrl_resrces_add_entry
this is the number of all needed resources for the whole CRL. This result can be used
as input for the PROFIBUS configuration service.

IN:  Cr                       -> communication reference
IN:  pCrlStatic               -> pointer to static part of the CRL entry
OUT: pCrlConfig               -> pointer to CRL configuraton structure

possible return values:
- E_OK                        -> function executed correctly
- E_FM7_CRL_INVALID_ENTRY     -> invalid entry found in CRL, resources are not
                                 calculated

----------------------------------------------------------------------------- */
;
#endif


#ifdef __cplusplus
 }
#endif


#endif

