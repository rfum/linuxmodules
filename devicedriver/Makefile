obj-m = testDevice.o
MODULE_FORCE_UNLOAD=y
all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean :
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

test:testDevice.c
	cc -o test testDevice.c
