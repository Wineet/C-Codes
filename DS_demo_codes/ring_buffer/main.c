/*
 * Dynamic Ring Buffer Code 
 * Author : Vinit
 * Machine: Linux Personal PC
 * Platform: Linux
 * */

#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include"ring_buffer.h"

int main()
{
    ringNode *ring1_handle= ring_init(sizeof(int),10);
    int read_buff;
    for(int i=1;i<22;i++)
    {
        if( FAIL ==ring_write(ring1_handle,&i,sizeof(int)))
        {
            printf("Writing Failed Over write Not allowed\n");
        }
    }
    print_ring_buffer(ring1_handle,sizeof(int));
    printf("\ncurrent entry count %d \n reading started \n",ring_entry(ring1_handle));
    for(int i=1;i<12;i++)
    {
        if(NULL ==ring_read(ring1_handle,(void *)&read_buff,sizeof(int)))
        {
             printf("Buffer is empty Nothing to read\n");
            /*Buffer empty*/
        }
        else
        {
            /* print read data */
            printf("%d ",read_buff);
        }
    }
    if(TRUE==ring_isEmpty(ring1_handle))
    {
        printf("Buffer is empty\n");
        ring_destroy(&ring1_handle);
    }
    
    
return 0;
}