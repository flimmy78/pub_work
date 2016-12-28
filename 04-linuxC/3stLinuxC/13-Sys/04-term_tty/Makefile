.PHONY:clean

CROSS_COMPILE=arm-goke-linux-gnueabi-gcc
GOKE_TEST_DIR=/opt/goke/rootfs_glibc/my_modules/

goke_test:
	$(CROSS_COMPILE) 04-tty.c -o tty
	cp  tty  $(GOKE_TEST_DIR)

clean:
	$(RM) tty a.out
