/*
* Author: Vinit
*
* Current example is Demo of divide and conquer algorithm
* Using this algorithm to print an array
* Using this algortihm to Find Max Number
*/


#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int arr[100000]={1,2,8,4,5};

void swap(int *first , int *second)
{
    int temp=*first;
    *first=*second;
    *second=temp;
}
void print_arr(int left_index,int right_index)
{
    if(right_index==left_index)
    {
        printf("%d ",arr[left_index]);
        return;
    }

    int center=(left_index+right_index)/2;
    print_arr(left_index,center);
    print_arr(center+1,right_index);

}

int  max_num_arr(int left_index,int right_index)
{

    if(right_index==left_index)
    {
        return arr[left_index];
    }
    int center=(left_index+right_index)/2;
    int max_left=max_num_arr(left_index,center);
    int max_right=max_num_arr(center+1,right_index);

    return max_left>max_right?max_left:max_right;
}

int max_number_loop(int arr[],int size)
{ 
    int max=0;
    for(int i=0;i<size;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
    }
    return max;
}

void main()
{
     
     for(int i=0;i<100000;i++)
     {
         arr[i]=rand();
     }
    
    int array_length=sizeof(arr)/sizeof(int);
    clock_t start_time = clock();               //--> start time
    //print_arr(0,array_length-1);
    int max_no=max_num_arr(0,array_length-1);
    clock_t end_time   = clock();
    printf("\n Max arry_no %d \n time taken1 %Lf\n",max_no,(long double)(end_time-start_time)/CLOCKS_PER_SEC);

    start_time = clock();  
    max_no=max_number_loop(arr,array_length);
    end_time   = clock();
    printf("\n Max arry_no %d \n time taken2 %Lf\n",max_no,(long double)(end_time-start_time)/CLOCKS_PER_SEC);

}