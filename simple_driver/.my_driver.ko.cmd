savedcmd_/home/liang/Desktop/test/driver/my_driver.ko := ld -r -m elf_x86_64 -z noexecstack --build-id=sha1  -T scripts/module.lds -o /home/liang/Desktop/test/driver/my_driver.ko /home/liang/Desktop/test/driver/my_driver.o /home/liang/Desktop/test/driver/my_driver.mod.o;  make -f ./arch/x86/Makefile.postlink /home/liang/Desktop/test/driver/my_driver.ko
