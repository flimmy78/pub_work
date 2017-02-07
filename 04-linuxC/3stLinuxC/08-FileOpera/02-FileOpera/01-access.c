#include <unistd.h>
#include <stdio.h>

#if (0)
int access(const char *pathname, int mode);
#endif

#define TEST_DIR "./TEST/test"

int main(void)
{
    if(access(TEST_DIR, F_OK) == 0)
    {
        printf("%s is OK\n",TEST_DIR);
    }
    else
    {
        printf("%s is not OK\n",TEST_DIR);
    }

    return 0;
}
