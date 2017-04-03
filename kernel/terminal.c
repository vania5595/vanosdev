#include "terminal.h"

short color= ((0<< 4) | (15 & 0x0F)<< 8);

short* terminalMemory = (short*)0xB8000;

int cursor=0;

void putc(char c){
	if(c=='\n'||cursor>79){
		cursor=0;
		for(int i=0;i<24*80;i++)terminalMemory[i]=terminalMemory[i+80];
		for(int i=0;i<80;i++)terminalMemory[80*24+i]=0;
		if(c!='\n')putc(c);
		return;
	}
	terminalMemory[80*24+cursor]=c|color;
	cursor++;
}

void printString(char *s){
	for(int i=0;s[i]!='\0';i++)putc(s[i]);
}

void crash(char *s){
	for(int i=0;i<80;i++)putc('*');
	for(int i=0;i<34;i++)putc(' ');
	printString("System Crash\n");
	for(int i=0;i<80;i++)putc('*');
	printString("Cause:");
	printString(s);
	while(1);
}
