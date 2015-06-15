/*****************************************************************************/
/*                       PROFIBUS WINDOWS NT DRIVERS                         */
/*                                                                           */
/*  Filename    : PB_NTDRV.H                                                 */
/*  Version     : 5.27.0.00.release                                          */
/*  Date        : 30-June-2004                                               */
/*                                                                           */
/*  Description : This file contains the global declarations                 */
/*                to access the PROFIBUS Drivers for Windows NT              */
/*                                                                           */
/*****************************************************************************/

#ifndef _PB_NTDRV_H_
#define _PB_NTDRV_H_

#ifndef CTL_CODE
#include "winioctl.h"
#endif


/*****************************************************************************/
/* Definitions of IO Control codes                                           */
/*****************************************************************************/

#define FILE_DEVICE_PROFIBOARD 0x8000

#define IOCTL_PROFI_CREATE_DP_MANAGEMENT  (ULONG)CTL_CODE(FILE_DEVICE_PROFIBOARD, 0x800, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_PROFI_CREATE_DP_SERVICE     (ULONG)CTL_CODE(FILE_DEVICE_PROFIBOARD, 0x801, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_PROFI_CREATE_DP_SLAVE_DATA  (ULONG)CTL_CODE(FILE_DEVICE_PROFIBOARD, 0x802, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_PROFI_CREATE_FDL_MANAGEMENT (ULONG)CTL_CODE(FILE_DEVICE_PROFIBOARD, 0x803, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_PROFI_CREATE_FDL_SAP        (ULONG)CTL_CODE(FILE_DEVICE_PROFIBOARD, 0x804, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_PROFI_CREATE_FMS_MANAGEMENT (ULONG)CTL_CODE(FILE_DEVICE_PROFIBOARD, 0x805, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_PROFI_CREATE_FMS_CR         (ULONG)CTL_CODE(FILE_DEVICE_PROFIBOARD, 0x806, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_PROFI_CREATE_DP_MSAC        (ULONG)CTL_CODE(FILE_DEVICE_PROFIBOARD, 0x80e, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_PROFI_SET_TIMEOUT           (ULONG)CTL_CODE(FILE_DEVICE_PROFIBOARD, 0x808, METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_PROFI_GET_TIMEOUT           (ULONG)CTL_CODE(FILE_DEVICE_PROFIBOARD, 0x809, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_PROFI_SET_QUEUE_SIZE        (ULONG)CTL_CODE(FILE_DEVICE_PROFIBOARD, 0x80a, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_PROFI_GET_QUEUE_SIZE        (ULONG)CTL_CODE(FILE_DEVICE_PROFIBOARD, 0x80b, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_PROFI_GET_OVERRUN_COUNT     (ULONG)CTL_CODE(FILE_DEVICE_PROFIBOARD, 0x80c, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_PROFI_READ_MULTI            (ULONG)CTL_CODE(FILE_DEVICE_PROFIBOARD, 0x80d, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_PROFI_GET_DATA_IMAGE        (ULONG)CTL_CODE(FILE_DEVICE_PROFIBOARD, 0x80f, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_PROFI_SET_DPS_DATA          (ULONG)CTL_CODE(FILE_DEVICE_PROFIBOARD, 0x810, METHOD_IN_DIRECT, FILE_ANY_ACCESS)

#define IOCTL_PROFI_SET_DP_BITS           (ULONG)CTL_CODE(FILE_DEVICE_PROFIBOARD, 0x811, METHOD_BUFFERED, FILE_WRITE_ACCESS)
#define IOCTL_PROFI_CLEAR_DP_BITS         (ULONG)CTL_CODE(FILE_DEVICE_PROFIBOARD, 0x812, METHOD_BUFFERED, FILE_WRITE_ACCESS)

#define IOCTL_PROFI_CHECK_DEV_CONN        (ULONG)CTL_CODE(FILE_DEVICE_PROFIBOARD, 0x813, METHOD_BUFFERED, FILE_ANY_ACCESS)

/*****************************************************************************/
/* Macros to access for PROFIBUS specific error codes                        */
/*****************************************************************************/

#define PROFI_ERROR_FLAG           0xe0000000

#define CUSTOMER_OK_FLAG           0x20000000                    // Bit 29 set
#define CUSTOMER_ERROR_FLAG        0xe0000000                // Bit 29..31 set


#define PROFI_ERROR(code)           ((code) | PROFI_ERROR_FLAG)
#define PROFI_ERROR_FLAG_SET(code)  ((BOOL) (((code) & PROFI_ERROR_FLAG) != 0) )

#define CUSTOMER_FLAG_SET(code)     ((BOOL) ((code) & CUSTOMER_OK_FLAG))



/*****************************************************************************/
/* Timeout structure and define for infinitive wait                          */
/*****************************************************************************/

#define WAIT_FOREVER ((ULONG)-1)

typedef struct _PROFI_TIMEOUT
{
  ULONG TimeoutRead;
  ULONG TimeoutWrite;
} PROFI_TIMEOUT,T_PROFI_TIMEOUT;


/*****************************************************************************/
/* Structure for data image description                                      */
/*****************************************************************************/

typedef struct _PROFI_DATA_IMAGE_DESCR
{
  UCHAR  imageId;
  USHORT offset;
  UCHAR  bus;
} PROFI_DATA_IMAGE_DESCR,T_PROFI_DATA_IMAGE_DESCR;

/*****************************************************************************/
/* Structure for bit access in DP output data                                */
/*****************************************************************************/

typedef struct _PROFI_DP_BIT_ACCESS
{
    USHORT offset;
    UCHAR  mask;
} PROFI_DP_BIT_ACCESS, T_PROFI_DP_BIT_ACCESS;



/*****************************************************************************/
/* Definitions for system registry access                                    */
/*****************************************************************************/

#define REGPATH_PARAMETER_FROM_HLM      "SYSTEM\\CurrentControlSet\\Services\\PROFIbrd\\Parameters"
#define MAX_SYMBOLIC_LINK_NAME_SIZE     255


/*****************************************************************************/
/* Operation Mode as (DP/FMS-Master or DP-Slave)                             */
/*****************************************************************************/

#define DP_FMS_MASTER_MODE         0x00                    // FMS/DPV1-Master
#define DPV0V1V2_MASTER_MODE       0x01                         // PROFIstack
#define DP_SLAVE_MODE              0x02                           // DP-Slave
#define ANALYZER_MODE              0x03                       // Anayzer-Mode


#endif
