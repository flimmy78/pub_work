#!/bin/sh
VERSIONFILE=./version
OLDVERSION=
OLDPRODUCT=
if [ -f "$VERSIONFILE" ] #检查文件是否存在
then
	OLDVERSION=$(sed -n '2p' $VERSIONFILE)#打印第二行
	OLDPRODUCT=$(sed -n '1p' $VERSIONFILE)
#	echo OLDVERSION $OLDVERSION
#	echo OLDPRODUCT $OLDPRODUCT
	if [ "$OLDVERSION"x != "$version"x ]
	then
		sed -i "2s/.*/$version/g" $VERSIONFILE
	fi
	if [ "$OLDPRODUCT"x != "$product"x ]
	then
		sed -i "1s/.*/$product/g" $VERSIONFILE
	fi
else
	cat /etc/version > $VERSIONFILE
	sed -i "1s/.*/$product/g" $VERSIONFILE
	sed -i "2s/.*/$version/g" $VERSIONFILE
fi
