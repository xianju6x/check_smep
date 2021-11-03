ifneq ($(KERNELRELEASE),)
	obj-m :=check_smep.o
else
	KERNELDIR := /lib/modules/$(shell uname -r)/build
	PWD := $(shell pwd)

modules:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules

endif

clean:
	rm *.o *.ko *.mod.* modules.order  Module.symvers

