#define YEAR (365*24*60*60)UL

#include <stdio.h>
#include <stdlib.h>
int main()
{
	char szOrbits[] = "365.24 29.53";
	char* pEnd;
	double d1, d2;

	printf("String: %s\n",szOrbits);
	d1 = strtod (szOrbits, &pEnd);
	d2 = strtod (pEnd, NULL);
	printf("d1 = %f\td2 = %f\n",d1,d2);
	printf ("月球每年绕地球运行 %.2f 周。\n", d1/d2);

	return 0;
}
