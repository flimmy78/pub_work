.PHONY:ALL GK_BIN INSTALL clean Test

SRV=server3
CLI=client3

CC_GK=arm-goke-linux-gnueabi-gcc
CFLAGS= -g -Wall -O0

all=$(SRV) $(CLI)

ALL:$(all)

Test:test.c
	$(CC) test.c $(CFLAGS) -o test -Wl,-Map,test_main.map

GK_BIN:
	$(CC_GK) server3.c $(CFLAGS) -o myserver -Wl,-Map,SRV_main.map
	$(CC_GK) client3.c $(CFLAGS) -o myclient -Wl,-Map,CLI_main.map

INSTALL:myserver myclient
	cp my* /opt/goke/rootfs_glibc/
	

clean:
	rm -rf $(all) a.out *.o my* *.map test 
