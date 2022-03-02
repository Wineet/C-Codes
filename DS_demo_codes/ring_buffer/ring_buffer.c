#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "ring_buffer.h"
#define MIN(x,y) x>y?y:x


ringNode* ring_init(int size,int numberOfentry)
{
    ringNode *ringNode_handle= (ringNode *) malloc(sizeof(ringNode)*1);
    if(ringNode_handle==NULL)
    {
        printf("ERROR: malloc Failed %d\n",__LINE__);
        return NULL;
    }
    memset(ringNode_handle,0,sizeof(ringNode));
    ringNode_handle->start=malloc(size*numberOfentry);
    if(ringNode_handle->start == NULL)
    {
        printf("ERROR: malloc Failed %d\n",__LINE__);
        return NULL;
    }
    memset(ringNode_handle->start,0,size*numberOfentry);

    ringNode_handle->write_ptr=ringNode_handle->start;
    ringNode_handle->read_ptr = ringNode_handle->write_ptr;
    ringNode_handle->end= ringNode_handle->write_ptr + (size*numberOfentry);
    ringNode_handle->max_entry=numberOfentry;
    return ringNode_handle;
}


ret_status ring_write(ringNode* handle,void *data,int size)
{
#ifdef OVERWRITE_ENABLE
    if(handle->read_ptr == handle->write_ptr && handle->write_ptr >= handle->end )
    {
        handle->write_ptr=handle->start; //Loop Back
        handle->read_ptr=handle->start; //Loop Back
    }
    else if(handle->write_ptr >= handle->end)
    {
        handle->write_ptr=handle->start; //Loop Back
    }
    int ret_size=MIN(handle->end-handle->write_ptr,size);
    memcpy(handle->write_ptr,data,ret_size);
    if( handle->max_entry == handle->current_entry)
    {
        handle->write_ptr+=ret_size;
        handle->read_ptr+=ret_size; 
    }
    else
    {
        handle->write_ptr+=ret_size;
        handle->current_entry++;
    }
#else
    if(handle->write_ptr >= handle->end || handle->max_entry <= handle->current_entry )
    {
        // printf("Buffer is full Over Writing\n");
        handle->write_ptr=handle->start;
        return FAIL;
    }
    else
    {
        int ret_size=MIN(handle->end-handle->write_ptr,size);
        handle->current_entry++;
        memcpy(handle->write_ptr,data,ret_size);
        handle->write_ptr+=ret_size;
    }
#endif
    return SUCCESS;
}
/*Reads Data From Queue and Puts into Data_buff */
void *ring_read(ringNode* handle,void *data_buff,int data_size)
{
#ifdef OVERWRITE_ENABLE
    if( handle->current_entry==0)
    {
        // printf("Nothing to read in Buffer \n");
        return NULL;
    }
    if(handle->read_ptr >= handle->end )
    {
        handle->read_ptr=handle->start;
    }
    memcpy(data_buff,handle->read_ptr,data_size);
    handle->current_entry--;
    handle->read_ptr +=data_size;
#else
  if(handle->read_ptr == handle->write_ptr && handle->current_entry == 0)
    {
        // printf("Nothing to read in Buffer \n");
        return NULL;
    }
    else
    {
        memcpy(data_buff,handle->read_ptr,data_size);
        handle->current_entry--;
        handle->read_ptr +=data_size;
        if(handle->read_ptr >= handle->end )
        {
            handle->read_ptr=handle->start;
        }
    }
#endif
    return data_buff;
}


void print_ring_buffer(ringNode* handle,int size)
{
    printf("Ring Buffer Handle Parameter \n \
            write_ptr %p \n \
            read_ptr  %p \n \
            current_entry %d \n \
            max_entry %d \n \
            start %p \n \
            end %p \n", handle->write_ptr,handle->read_ptr,handle->current_entry, \
                        handle->max_entry,handle->start,handle->end);
    void *buff_ptr=handle->start;
    for(int i=1;i<=handle->max_entry;i++)
    {
        printf(" %d ",*(int *)(buff_ptr));
        buff_ptr+=size;
        if(buff_ptr >= handle->end)
        {
            printf("Buffer is full Over Writing");
            buff_ptr=handle->start;
        }
    }

}



void ring_destroy(ringNode** handle)
{
    (*handle)->read_ptr=NULL;
    (*handle)->write_ptr=NULL;
    (*handle)->end=NULL;
    free((*handle)->start);
    (*handle)->start=NULL;
    (*handle)->max_entry=0;
    (*handle)->current_entry=0;
    free(*handle);
    *handle=NULL;
    return;
}

int ring_entry(ringNode* handle)
{
    return handle->current_entry;
}

ret_status ring_isEmpty(ringNode* handle)
{
    return handle->current_entry !=0?FALSE:TRUE;
}

void ring_flush(ringNode* handle)
{
    handle->read_ptr=handle->start;
    handle->write_ptr=handle->start;
    handle->current_entry=0;
}