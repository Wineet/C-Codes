/*
 * Program Demonstrate Power function
 * By two ways results calculated
 *
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef unsigned long long int ul_int;
ul_int power(ul_int num,int pow);

ul_int power(ul_int num,int pow)
{
  printf("num=%lld pow=%d \n",num,pow);
    if(pow==0)
        return 1;
    if(pow == 1)
        return num;
    if(pow%2==0)
      return  power(num*num,pow/2);
    else
      return power(num*num,pow/2)*num;
}

ul_int power2(ul_int num,int pow)
{
    ul_int result=num;
    if(pow==0)
        return 1;
    for(int i=0;i<pow-1;i++)
        result*=num;
    return result;
}
void main()
{
    clock_t start_time = clock();               //--> start time
    printf("power(4,2) %lld\n",power(2,50));
   // printf("power(4,2) %lld\n",power2(2,50));
    clock_t end_time = clock();               //--> start time

    printf("Time Taken %Lf\n",(long double)(end_time-start_time)/CLOCKS_PER_SEC);



}