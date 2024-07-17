/**
  Copyright (c) 2011 - 2020, Arm Limited. All rights reserved.<BR>

  SPDX-License-Identifier: BSD-2-Clause-Patent
**/

#ifndef _PREPI_H_
#define _PREPI_H_

STATIC UINT64 mSystemMemoryEnd = FixedPcdGet64 (PcdSystemMemoryBase) + FixedPcdGet64 (PcdSystemMemorySize) - 1;

#define IS_XIP() (((UINT64)FixedPcdGet64 (PcdFdBaseAddress) > mSystemMemoryEnd) || ((FixedPcdGet64 (PcdFdBaseAddress) + FixedPcdGet32 (PcdFdSize)) <= FixedPcdGet64 (PcdSystemMemoryBase)))

RETURN_STATUS
EFIAPI
TimerConstructor ();

EFI_STATUS
EFIAPI
MemoryPeim (
  IN EFI_PHYSICAL_ADDRESS UefiMemoryBase,
  IN UINT64               UefiMemorySize
  );

EFI_STATUS
EFIAPI
PlatformPeim ();

VOID
ArchInitialize ();

VOID
EFIAPI
ProcessLibraryConstructorList ();

//
// Enabled DXE Memory Protection Settings
//
#define DXE_MEMORY_PROTECTION_SETTINGS_ON                \
{                                                        \
  DXE_MEMORY_PROTECTION_SETTINGS_CURRENT_VERSION,        \
  TRUE,                                                  \
  FALSE,                                                 \
  {                                                      \
    .Fields.UefiNullDetection           = 1,             \
    .Fields.DisableEndOfDxe             = 0,             \
    .Fields.DisableReadyToBoot          = 0              \
  },                                                     \
  {                                                      \
    .Fields.UefiPageGuard               = 1,             \
    .Fields.UefiPoolGuard               = 1,             \
    .Fields.Direction                   = 0              \
  },                                                     \
  {                                                      \
    .Fields.ProtectImageFromUnknown     = 1,             \
    .Fields.ProtectImageFromFv          = 1,             \
    .Fields.RaiseErrorIfProtectionFails = 1,             \
    .Fields.BlockImagesWithoutNxFlag    = 0              \
  },                                                     \
  {                                                      \
    .Fields.EfiReservedMemoryType       = 1,             \
    .Fields.EfiLoaderCode               = 1,             \
    .Fields.EfiLoaderData               = 1,             \
    .Fields.EfiBootServicesCode         = 1,             \
    .Fields.EfiBootServicesData         = 0,             \
    .Fields.EfiRuntimeServicesCode      = 1,             \
    .Fields.EfiRuntimeServicesData      = 1,             \
    .Fields.EfiConventionalMemory       = 1,             \
    .Fields.EfiUnusableMemory           = 1,             \
    .Fields.EfiACPIReclaimMemory        = 1,             \
    .Fields.EfiACPIMemoryNVS            = 1,             \
    .Fields.EfiMemoryMappedIO           = 1,             \
    .Fields.EfiMemoryMappedIOPortSpace  = 1,             \
    .Fields.EfiPalCode                  = 1,             \
    .Fields.EfiPersistentMemory         = 1,             \
    .Fields.EfiUnacceptedMemoryType     = 1,             \
    .Fields.OEMReserved                 = 1,             \
    .Fields.OSReserved                  = 1              \
  },                                                     \
  {                                                      \
    .Fields.EfiReservedMemoryType       = 1,             \
    .Fields.EfiLoaderCode               = 1,             \
    .Fields.EfiLoaderData               = 1,             \
    .Fields.EfiBootServicesCode         = 1,             \
    .Fields.EfiBootServicesData         = 1,             \
    .Fields.EfiRuntimeServicesCode      = 1,             \
    .Fields.EfiRuntimeServicesData      = 1,             \
    .Fields.EfiConventionalMemory       = 1,             \
    .Fields.EfiUnusableMemory           = 1,             \
    .Fields.EfiACPIReclaimMemory        = 1,             \
    .Fields.EfiACPIMemoryNVS            = 1,             \
    .Fields.EfiMemoryMappedIO           = 1,             \
    .Fields.EfiMemoryMappedIOPortSpace  = 1,             \
    .Fields.EfiPalCode                  = 1,             \
    .Fields.EfiPersistentMemory         = 1,             \
    .Fields.EfiUnacceptedMemoryType     = 1,             \
    .Fields.OEMReserved                 = 1,             \
    .Fields.OSReserved                  = 1              \
  },                                                     \
  {                                                      \
    .Fields.EfiReservedMemoryType       = 0,             \
    .Fields.EfiLoaderCode               = 1,             \
    .Fields.EfiLoaderData               = 1,             \
    .Fields.EfiBootServicesCode         = 1,             \
    .Fields.EfiBootServicesData         = 0,             \
    .Fields.EfiRuntimeServicesCode      = 1,             \
    .Fields.EfiRuntimeServicesData      = 1,             \
    .Fields.EfiConventionalMemory       = 0,             \
    .Fields.EfiUnusableMemory           = 1,             \
    .Fields.EfiACPIReclaimMemory        = 1,             \
    .Fields.EfiACPIMemoryNVS            = 1,             \
    .Fields.EfiMemoryMappedIO           = 1,             \
    .Fields.EfiMemoryMappedIOPortSpace  = 1,             \
    .Fields.EfiPalCode                  = 1,             \
    .Fields.EfiPersistentMemory         = 1,             \
    .Fields.EfiUnacceptedMemoryType     = 1,             \
    .Fields.OEMReserved                 = 1,             \
    .Fields.OSReserved                  = 1              \
  },                                                     \
  TRUE,                                                  \
  TRUE                                                   \
}

//
// Enabled MM Memory Protection Settings
//
#define MM_MEMORY_PROTECTION_SETTINGS_ON                 \
{                                                        \
  MM_MEMORY_PROTECTION_SETTINGS_CURRENT_VERSION,         \
  TRUE,                                                  \
  {                                                      \
    .Fields.MmPageGuard                 = 1,             \
    .Fields.MmPoolGuard                 = 1,             \
    .Fields.Direction                   = 0              \
  },                                                     \
  {                                                      \
    .Fields.EfiReservedMemoryType       = 1,             \
    .Fields.EfiLoaderCode               = 1,             \
    .Fields.EfiLoaderData               = 1,             \
    .Fields.EfiBootServicesCode         = 1,             \
    .Fields.EfiBootServicesData         = 1,             \
    .Fields.EfiRuntimeServicesCode      = 1,             \
    .Fields.EfiRuntimeServicesData      = 1,             \
    .Fields.EfiConventionalMemory       = 1,             \
    .Fields.EfiUnusableMemory           = 1,             \
    .Fields.EfiACPIReclaimMemory        = 1,             \
    .Fields.EfiACPIMemoryNVS            = 1,             \
    .Fields.EfiMemoryMappedIO           = 1,             \
    .Fields.EfiMemoryMappedIOPortSpace  = 1,             \
    .Fields.EfiPalCode                  = 1,             \
    .Fields.EfiPersistentMemory         = 1,             \
    .Fields.EfiUnacceptedMemoryType     = 1,             \
    .Fields.OEMReserved                 = 1,             \
    .Fields.OSReserved                  = 1              \
  },                                                     \
  {                                                      \
    .Fields.EfiReservedMemoryType       = 1,             \
    .Fields.EfiLoaderCode               = 1,             \
    .Fields.EfiLoaderData               = 1,             \
    .Fields.EfiBootServicesCode         = 1,             \
    .Fields.EfiBootServicesData         = 1,             \
    .Fields.EfiRuntimeServicesCode      = 1,             \
    .Fields.EfiRuntimeServicesData      = 1,             \
    .Fields.EfiConventionalMemory       = 1,             \
    .Fields.EfiUnusableMemory           = 1,             \
    .Fields.EfiACPIReclaimMemory        = 1,             \
    .Fields.EfiACPIMemoryNVS            = 1,             \
    .Fields.EfiMemoryMappedIO           = 1,             \
    .Fields.EfiMemoryMappedIOPortSpace  = 1,             \
    .Fields.EfiPalCode                  = 1,             \
    .Fields.EfiPersistentMemory         = 1,             \
    .Fields.EfiUnacceptedMemoryType     = 1,             \
    .Fields.OEMReserved                 = 1,             \
    .Fields.OSReserved                  = 1              \
  }                                                      \
}

#endif /* _PREPI_H_ */
