ENTRY(boot_voe)
SECTIONS
{
	. = 0xFEC00000;
  .text  :{
		 *(.text)
  }
  
} 
