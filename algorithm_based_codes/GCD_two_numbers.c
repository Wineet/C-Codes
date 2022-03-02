/*
 * Program Demonstrate GC functions
 * By two ways results calculated
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef unsigned long long int ul_int;
void swap(ul_int *num1,ul_int *num2);
void swap(ul_int *num1,ul_int *num2)
{
    ul_int temp=*num1;
    *num1=*num2;
    *num2=temp;
}

ul_int get_GCD(ul_int number1, ul_int number2)
{
    ul_int reminder=0;
    if(number1<number2)
        swap(&number1,&number2);
    while (number2 > 0)
    {
        reminder=number1%number2;
        number1=number2;
        number2=reminder;
    }
    return number1;
}

ul_int get_GCD2(ul_int number1, ul_int number2)
{
    ul_int GCD=1;
    ul_int max=number1>number2?number1:number2;
    for(ul_int i=1;i<=max;i++)
    {
        if(number1%i==0 && number2%i==0)
        {
            GCD=i;
        }
    }
    return GCD;
}

void main()
{
    clock_t start_time = clock();               //--> start time
  //  printf("GCD %lld\n",get_GCD(1353435541,156546545));
    printf("GCD %lld\n",get_GCD2(1353435541,1565465451));
    clock_t end_time = clock();               //--> start time

    printf("Time Taken %Lf\n",(long double)(end_time-start_time)/CLOCKS_PER_SEC);


}

//1353435541
//1575965453