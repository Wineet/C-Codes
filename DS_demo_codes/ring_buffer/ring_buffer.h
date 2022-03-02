
#ifndef RING_BUFFER_H
#define RING_BUFFER_H

/* Over Write of ring buffer is  enabled and disable controller by below Macro*/

#define OVERWRITE_ENABLE
//#undef  OVERWRITE_ENABLE

typedef struct _ring{

    void *write_ptr;        // Pointer which is used to write
    void *read_ptr;          // Points to End of Pointer
    int   current_entry;            // Number of Entries allowed
    int   max_entry;
    void *start;             // Holds start address allocated Memory
    void *end;             //pointer holds last address

}ringNode;

typedef enum{
    SUCCESS=0,
    FAIL=1,
    TRUE=0,
    FALSE=1
}ret_status;

ringNode* ring_init(int size,int numberOfentry);
ret_status ring_write(ringNode* handle,void *start,int size);
void *ring_read(ringNode* handle,void *data_buff,int data_size);
void ring_destroy(ringNode** handle);
int ring_entry(ringNode* handle);
ret_status ring_isEmpty(ringNode* handle);
void ring_flush(ringNode* handle);
void print_ring_buffer(ringNode* handle,int size);
ret_status ring_write(ringNode* handle,void *data,int size);
#endif