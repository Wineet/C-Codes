	#include<stdio.h>
int add(int,int);
int mul(int,int);
int div(int,int);
int sub(int,int);

int main()
{
int a=0,b=0;
char c=0;
printf("Enter Arthematic\n\n");
scanf("%d %c %d",&a,&c,&b);
switch(c)
{
	case '+':
	 printf("Result=%d\n",add(a,b));
         break;
	case '*':
	 printf("Result=%d\n",mul(a,b));
        break;
	case '/':
	b==0?printf("Infinte"): printf("Result=%d\n",div(a,b));
	 break;
	case '-':
	 printf("Result=%d\n",sub(a,b));
	 break;

	default:
         printf("Wrong\n");
        break;


}

return 0;
}

int add(int x,int y)
{
int result=0;
result=x+y;
return result;
}

int mul(int x,int y)
{
int result=0;
result=x*y;
return result;
}

int div(int x, int y)
{
int result=0;
	
        result=x/y;
                 return result;

}

int sub(int x, int y)
{
int result=0;
result=x-y;
return result;

}


