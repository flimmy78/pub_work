#include <stdio.h>
#include <stdlib.h>

#if (0)
double strtod(const char *nptr, char **endptr);/*将字符串转换成浮点数*/
#endif

#define YEAR (365*24*60*60)UL

#if (1)
int main()
{
	char szOrbits[] = "365.24 29.53";
	char* pEnd;
	double d1, d2;

	printf("String: %s\n",szOrbits);
    //printf("&szOrbits = %p\n",szOrbits);
	d1 = strtod (szOrbits, &pEnd);
    //printf("&pEnd = %p pEnd = %d\n",&pEnd,pEnd);
	d2 = strtod (pEnd, NULL);
	printf("d1 = %f\td2 = %f\n",d1,d2);
	printf ("月球每年绕地球运行 %.2f 周。\n", d1/d2);

	return 0;
}
#else

#endif
