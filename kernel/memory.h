#include "kernel_structure.h"

extern int placement_address;
extern void paging_init();
extern void paging_map_virtual_to_phys(unsigned int , unsigned int ); 
extern short malloc(short);
extern void clear_memory(short,short);
