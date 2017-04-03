#ifndef MOUNTPOINT

#define MOUNTPOINT

struct mount_point
{
    void *fs_address;
    struct file (*open_file)(void*,char*);
}; 

#endif
