#include "memory.h"

int placement_address;

static unsigned int* page_directory = 0;
static unsigned int page_dir_loc = 0;
static unsigned int* last_page = 0;

/* Paging now will be really simple
 * we reserve 0-8MB for kernel stuff
 * heap will be from approx 1mb to 4mb
 * and paging stuff will be from 4mb
 */


void paging_map_virtual_to_phys(unsigned int virt, unsigned int phys)
{
	unsigned short id = virt >> 22;
	last_page = (unsigned int *)(((unsigned int)0x404000) + 4096*id);
	for(int i = 0; i < 1024; i++)
	{
		last_page[i] = phys | 3;
		phys += 4096;
	}
	page_directory[id] = ((unsigned int)last_page) | 3;
	
}

void paging_enable()
{
	asm volatile("mov %%eax, %%cr3": :"a"(page_dir_loc));	
	asm volatile("mov %cr0, %eax");
	asm volatile("orl $0x80000000, %eax");
	asm volatile("mov %eax, %cr0");
}

void paging_init()
{
	page_directory = (unsigned int*)0x400000;
	page_dir_loc = (unsigned int)page_directory;
	last_page = (unsigned int *)0x404000;
	for(int i = 0; i < 1024; i++)
	{
		page_directory[i] = 0 | 2;
	}
	paging_map_virtual_to_phys(0, 0);
	for(int i=0;i<1000;i++)paging_map_virtual_to_phys(i*0x400000, i*0x400000);
	paging_enable();
	char *heap_table=(char*)0x800000;
	for(int i=0;i<64*1024;i++)heap_table[i]=0x00;
	heap_table[0]=0xff;
}

short malloc(short sz){
	char *heap_table=(char*)0x800000;
	short tmp,count;
	for(int i=1;i<64*1024;i++){
		if(heap_table[i-1]==0xff)if(heap_table[i]==0x00)tmp=i;
		if(heap_table[i]==0xff)count=0;
		if(heap_table[i]==0x00)count++;
		if(sz==count)break;
	}
	if(sz==count){
		for(int i=0;i<count;i++)heap_table[64*1024*(tmp+i)]=0xff;
	}
}

void clear_memory(short id,short sz){
	char *heap_table=(char*)0x800000;
	for(int i=0;i<sz;i++)heap_table[64*1024*(id+i)]=0x00;
}
