#include<stdio.h>

int main()
{
int fact=1,n,flag;
printf("enter the number whose factorials you want");
scanf("%d",&n);
print("enter the number");

if(n!=0)
{
	while(n>0)
	{
	fact=n*fact;
	n--;
	}
}
else
	fact=1;



printf("the factorial of %d is %d",n,fact);


return 0;
}
