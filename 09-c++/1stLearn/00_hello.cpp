#include <iostream>
#include <stdio.h>

using namespace std;

/*----main()程序开始执行的地方----*/

int main()
{
	cout << "This is a c++ SRC file !\n";//输出
	printf("[%s]___(%d)___<%s>\n",__FILE__,__LINE__,__func__);

	return 0;
}
