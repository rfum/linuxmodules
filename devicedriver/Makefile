obj-m = testDev.o
MODULE_FORCE_UNLOAD=y
all:
	make -C /lib/modules/$(shell uname -r)/build M=$(pwd) modules
clean :
	make -C /lib/modules/$(shell uname -r)/build M=$(pwd) clean

test:test.c
	cc -o test test.c
