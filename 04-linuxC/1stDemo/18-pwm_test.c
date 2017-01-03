#include <stdio.h>

void delay(unsigned int D_time);

void main()
{

}

void delay(unsigned int D_time)
{
    unsigned int value;
    for(value = D_time; value > 0; value --);
}
