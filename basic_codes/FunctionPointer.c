//
// Q 12. Passing function names as parameters
// void test(int x, int y, int (*fp) (int,int))
// {
// int z = fp(x,y);
// ----
// }
// test(10,20,sum)

#include<stdio.h>

int sum(int x,int y);
int test(int , int , int (*) (int,int));

void main()
{

printf("Answer=%d\n",test(10,20,sum));
printf("function Add=%p\n",&sum);
}

int test(int x, int y, int (*fp) (int x,int y))
{
int z = fp(x,y);
return z;
}

int sum(int x,int y)
{
  x=x+y;
  return x;
}