一、SDK 环境配置：
1. 解压 GK8602 的 SDK;
2. 切换到sdk解压后的目录；
3. 修改Confik.mak文件里面的设定，主要包括: 
	(1)$(SDK_TOP)设置为当前SDK路径，
	(2)C_LIBRARY  ?= glibc ;
4. 部署编译环境，make deploy
5. 设置环境变量，source env/build_env.sh
6. 修改内核配置, cd $(KERNEL_TOP);	(路径在 Confik.mak 文件里定义，linux/kernel/3.4.43)
	    配置对应的产品类型：make gk7101_xxxxxx_defconfig 
		(如 GK8602A WIFI项目为 gk7101_wifi_defconfig，GK8602B 为 gk7102_wifi_defconfig )
7. 设置产品类型：修改 $(SDK_TOP)/applications/DVR-ALL/demo/Makefile
		PRODUCT ?= MAKE_WIFI_DVR	（USB项目则是 MAKE_UVC_DVR）
	设置应用程序输出路径：RUN_PATH = /opt/goke/rootfs_glibc

二、编译sdk，
1. 编译 kernel：
	(1)cd $(KERNEL_TOP); make;
	(2) 编译完成后，会生成kernel镜像 arch/arm/boot/zImage ;
	
2. 编译 应用程序：
	(1)cd $(SDK_TOP)/applications/DVR_ALL; 修改应用程序的输出目录为  RUN_PATH = /opt/goke/rootfs_glibc ;
	(2) make clean;make	; 编译完成后应用程序输出到 $(RUN_PATH)
	
3. 编译后主要路径：
  文件系统根目录：/opt/goke/rootfs_glibc
  uboot镜像：$(SDK_TOP)/boot/u-bootxxx.bin
  内核镜像：$(KERNEL_TOP)/arch/arm/boot/zImage

三、制作文件系统镜像：
  修改文件$(SDK_TOP)/linux/rootfs/rootfs.mak，FILE_SYSTEM := squashfs
  cd $(SDK_TOP); make rootfs-image
  生成文件系统镜像：$(SDK_TOP)/linux/rootfs/squashfs.img

四、转换成可用于TF卡升级的bin档：
1. 把编译生成的 zImage/squashfs.img (一般不升级uboot)放到 $(SDK_TOP)/gen-bin 目录下，
2. 按照 gen-bin 目录下的 “操作手册.txt” 修改 argument文件中cmd_video参数（一般要确认rootfstype/sensor/wifi/version 这几个参数），确认参数正确后执行./update生成 'GK860x.bin' 
3. 复制 GK860x.bin 到TF卡根目录，把TF卡接入板子，按住升级按键上电，就可以进行TF卡升级；



主要文件位置：
uboot: boot/uboot_xxx
kernel: linux/kernel/3.4.43 ; 已经预编译好的 kernel 镜像：gen-bin/zImage_xxx.bin
rootfs: linux/rootfs/rootfs_glibc_xxx.tar.gz, 部署编译环境时会解压到 $(ROOTFS_PARENT_DIRECTORY),
		rootfs 镜像：linux/rootfs/squashfs.img
TF卡升级bin：gen-bin/GK860x.bin		
		

