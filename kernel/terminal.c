#include "terminal.h"
#include "vesa.h"

short color= ((0<< 4) | (15 & 0x0F)<< 8);



short* terminalMemory = (short*)0xB8000;

int cursor=0;

void putc(char c){
	if(c=='\n'||cursor>127){
		cursor=0;
		for(int i=0;i<VideoRamVector(0,767-8);i++)vram[i]=vram[i+8192];
		for(int i=VideoRamVector(0,767-8);i<VideoRamVector(1024,767);i++)vram[i]=0;
		if(c!='\n')putc(c);
		return;
	}
	renderChar(VideoRamVector(8*cursor,767-8),c);
	cursor++;
}

void printString(char *s){
	for(int i=0;s[i]!='\0';i++)putc(s[i]);
}

void crash(char *s){
	for(int i=0;i<128;i++)putc('*');
	for(int i=0;i<58;i++)putc(' ');
	printString("System Crash\n");
	for(int i=0;i<128;i++)putc('*');
	printString("Cause:");
	printString(s);
	while(1);
}
