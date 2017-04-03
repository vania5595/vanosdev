clear
make
qemu-system-x86_64 -kernel kernel -initrd ramdisk.tar -m 12M
make clean
