#include "voe_api.h"

typedef int voe_entry(int arg); 


extern void InitAPI(struct kernel_structure *);

extern  unsigned int load_VOE(struct file);

extern void voe_jump(unsigned int ,unsigned int ,unsigned int ,int);
