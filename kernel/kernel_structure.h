#include "mount_point.h"
#include "multiboot.h"

#ifndef KERNELSTRUCTURE

#define KERNELSTRUCTURE


struct kernel_structure
{
    struct mount_point mount_points[16];
    struct multiboot *multiboot;
    void* ramdisk_address;
};

#endif
