get_ps_info:get_ps_info.o
	gcc -g -static get_ps_info.o -o get_ps_info
get_ps_info.o:get_ps_info.c
	gcc -g -c -static get_ps_info.c
.PHONY:open1 open2 open3 open4
open1:
	sudo vim /home/lumos/oslab/linux-4.9.263/arch/x86/entry/syscalls/syscall_64.tbl 

open2:
	sudo vim /home/lumos/oslab/linux-4.9.263/include/linux/syscalls.h

open3:
	sudo vim /home/lumos/oslab/linux-4.9.263/kernel/sys.c

open4:
	sudo vim get_ps_num.c

open5:
	sudo vim get_ps_info.c
my_cp:
	sudo cp get_ps_info ../busybox-1.32.1/_install
	sudo rm ../initramfs-busybox-x64.cpio.gz
my_cd:
	cd ../linux-4.9.263/
	make find
