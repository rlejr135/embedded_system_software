obj-m := stopwatch.o

KDIR := /work/achroimx_kernel
PWD := $(shell pwd)

driver:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules ARCH=arm

clean :
	rm -rf *.o
	rm -rf *.ko
	rm -rf *.mod.c
	rm -rf *.order
	rm -rf *.symvers
	rm -rf .tmp*
	rm -rf .stop*
