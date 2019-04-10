#include<stdio.h>

int main()
{
int a,b;
printf("enter the values of two no.");
scanf("%d",&a);
scanf("%d",&b);
printf("before swap a=%d, b=%d",a,b);
a=a+b;
b=a-b;
a=a-b;
printf("\nafter swap a=%d, b=%d",a,b);
return 0;
}

	
