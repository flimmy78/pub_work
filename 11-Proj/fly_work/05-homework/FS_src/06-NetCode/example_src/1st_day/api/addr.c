#include <stdio.h>
#include <string.h>

struct people{
        int contry;
        char name[32];
};

struct american{
        int contry;
        char eng_name[16];
        char nick_name[16];
};

struct chinese{
        int contry;
        char chi_name[32];
};

int show_name(struct people *info)
{
        struct chinese *tmp_1;
        struct american  *tmp_2;
        if(info->contry == 1)
        {
                tmp_1 = (struct chinese *)info;
                printf("name = %s\n", tmp_1->chi_name);
                return 0;
        }
        if(info->contry == 2)
        {
                tmp_2 = (struct american *)info;
                printf("name = %s\n", tmp_2->eng_name);
                return 0;
        }

        return -1;
}

int main(int argc, char *argv[])
{
        struct chinese jhq;
	struct american peter;

	jhq.contry = 1;
	strcpy(jhq.chi_name, "jihq");
	
	peter.contry = 2;
	strcpy(peter.eng_name, "peter");
	
	show_name((struct people *)&jhq);
	show_name((struct people *)&peter);


	return 0;
}
