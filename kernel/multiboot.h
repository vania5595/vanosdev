#ifndef MULTIBOOT

#define MULTIBOOT


struct multiboot
{
   int flags;
   int mem_lower;
   int mem_upper;
   int boot_device;
   int cmdline;
   int mods_count;
   int mods_addr;
   int num;
   int size;
   int addr;
   int shndx;
   int mmap_length;
   int mmap_addr;
   int drives_length;
   int drives_addr;
   int config_table;
   int boot_loader_name;
   int apm_table;
   int vbe_control_info;
   int vbe_mode_info;
   int vbe_mode;
   int vbe_interface_seg;
   int vbe_interface_off;
   int vbe_interface_len;
}  __attribute__((packed)); 

#endif
