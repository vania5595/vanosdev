#include "kernel_structure.h"

struct voe_api{
	short (*malloc)(short);
	void (*clear_memory)(short,short);
	struct kernel_structure *ks;
	void (*putc)(char);
	struct file (*file_open)(struct mount_point,char*);
	char (*isExist)(struct file);
	int (*file_get_size)(struct file);
	char (*file_read_byte)(struct file,int);
	unsigned int (*load_VOE)(struct file);
	void (*voe_jump)(unsigned int ,unsigned int ,unsigned int ,int);
};

struct voe_descriptor{
	char cmdline[100];
	struct voe_api *api;
	void *mailbox;
	void *cache;
	char reversed[3984];
};

typedef int voe_entry(int arg); 


extern void InitAPI();

extern  unsigned int load_VOE(struct file);

extern void voe_jump(unsigned int ,unsigned int ,unsigned int ,int);
