/*******************************************************************
 *   > File Name: 07-check_product_model.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 03 Mar 2017 09:59:50 AM CST
 ******************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum product_type{
    PRODUCT_WIFI_DVR_A,
    PRODUCT_USB_DVR,
    PRODUCT_TWO_CAREMA
};

int check_product_model(void){
    char *product = NULL;
    product = getenv("product");
    if(product == NULL)
        return PRODUCT_WIFI_DVR_A;
    else{
        if(strncmp(product, "WIFI_DVR", strlen("WIFI_DVR")) == 0)
            return PRODUCT_WIFI_DVR_A;
        else if(strcmp(product ,"USB_DVR") == 0)
            return PRODUCT_USB_DVR;
        else if((strcmp(product, "TWO_CAREMA")) == 0)
            return PRODUCT_TWO_CAREMA;
        else
            return PRODUCT_WIFI_DVR_A;
    }
}

int main(int argc, char* argv[])
{
    int retval;

    retval = check_product_model();
    switch(retval){
        case 0:printf("PRODUCT_WIFI_DVR_A\n");break;
        case 1:printf("PRODUCT_USB_DVR\n");break;
        case 2:printf("PRODUCT_TWO_CAREMA\n");break;
        default:break;
    }

    return 0;
}
