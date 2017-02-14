/*******************************************************************
 *   > File Name: 01-ferror.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 14 Feb 2017 05:59:38 PM CST
 ******************************************************************/

#include <stdio.h>

#if (0)
#include <stdio.h>
int ferror(FILE *stream);/*检查文件流是否有错误发生*/
//@return：如果文件流有错误发生则返回非0值
#endif

#define MODE "w"

int main(int argc, char* argv[])
{
    FILE* stream;

    stream = fopen("DUMMY.FIL", MODE);
    (void)getc(stream);
    if(ferror(stream))
    {
        printf("Error reading from DUMMY.FIL\n");
        clearerr(stream);
    }
    fclose(stream);

    return 0;
}
