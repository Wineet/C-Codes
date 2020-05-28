#include<stdio.h>
void main()
{
    int i, N, Sum=0, k;
    printf("Enter an integer number to check if it's a PERFECT No. or Not ");
    scanf("%d",&N);
    for (i=1; i<=N; i++)
    {
        if (N%i == 0)
        {
          Sum = Sum + i;
          k = Sum/2;
        }
    }
if (k == N)
 {
    printf("\n %d is a PERFECT NUMBER.",N);
 }
else 
printf("\n %d is not a PERFECT NUMBER.",N);
}