#include <iostream>

using namespace std;

int main()
{
	cout << "Size of char		:" << sizeof(char) <<endl;
	cout << "Size of int		:" << sizeof(int) <<endl;
	cout << "Size of short int  :" << sizeof(short int) <<endl;
	
	/**实例使用endl，将在每一行添加一个换行符
	 *<<用于向屏幕传多个值
	 */
	cout << "Size of long int	:" << sizeof(long int) <<endl;
	cout << "Size of float		:" << sizeof(float) <<endl;
	cout << "Size of double		:" << sizeof(double) <<endl;
	cout << "Size of wchar_t	:" << sizeof(wchar_t) <<endl;

	return 0;
}
