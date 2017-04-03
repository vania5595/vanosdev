#include "ramdisk.h"
#include "fs.h"


struct tar_header
{
    char filename[100];
    char mode[8];
    char uid[8];
    char gid[8];
    char size[12];
    char mtime[12];
    char chksum[8];
    char typeflag[1];
}; 

struct fs_api ramdisk_api;

unsigned int getsize(const char *in)
{
 
    unsigned int size = 0;
    unsigned int j;
    unsigned int count = 1;
 
    for (j = 11; j > 0; j--, count *= 8)
        size += ((in[j - 1] - '0') * count);
 
    return size;
 
}

int ramdisk_get_size(void *file_address){
	return getsize(((struct tar_header*)(file_address))->size);
}

char ramdisk_read_byte(void *file_address,int index){
	return *(char*)(file_address+512+index);
}


struct file ramdisk_open_file(void *fs_address,char* filename){
	int index=0;
	struct file file_object;
	file_object.file_address = (void*)0;
	while(1){
		struct tar_header *file_address = fs_address + 512 * index;
		if(file_address->filename[0]==0)break;
		char is_file=1;
		for(int i=0;filename[i]!='\0';i++){
			if(file_address->filename[i]!=filename[i]){
				is_file=0;
				break;
			}
		}
		if(is_file){
			file_object.file_address=file_address;
		}
		
		int offset=getsize(file_address->size)/512;
		if(getsize(file_address->size)%512)offset++;
		index+=offset+1;
	}
	file_object.fs_api_address=&ramdisk_api;
	return file_object;
}

struct mount_point mount_ramdisk(void *ramdisk_address){
	struct mount_point mp;
	mp.fs_address=ramdisk_address;
	mp.open_file=ramdisk_open_file;
	ramdisk_api.get_size=ramdisk_get_size;
	ramdisk_api.read_byte=ramdisk_read_byte;
	return mp;
} 
