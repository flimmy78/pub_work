#!/bin/sh
if [ $# != 0 ]
then
	echo "		insmod /lib/modules/3.4.43-gk/extra/dsp.ko"
	echo "		insmod /lib/modules/3.4.43-gk/extra/encipher.ko" &
	echo "		insmod /lib/modules/3.4.43-gk/extra/vo.ko" 
	echo "		insmod /lib/modules/3.4.43-gk/extra/tv.ko" &
	echo "		insmod /lib/modules/3.4.43-gk/extra/vi.ko"
if [ $1 == "OV2710" ]
then
	echo  "			insmod /lib/modules/3.4.43-gk/extra/ov2710.ko" &
elif [ $1 == "JXH42" ]
then
	echo "			insmod /lib/modules/3.4.43-gk/extra/jxh42.ko" &
elif [ $1 == "IMX222_12bit" ]
then
	echo "			insmod /lib/modules/3.4.43-gk/extra/imx222_12bit.ko" &
elif [ $1 == "IMX222_10bit" ]
then
	echo "			insmod /lib/modules/3.4.43-gk/extra/imx222_10bit.ko" &
elif [ $1 == "JXF02" ]
then
	echo "			insmod /lib/modules/3.4.43-gk/extra/jxf02.ko" &
else
	echo "			insmod /lib/modules/3.4.43-gk/extra/jxh42.ko" &
fi
echo "	insmod /lib/modules/3.4.43-gk/extra/isp.ko"
echo "	insmod /lib/modules/3.4.43-gk/extra/hw_crypto.ko"
echo "	insmod /lib/modules/3.4.43-gk/extra/media.ko" &
else
	echo "Pls input sensor type......"
fi
