#include <stdlib.h>
#include <stdio.h>

#if (0)
double atof(const char *nptr);/*将字符串转换成浮点型数*/
#endif

int main(void)
{
    char *a = "-100.23";
    char *b = "200e-2";
    float c;
    c = atof(a) + atof(b); 
    printf("String (a) %s (b) %s\n",a,b);
    printf("atof(a) = %f atof(b) = %f c = %f\n",atof(a),atof(b),c);
}
