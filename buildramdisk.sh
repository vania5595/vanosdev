 mkdir ramdisk
 
 cd apps/vesa_test
 sh build.sh
 cd ..
 cd ..
 cp apps/vesa_test/app.i386 ramdisk/init.i386
 
 cd ramdisk
 tar cf ../boot/VanOS/bootcontrol.eaf *
 cd ..
 rm -r ramdisk
