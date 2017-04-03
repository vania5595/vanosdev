#include "fs.h"

struct file file_open(struct mount_point mp,char* filename){
	return mp.open_file(mp.fs_address,filename);
} 

char isExist(struct file file_object){
	return file_object.file_address != (void*)0;
}

int file_get_size(struct file file_object){
	return file_object.fs_api_address->get_size(file_object.file_address);
} 

char file_read_byte(struct file file_object,int index){
	return file_object.fs_api_address->read_byte(file_object.file_address,index);
} 

