#include<stdio.h>
void main()
{   int first = 0, second = 1, n, i; 
    printf("Number of Fibonacci digits to be displayed = ");
    scanf("%d",&n);
    printf("%d,",first);
    if (n < 1) 
        return; 
  
    for (i = 1; i <= n; i++) 
    { 
        
        printf("%d,", second); 
        int next = first + second; 
        first = second; 
        second = next; 
    } 
}