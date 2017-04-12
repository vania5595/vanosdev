cd kernel
make
cd ..
cp kernel/kernel boot/VanOS/kernel.i386 
cd kernel
make clean
cd ..
sh buildramdisk.sh
grub-mkrescue boot -o test.iso
