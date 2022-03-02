// Nested Calls

#include<stdio.h>

//sqrt(pow(2,abs(x)) ) // putchar( toupper(ch) )


int pow1(int , int );

float sqr(int );
int val(int );

void main()
{
    int x,y;
 printf("Enter The Number\n");
 scanf("%d",&x);
  printf("Enter The Power\n");
 scanf("%d",&y);
 printf("%f\n", sqr(pow1(x,val(y)) ) );



 
}


float sqr(int num)  // Finding square root
{
    float low=0,low2=0;
    int i=1;
    while( pow1(i,2) <=num )
    {
        if(pow1(i,2)==num)
        {
            return i;
        }
         low=i;
         i++;
    }
    low2=low;
    low=((float)num)/low;  
    low=(low+low2)/2;  
    low=((float)num)/low;
    return low;
}

int pow1(int x, int y)
{
    int z=x;
    if(y==0)
    { 
         return 1;
    }
    for(int i=1;i<y;i++)
    {
        z=z*x;
    }

return z;
}

int val(int num)
{
    if(num>0)
    {
        return num;
    }
    else
    {
        num=~(num)+0x01;    
        return num;
    }


}