savedcmd_/home/liang/Desktop/test/driver/my_driver.mod := printf '%s\n'   my_driver.o | awk '!x[$$0]++ { print("/home/liang/Desktop/test/driver/"$$0) }' > /home/liang/Desktop/test/driver/my_driver.mod
