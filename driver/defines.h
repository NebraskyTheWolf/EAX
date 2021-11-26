#pragma once

#define OFFSET_IO_MIRRORE       0x2338
#define FILE_DEVICE_MIRRORE     0x3009

#define IOCTL_GET_MODULE_INFORMATION (ULONG)CTL_CODE(FILE_DEVICE_MIRRORE, OFFSET_IO_MIRRORE + 0x0010, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_COPY_MEMORY (ULONG)CTL_CODE(FILE_DEVICE_MIRRORE, OFFSET_IO_MIRRORE + 0x0050, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_PROTECT_MEMORY (ULONG)CTL_CODE(FILE_DEVICE_MIRRORE, OFFSET_IO_MIRRORE + 0x0100, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_ALLOC_MEMORY (ULONG)CTL_CODE(FILE_DEVICE_MIRRORE, OFFSET_IO_MIRRORE + 0x0150, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_FREE_MEMORY (ULONG)CTL_CODE(FILE_DEVICE_MIRRORE, OFFSET_IO_MIRRORE + 0x0200, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

typedef struct _set_module_information 
{
    ULONG pid;
    wchar_t sz_name[32];

} set_module_information, *pset_module_information;

typedef struct _get_module_information
{
	ULONGLONG base_image;
	ULONGLONG size_of_image;
} get_module_information, *pget_module_information;

typedef struct _copy_memory
{
	ULONGLONG buffer;
	ULONGLONG address;
	ULONGLONG size;
	ULONG pid;
	BOOLEAN write;
} copy_memory, *pcopy_memory;

typedef struct _protect_memory
{
	ULONG pid;
	ULONGLONG address;
	ULONGLONG size;
	PDWORD new_protect;
} protect_memory, *pprotect_memory;

typedef struct _alloc_memory
{
	ULONG pid;
	ULONGLONG out_address;
	ULONGLONG size;
	ULONG protect;
} alloc_memory, *palloc_memory;

typedef struct _free_memory
{
	ULONG pid;
	ULONGLONG address;
} free_memory, *pfree_memory;