.set ALIGN,    1<<0             # align loaded modules on page boundaries
.set MEMINFO,  1<<1             # provide memory map
.set VIDINFO,  1<<2             # provide video info
.set FLAGS,    ALIGN | MEMINFO | VIDINFO # this is the Multiboot 'flag' field
.set MAGIC,    0x1BADB002       # 'magic number' lets bootloader find the header
.set CHECKSUM, -(MAGIC + FLAGS) # checksum of above, to prove we are multiboot

# Declare a header as in the Multiboot Standard. We put this into a special
# section so we can force the header to be in the start of the final program.
# You don't need to understand all these details as it is just magic values that
# is documented in the multiboot standard. The bootloader will search for this
# magic sequence and recognize us as a multiboot kernel.
.section .mboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

.long 0x00000000
.long 0x00000000
.long 0x00000000
.long 0x00000000
.long 0x00000000

.long 0x00000000

.long 1024
.long 768
.long 32

.global	init

init:
cli
push %ebx
call main

