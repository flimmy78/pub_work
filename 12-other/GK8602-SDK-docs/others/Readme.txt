һ��SDK �������ã�
1. ��ѹ GK8602 �� SDK;
2. �л���sdk��ѹ���Ŀ¼��
3. �޸�Confik.mak�ļ�������趨����Ҫ����: 
	(1)$(SDK_TOP)����Ϊ��ǰSDK·����
	(2)C_LIBRARY  ?= glibc ;
4. ������뻷����make deploy
5. ���û���������source env/build_env.sh
6. �޸��ں�����, cd $(KERNEL_TOP);	(·���� Confik.mak �ļ��ﶨ�壬linux/kernel/3.4.43)
	    ���ö�Ӧ�Ĳ�Ʒ���ͣ�make gk7101_xxxxxx_defconfig 
		(�� GK8602A WIFI��ĿΪ gk7101_wifi_defconfig��GK8602B Ϊ gk7102_wifi_defconfig )
7. ���ò�Ʒ���ͣ��޸� $(SDK_TOP)/applications/DVR-ALL/demo/Makefile
		PRODUCT ?= MAKE_WIFI_DVR	��USB��Ŀ���� MAKE_UVC_DVR��
	����Ӧ�ó������·����RUN_PATH = /opt/goke/rootfs_glibc

��������sdk��
1. ���� kernel��
	(1)cd $(KERNEL_TOP); make;
	(2) ������ɺ󣬻�����kernel���� arch/arm/boot/zImage ;
	
2. ���� Ӧ�ó���
	(1)cd $(SDK_TOP)/applications/DVR_ALL; �޸�Ӧ�ó�������Ŀ¼Ϊ  RUN_PATH = /opt/goke/rootfs_glibc ;
	(2) make clean;make	; ������ɺ�Ӧ�ó�������� $(RUN_PATH)
	
3. �������Ҫ·����
  �ļ�ϵͳ��Ŀ¼��/opt/goke/rootfs_glibc
  uboot����$(SDK_TOP)/boot/u-bootxxx.bin
  �ں˾���$(KERNEL_TOP)/arch/arm/boot/zImage

���������ļ�ϵͳ����
  �޸��ļ�$(SDK_TOP)/linux/rootfs/rootfs.mak��FILE_SYSTEM := squashfs
  cd $(SDK_TOP); make rootfs-image
  �����ļ�ϵͳ����$(SDK_TOP)/linux/rootfs/squashfs.img

�ġ�ת���ɿ�����TF��������bin����
1. �ѱ������ɵ� zImage/squashfs.img (һ�㲻����uboot)�ŵ� $(SDK_TOP)/gen-bin Ŀ¼�£�
2. ���� gen-bin Ŀ¼�µ� �������ֲ�.txt�� �޸� argument�ļ���cmd_video������һ��Ҫȷ��rootfstype/sensor/wifi/version �⼸����������ȷ�ϲ�����ȷ��ִ��./update���� 'GK860x.bin' 
3. ���� GK860x.bin ��TF����Ŀ¼����TF��������ӣ���ס���������ϵ磬�Ϳ��Խ���TF��������



��Ҫ�ļ�λ�ã�
uboot: boot/uboot_xxx
kernel: linux/kernel/3.4.43 ; �Ѿ�Ԥ����õ� kernel ����gen-bin/zImage_xxx.bin
rootfs: linux/rootfs/rootfs_glibc_xxx.tar.gz, ������뻷��ʱ���ѹ�� $(ROOTFS_PARENT_DIRECTORY),
		rootfs ����linux/rootfs/squashfs.img
TF������bin��gen-bin/GK860x.bin		
		

