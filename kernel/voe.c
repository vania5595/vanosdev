#include "voe.h"
#include "fs.h" 
#include "memory.h"
#include "fs.h"
#include "terminal.h"

struct voe_api voe_api_object;

unsigned int load_VOE(struct file voe_file){
	
	int file_size = file_get_size(voe_file);
	short blocks = (file_size+sizeof(struct voe_descriptor) ) / (64*1024);
	if((file_size+sizeof(struct voe_descriptor) ) % (64*1024))blocks++;
	short blocks_id = malloc(blocks);
	struct voe_descriptor *vd = (struct voe_descriptor *)(blocks_id*64*1024);
	vd->cmdline[0]='\0';
	vd->mailbox=(void*)0;
	vd->cache=(void*)0;
	vd->api=&voe_api_object;
	char *voe_code = (char*)((int)vd+sizeof(struct voe_descriptor));
	for(int i=0;i<file_size;i++)voe_code[i]=file_read_byte(voe_file,i);
	return (unsigned int)vd;
	
}

void voe_jump(unsigned int current_voe,unsigned int new_voe,unsigned int entry,int arg){
	
	paging_map_virtual_to_phys(0xFEC00000, new_voe+sizeof(struct voe_descriptor));
	//putc(  ((char*)(0xFEC00000))[ 0] );
	((voe_entry*)(0xFEC00000))(arg);
	if(current_voe==0)return;
	paging_map_virtual_to_phys(0xFEC00000, current_voe+sizeof(struct voe_descriptor));
	
}

void InitAPI(struct kernel_structure *ks){
	voe_api_object.clear_memory=clear_memory;
	voe_api_object.file_get_size=file_get_size;
	voe_api_object.file_open=file_open;
	voe_api_object.file_read_byte=file_read_byte;
	voe_api_object.isExist=isExist;
	voe_api_object.ks=ks;
	voe_api_object.malloc=malloc;
	voe_api_object.putc=putc;
	voe_api_object.load_VOE=load_VOE;
}


