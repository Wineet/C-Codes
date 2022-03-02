/* Using this Program to Find max subsequce in an array
 *
 *
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int arr[]={4,-3,5,-2,-1,2,6,-2};

int max_sub_seq(int *arr,int array_length)
{
    int sum=0;
    int max_subseq=0;
    /*
    * Below loop works on logic, if sum is greater than 0 
    * which means the sequence until which it got added is worth to add, 
    * if it is less than zero sum will get restored and recent max sum will be stored
    * 
    * Limitation : array will have positive integers too
    * max_subseq > 0
    * If Entire array is with -ve numbers it will show zero
    */
    for(int i=0;i<array_length;i++)
    {   
        sum+=arr[i];
        if(sum>max_subseq)
        {
            max_subseq=sum;
        }
        else if(sum<0)
        {
            sum=0;
        }
    }
    return max_subseq;
}
void main()
{

    int array_length=sizeof(arr)/sizeof(int);

    printf("max_subSeq %d \n",max_sub_seq(arr,array_length));

}