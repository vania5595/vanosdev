#include "vanos.h"

void printString(char *str){
	for(int i=0;str[i]!=0;i++)
	voe_descriptor_object->api->putc(str[i]);
}

void SlowEffect(int addr,int color){
	voe_descriptor_object->api->vram[addr]+=color;//voe_descriptor_object->api->vram[addr]/=2;
}

unsigned char inportb(unsigned int port)
{
   unsigned char ret;
   asm volatile ("inb %%dx,%%al":"=a" (ret):"d" (port));
   return ret;
}

void main(){
	int anim=0;
	printString("VESA Video Driver Demo\n");
	printString("Hello,World!\n");
	while(1){
		while ((inportb(0x3DA) & 0x08));
        while (!(inportb(0x3DA) & 0x08));
		for(int x=300;x<600;x++)for(int y=300;y<600;y++){
			if((450-x)*(450-x)+(450-y)*(450-y)<anim*anim)SlowEffect(1024*y+x,0x2281337);
			else SlowEffect(1024*y+x,0x0);
			
		}
		anim++;
			anim%=100;
	}
} 
