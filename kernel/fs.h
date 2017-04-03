#include "mount_point.h"

#ifndef FS

#define FS


extern struct file file_open(struct mount_point ,char*);
extern char isExist(struct file);
extern int file_get_size(struct file);
char file_read_byte(struct file,int);

struct fs_api{
	int (*get_size)(void*);
	char (*read_byte)(void*,int);
};

struct file{
	void *file_address;
	struct fs_api *fs_api_address;
};

#endif
