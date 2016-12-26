#include <stdio.h>
#include <stdlib.h>

int getenv_path(void)
{
	char *path = NULL;
	path = getenv("PATH");
	if(path == NULL)
	{
		perror("get err");
		return EXIT_FAILURE;
	}
	else
	{
		printf("%s\n",path);
	}
	return EXIT_SUCCESS;
}

int main(void)
{
	getenv_path();

	return 0;
}
