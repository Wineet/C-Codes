/* Author: Vinit
   Task:  variable value Swapping
*/

#include<stdio.h>
#include<stdlib.h>

void swap_number(int *x,int *y);
#define SWAP(x,y) 	x=x^y,y=x^y,x=x^y
void main()
{
	int x=10,y=12,z=15;
	//swap_number(&x,&y);
	SWAP(x,y);
	printf("x=%d y=%d\n",x,y);	
	
	
	/* Find Bigger and smaller Number in 3/2 Numbers*/
	printf("big num= %d \n",x>y?x:y);	// Bigger Number reutrned
	printf("big num= %d \n",x>y?y:x);	// smaller Number returned

	printf("big num= %d \n",x>y?(x>z?x:z):(y>z?y:z));
	printf("small num= %d \n",x<y?(x<z?x:z):(y<z?y:z));

return;
}


void swap_number(int *x,int *y)
{
	*x= *x ^ *y;
	*y= *x ^ *y;
	*x= *x ^ *y;
}
