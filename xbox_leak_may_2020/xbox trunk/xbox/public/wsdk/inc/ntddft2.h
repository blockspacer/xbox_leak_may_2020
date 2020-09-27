/*++

Copyright (c) 1996-1999 Microsoft Corporation

Module Name:

    ntddft2.h

Abstract:

    This header file defines new IOCTLs for the FTDISK driver to support
    the new FT API.

Author:

    Norbert Kusters 13-July-1996

Notes:

Revision History:

--*/

#ifndef _NTDDFT2_
#define _NTDDFT2_

#if _MSC_VER > 1000
#pragma once
#endif

#include <fttypes.h>

#ifdef __cplusplus
extern "C" {
#endif

//
// The name of the control device for the FT disk driver.
//

#define DD_FT_CONTROL_DEVICE_NAME   L"\\Device\\FtControl"
#define DD_DOS_FT_CONTROL_NAME      L"\\\\.\\FtControl"

//
// Control codes handled by the 'FtControl' device.
//

#define FTCONTROLTYPE   ((ULONG) 'g')

#define FT_CREATE_LOGICAL_DISK                      CTL_CODE(FTCONTROLTYPE, 0, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define FT_BREAK_LOGICAL_DISK                       CTL_CODE(FTCONTROLTYPE, 1, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define FT_ENUMERATE_LOGICAL_DISKS                  CTL_CODE(FTCONTROLTYPE, 2, METHOD_BUFFERED, FILE_READ_ACCESS)
#define FT_QUERY_LOGICAL_DISK_INFORMATION           CTL_CODE(FTCONTROLTYPE, 3, METHOD_BUFFERED, FILE_READ_ACCESS)
#define FT_ORPHAN_LOGICAL_DISK_MEMBER               CTL_CODE(FTCONTROLTYPE, 4, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define FT_REPLACE_LOGICAL_DISK_MEMBER              CTL_CODE(FTCONTROLTYPE, 5, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define FT_QUERY_NT_DEVICE_NAME_FOR_LOGICAL_DISK    CTL_CODE(FTCONTROLTYPE, 6, METHOD_BUFFERED, FILE_READ_ACCESS)
#define FT_INITIALIZE_LOGICAL_DISK                  CTL_CODE(FTCONTROLTYPE, 7, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define FT_QUERY_DRIVE_LETTER_FOR_LOGICAL_DISK      CTL_CODE(FTCONTROLTYPE, 8, METHOD_BUFFERED, FILE_READ_ACCESS)
#define FT_CHECK_IO                                 CTL_CODE(FTCONTROLTYPE, 9, METHOD_BUFFERED, FILE_READ_ACCESS)
#define FT_SET_DRIVE_LETTER_FOR_LOGICAL_DISK        CTL_CODE(FTCONTROLTYPE, 10, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define FT_QUERY_NT_DEVICE_NAME_FOR_PARTITION       CTL_CODE(FTCONTROLTYPE, 12, METHOD_BUFFERED, FILE_READ_ACCESS)
#define FT_CHANGE_NOTIFY                            CTL_CODE(FTCONTROLTYPE, 13, METHOD_BUFFERED, FILE_READ_ACCESS)
#define FT_STOP_SYNC_OPERATIONS                     CTL_CODE(FTCONTROLTYPE, 14, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

//
// Control codes handles by FT logical disks.
//

#define FT_QUERY_LOGICAL_DISK_ID                    CTL_CODE(FTCONTROLTYPE, 100, METHOD_BUFFERED, FILE_READ_ACCESS)
#define FT_CREATE_PARTITION_LOGICAL_DISK            CTL_CODE(FTCONTROLTYPE, 101, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

//
// Input parameter for FT_CREATE_LOGICAL_DISK.
//

typedef struct _FT_CREATE_LOGICAL_DISK_INPUT {
    FT_LOGICAL_DISK_TYPE    LogicalDiskType;
    USHORT                  NumberOfMembers;
    USHORT                  ConfigurationInformationSize;
    FT_LOGICAL_DISK_ID      MemberArray[1];
} FT_CREATE_LOGICAL_DISK_INPUT, *PFT_CREATE_LOGICAL_DISK_INPUT;

//
// Output parameter for FT_CREATE_LOGICAL_DISK.
//

typedef struct _FT_CREATE_LOGICAL_DISK_OUTPUT {
    FT_LOGICAL_DISK_ID  NewLogicalDiskId;
} FT_CREATE_LOGICAL_DISK_OUTPUT, *PFT_CREATE_LOGICAL_DISK_OUTPUT;

//
// Input parameter for FT_BREAK_LOGICAL_DISK.
//

typedef struct _FT_BREAK_LOGICAL_DISK_INPUT {
    FT_LOGICAL_DISK_ID  RootLogicalDiskId;
} FT_BREAK_LOGICAL_DISK_INPUT, *PFT_BREAK_LOGICAL_DISK_INPUT;

//
// Output parameter for FT_ENUMERATE_LOGICAL_DISKS.
//

typedef struct _FT_ENUMERATE_LOGICAL_DISKS_OUTPUT {
    ULONG               NumberOfRootLogicalDisks;
    ULONG               Reserved;
    FT_LOGICAL_DISK_ID  RootLogicalDiskIds[1];
} FT_ENUMERATE_LOGICAL_DISKS_OUTPUT, *PFT_ENUMERATE_LOGICAL_DISKS_OUTPUT;

//
// Input parameter for FT_QUERY_LOGICAL_DISK_INFORMATION.
//

typedef struct _FT_QUERY_LOGICAL_DISK_INFORMATION_INPUT {
    FT_LOGICAL_DISK_ID  LogicalDiskId;
} FT_QUERY_LOGICAL_DISK_INFORMATION_INPUT, *PFT_QUERY_LOGICAL_DISK_INFORMATION_INPUT;

//
// Output parameter for FT_QUERY_LOGICAL_DISK_INFORMATION.
//

typedef struct _FT_QUERY_LOGICAL_DISK_INFORMATION_OUTPUT {
    FT_LOGICAL_DISK_TYPE    LogicalDiskType;
    LONGLONG                VolumeSize;
    USHORT                  NumberOfMembers;
    USHORT                  ConfigurationInformationSize;
    USHORT                  StateInformationSize;
    USHORT                  Reserved;
    FT_LOGICAL_DISK_ID      MemberArray[1];
} FT_QUERY_LOGICAL_DISK_INFORMATION_OUTPUT, *PFT_QUERY_LOGICAL_DISK_INFORMATION_OUTPUT;

//
// Input parameter for FT_ORPHAN_LOGICAL_DISK_MEMBER.
//

typedef struct _FT_ORPHAN_LOGICAL_DISK_MEMBER_INPUT {
    FT_LOGICAL_DISK_ID  LogicalDiskId;
    USHORT              MemberNumberToOrphan;
    USHORT              Reserved[3];
} FT_ORPHAN_LOGICAL_DISK_MEMBER_INPUT, *PFT_ORPHAN_LOGICAL_DISK_MEMBER_INPUT;

//
// Input parameter for FT_REPLACE_LOGICAL_DISK_MEMBER.
//

typedef struct _FT_REPLACE_LOGICAL_DISK_MEMBER_INPUT {
    FT_LOGICAL_DISK_ID  LogicalDiskId;
    USHORT              MemberNumberToReplace;
    USHORT              Reserved[3];
    FT_LOGICAL_DISK_ID  NewMemberLogicalDiskId;
} FT_REPLACE_LOGICAL_DISK_MEMBER_INPUT, *PFT_REPLACE_LOGICAL_DISK_MEMBER_INPUT;

//
// Output parameter for FT_REPLACE_LOGICAL_DISK_MEMBER.
//

typedef struct _FT_REPLACE_LOGICAL_DISK_MEMBER_OUTPUT {
    FT_LOGICAL_DISK_ID  NewLogicalDiskId;
} FT_REPLACE_LOGICAL_DISK_MEMBER_OUTPUT, *PFT_REPLACE_LOGICAL_DISK_MEMBER_OUTPUT;

//
// Input parameter for FT_QUERY_NT_DEVICE_NAME_FOR_LOGICAL_DISK.
//

typedef struct _FT_QUERY_NT_DEVICE_NAME_FOR_LOGICAL_DISK_INPUT {
    FT_LOGICAL_DISK_ID  RootLogicalDiskId;
} FT_QUERY_NT_DEVICE_NAME_FOR_LOGICAL_DISK_INPUT, *PFT_QUERY_NT_DEVICE_NAME_FOR_LOGICAL_DISK_INPUT;

//
// Output parameter for FT_QUERY_NT_DEVICE_NAME_FOR_LOGICAL_DISK.
//

typedef struct _FT_QUERY_NT_DEVICE_NAME_FOR_LOGICAL_DISK_OUTPUT {
    USHORT  NumberOfCharactersInNtDeviceName;
    WCHAR   NtDeviceName[1];
} FT_QUERY_NT_DEVICE_NAME_FOR_LOGICAL_DISK_OUTPUT, *PFT_QUERY_NT_DEVICE_NAME_FOR_LOGICAL_DISK_OUTPUT;

//
// Input parameter for FT_INITIALIZE_LOGICAL_DISK.
//

typedef struct _FT_INITIALIZE_LOGICAL_DISK_INPUT {
    FT_LOGICAL_DISK_ID  RootLogicalDiskId;
    BOOLEAN             RegenerateOrphans;
} FT_INITIALIZE_LOGICAL_DISK_INPUT, *PFT_INITIALIZE_LOGICAL_DISK_INPUT;

//
// Input parameter for FT_QUERY_DRIVE_LETTER_FOR_LOGICAL_DISK.
//

typedef struct _FT_QUERY_DRIVE_LETTER_FOR_LOGICAL_DISK_INPUT {
    FT_LOGICAL_DISK_ID  RootLogicalDiskId;
} FT_QUERY_DRIVE_LETTER_FOR_LOGICAL_DISK_INPUT, *PFT_QUERY_DRIVE_LETTER_FOR_LOGICAL_DISK_INPUT;

//
// Output parameter for FT_QUERY_DRIVE_LETTER_FOR_LOGICAL_DISK.
//

typedef struct _FT_QUERY_DRIVE_LETTER_FOR_LOGICAL_DISK_OUTPUT {
    UCHAR   DriveLetter;
} FT_QUERY_DRIVE_LETTER_FOR_LOGICAL_DISK_OUTPUT, *PFT_QUERY_DRIVE_LETTER_FOR_LOGICAL_DISK_OUTPUT;

//
// Input parameter for FT_CHECK_IO.
//

typedef struct _FT_CHECK_IO_INPUT {
    FT_LOGICAL_DISK_ID  LogicalDiskId;
} FT_CHECK_IO_INPUT, *PFT_CHECK_IO_INPUT;

//
// Output parameter for FT_CHECK_IO.
//

typedef struct _FT_CHECK_IO_OUTPUT {
    BOOLEAN IsIoOk;
} FT_CHECK_IO_OUTPUT, *PFT_CHECK_IO_OUTPUT;

//
// Input parameter for FT_SET_DRIVE_LETTER_FOR_LOGICAL_DISK.
//

typedef struct _FT_SET_DRIVE_LETTER_FOR_LOGICAL_DISK_INPUT {
    FT_LOGICAL_DISK_ID  RootLogicalDiskId;
    UCHAR               DriveLetter;
} FT_SET_DRIVE_LETTER_FOR_LOGICAL_DISK_INPUT, *PFT_SET_DRIVE_LETTER_FOR_LOGICAL_DISK_INPUT;

//
// Input parameter for FT_QUERY_NT_DEVICE_NAME_FOR_PARTITION.
//

typedef struct _FT_QUERY_NT_DEVICE_NAME_FOR_PARTITION_INPUT {
    ULONG       Signature;
    ULONG       Reserved;
    LONGLONG    Offset;
} FT_QUERY_NT_DEVICE_NAME_FOR_PARTITION_INPUT, *PFT_QUERY_NT_DEVICE_NAME_FOR_PARTITION_INPUT;

//
// Output parameter for FT_QUERY_NT_DEVICE_NAME_FOR_PARTITION.
//

typedef struct _FT_QUERY_NT_DEVICE_NAME_FOR_PARTITION_OUTPUT {
    USHORT  NumberOfCharactersInNtDeviceName;
    WCHAR   NtDeviceName[1];
} FT_QUERY_NT_DEVICE_NAME_FOR_PARTITION_OUTPUT, *PFT_QUERY_NT_DEVICE_NAME_FOR_PARTITION_OUTPUT;

//
// Input parameter for FT_STOP_SYNC_OPERATIONS.
//

typedef struct _FT_STOP_SYNC_OPERATIONS_INPUT {
    FT_LOGICAL_DISK_ID RootLogicalDiskId;
} FT_STOP_SYNC_OPERATIONS_INPUT, *PFT_STOP_SYNC_OPERATIONS_INPUT;

//
// Output parameter for FT_QUERY_LOGICAL_DISK_ID.
//

typedef struct _FT_QUERY_LOGICAL_DISK_ID_OUTPUT {
    FT_LOGICAL_DISK_ID  RootLogicalDiskId;
} FT_QUERY_LOGICAL_DISK_ID_OUTPUT, *PFT_QUERY_LOGICAL_DISK_ID_OUTPUT;

//
// Output parameter for FT_CREATE_PARTITION_LOGICAL_DISK.
//

typedef struct _FT_CREATE_PARTITION_LOGICAL_DISK_OUTPUT {
    FT_LOGICAL_DISK_ID  NewLogicalDiskId;
} FT_CREATE_PARTITION_LOGICAL_DISK_OUTPUT, *PFT_CREATE_PARTITION_LOGICAL_DISK_OUTPUT;

#ifdef __cplusplus
}
#endif

#endif  // _NTDDFT2_