// Author: Vinit
// Task:   Dynamic Memory allocation program

#include<stdio.h>
#include<stdlib.h>
void main()
{	
	int *p=(int *)malloc(sizeof(int)*4);
	if(p==NULL)
	{
		printf("Memory allocation Failed\n");
		exit(1);
	}
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
	free(p);
}
