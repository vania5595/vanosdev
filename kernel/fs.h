#include "voe_api.h"

#ifndef FS

#define FS


extern struct file file_open(struct mount_point ,char*);
extern char isExist(struct file);
extern int file_get_size(struct file);
char file_read_byte(struct file,int);



#endif
