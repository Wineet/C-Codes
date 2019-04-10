//Dynamic Memory allocation program

#include<stdio.h>
#include<stdlib.h>
void main()
{
	
int *p=(int *)malloc(sizeof(int)*4);

p[0]=1;
p[1]=2;
p[2]=3;
p[3]=15;
p=realloc(p,sizeof(int)*2);
p[4]=20;
p[5]=22;
        for(int i=0;i<6;i++)
	{
       printf("%d\n",*(p+i));
	}

//printf("%p\n",*q);// segmentation Fault .
/*
int *p=(int *)malloc(20*sizeof(int));

        for(int i=0;i<20;i++)
	{
         printf("%d\n",*(p+i));
        }
*/

}
