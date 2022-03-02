

/* Bit Manupulation Sample C code */
#include<stdio.h>
#include<stdlib.h>

/* Macros for bit set and reset Operations */

#define BIT_SET(x,bitno)    x|=(1<<bitno)  
#define BIT_RESET(x,bitno)  x&=~(1<<bitno)
#define BIT_TOGGLE(x,bitno) x^=(1<<bitno)
void main()
{
    int x=0;
#ifdef TOGGLE_BIT
    int loop_i=10;
    while(loop_i--)
    {
        BIT_TOGGLE(x,0);
        printf("x = %d \n",x);
    }
#endif
#ifdef BIT_SET_RESET
    for(int i=0;i<8;i++)
    {
        BIT_SET(x,i);
        printf("x = %d \n",x);
    }
    printf("\n \n");
    for(int i=7;i>0;i--)
    {
        BIT_RESET(x,i);
        printf("x = %d \n",x);
    }
#endif

}