#include<stdio.h>
#include<math.h>

int main()
{
    int Num, n, rem, result = 0, k = 0 ;

    printf("Enter an integer: ");
    scanf("%d", &Num);

     n = Num;
    
    while (n != 0)
    {
        n = n/10;
        ++k;
    }

    n = Num;

    while (n != 0)
    {
        rem = n%10;
        result += pow(rem, k);
        n = n/10;
    }

    if(result == Num)
        printf("%d is an Armstrong Number.", Num);
    else
        printf("%d is not an Armstrong Number.", Num);

    return 0;
}
/* USE  gcc -o try try.c -lm  TO COMPILE...*/