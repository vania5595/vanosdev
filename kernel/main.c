#include "voe_api.h"
#include "terminal.h"
#include "ramdisk.h"
#include "fs.h"
#include "memory.h"
#include "voe.h"


void main(struct multiboot* multiboot){
		struct kernel_structure kernel_structure_object;
		kernel_structure_object.multiboot=multiboot;
		if(kernel_structure_object.multiboot->mods_count == 0)crash("Ramdisk not found.");
		kernel_structure_object.ramdisk_address = (void*)*((int*)(kernel_structure_object.multiboot->mods_addr));
		placement_address = (unsigned int)*((int*)(kernel_structure_object.multiboot->mods_addr+4));
		kernel_structure_object.mount_points[0] = mount_ramdisk(kernel_structure_object.ramdisk_address);
		struct file init_file = file_open(kernel_structure_object.mount_points[0],"test.voe");
		if(!isExist(init_file))crash("Init file not found.");
		paging_init();
		InitAPI(kernel_structure_object);
		unsigned int  init_voe = load_VOE(init_file);
		voe_jump(0,init_voe,0,init_voe);
		crash("The system is fully initialized, but not the control process.");
}
