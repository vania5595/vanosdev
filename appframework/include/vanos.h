#include "../../kernel/voe_api.h"

extern struct voe_descriptor *voe_descriptor_object;

extern void main();

void boot_voe(struct voe_descriptor *voe_descriptor_arg){
	voe_descriptor_object=voe_descriptor_arg;
	main();
} 

struct voe_descriptor *voe_descriptor_object;
