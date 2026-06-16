labels="mysys"
mkdir -p CD_root/isolinux
mkdir -p CD_root/images
mkdir -p CD_root/kernel
cp isolinux.bin CD_root/isolinux/isolinux.bin
cp isolinux.cfg CD_root/isolinux/isolinux.cfg
bcc -ansi -c -3 -Md libdos.c -o libdos.a
cp libdos.a libc.a
bcc -c  -3 -Md  color.c -o color.o
ld86 -T0x101000 -D0x101200 -i -L -3  color.o -o color.c32
bcc -c  -3 -Md  intro.c -o intro.o
ld86 -T0x101000 -D0x101200 -i -L -3  intro.o -o intro.c32
bcc -c  -3 -Md  tests.c -o tests.o
ld86 -T0x101000 -D0x101200 -i -L -3  tests.o -o tests.c32

cp *.bss CD_root/isolinux/
cp *.sys CD_root/isolinux/
cp *.c32 CD_root/isolinux/
cp *.com CD_root/isolinux/
cp *.elf CD_root/isolinux/
cp *.jpg CD_root/isolinux/
cp *.menu CD_root/isolinux/
cp *.txt CD_root/isolinux/

cp *.c32 CD_root/isolinux/
cp *.com CD_root/isolinux/
ls CD_root/isolinux > CD_root/isolinux/ls.txt
tree CD_root/ > CD_root/isolinux/tree.txt
printf "$labels\n" > CD_root/isolinux/label.txt
genisoimage -o myos.iso -V "$labels" -input-charset utf-8 -b isolinux/isolinux.bin -no-emul-boot -boot-load-size 4  -boot-info-table ./CD_root 

