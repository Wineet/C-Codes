/******************************************************************************
Author: Vinit
Task: simple Stack Data structure Code
     It is not dynamic stack which grows as per entries
     it is fixed stack entry, initilised at the time of creation
     

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _stack_handle{
    void *stack_pointer;
    void *stack_start_addr;
    int max_entry;
    int entry_count;
    int entry_size;
    
}stack_handle;
typedef enum { SUCCESS=0,FAIL=1}ret_s;

stack_handle *stack_create(int entry,int size);
ret_s stack_push(stack_handle *s_ptr ,void *data);
ret_s stack_pop(stack_handle *s_ptr,void *data);
void stack_destroy(stack_handle *s_ptr);

int main()
{
    stack_handle *s_handle=stack_create(10,sizeof(int));
    if(s_handle==NULL)
    {
        printf("stack Not created\n");
        exit(1);
    }
    // printf("Init SP %p\n",s_handle->stack_pointer);
    for(int i=1;i<11;i++)
    {
        stack_push(s_handle,&i);
    }

    for(int i=1;i<4;i++)
    {
        int x=0;
       if(FAIL != stack_pop(s_handle,&x))
       {
            printf("data %d",x);
       }
    }
    stack_destroy(s_handle);
    return 0;
}


stack_handle *stack_create(int entry,int size)
{
    stack_handle *s_ptr=NULL;
    s_ptr=malloc( sizeof(stack_handle));
    if(s_ptr == NULL)
    {
        return NULL;
    }
    s_ptr->stack_pointer=malloc(size*entry);
    if(s_ptr->stack_pointer==NULL)
    {
        free(s_ptr);
        return NULL;
    }
    s_ptr->max_entry=entry;
    s_ptr->entry_size=size;
    s_ptr->stack_start_addr=s_ptr->stack_pointer;
    s_ptr->entry_count=0;
    return s_ptr;
}

ret_s stack_push(stack_handle *s_ptr ,void *data)
{
    if(data==NULL || s_ptr==NULL)
    {
        return FAIL;
    }
    if(s_ptr->entry_count >= s_ptr->max_entry)
    {
        printf("stack is full\n");
        return FAIL;
    }
    if(s_ptr->entry_count!=0)
    {
        s_ptr->stack_pointer+=s_ptr->entry_size;
    }
    memcpy(s_ptr->stack_pointer,data,s_ptr->entry_size);
    s_ptr->entry_count++;
    // printf("Push SP %p\n",s_ptr->stack_pointer);
    return SUCCESS;
}

ret_s stack_pop(stack_handle *s_ptr,void *data)
{
    if(s_ptr==NULL||data==NULL)
    {
        return FAIL;
    }
    if(s_ptr->entry_count==0)
    {
        printf("stack is empty\n");
        return FAIL;
    }
    // printf("pop SP %p\n",s_ptr->stack_pointer);
    memcpy(data, s_ptr->stack_pointer, s_ptr->entry_size);
    if(s_ptr->entry_count!=1)
    {
        s_ptr->stack_pointer-=s_ptr->entry_size;
    }
    s_ptr->entry_count--;
    return SUCCESS;
}

void stack_destroy(stack_handle *s_ptr)
{
    if(s_ptr==NULL)
    {
        return;
    }    
    if(s_ptr->stack_start_addr!= NULL && s_ptr->stack_pointer != NULL )
    {
        free(s_ptr->stack_start_addr);
        s_ptr->stack_start_addr=NULL;
        s_ptr->stack_pointer=NULL;
    }
    free(s_ptr);
}



