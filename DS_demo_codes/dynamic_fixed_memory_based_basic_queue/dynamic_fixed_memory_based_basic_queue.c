#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_QUEUE_SIZE   5
#define SENSOR_COUNT 6
#define NO_ENTRY 0
//Queue Payload
int present_entry_queue = 0;
int start=0;
int end=0;

	
typedef struct {
	//unsigned int sensor[SENSOR_COUNT];
	unsigned int sensor;
}adc_val;

	adc_val *queue_start_ptr=	NULL;	// Start and End pointer for queue
	adc_val *queue_end_ptr	=	NULL;
	
typedef enum { fail=0,sucess=1}status_t;

status_t queue_init()
{

			
	     queue_start_ptr=(adc_val *) malloc(sizeof (adc_val)* MAX_QUEUE_SIZE);
		 if(NULL == queue_start_ptr)
		 {
			 return fail;			//Insufficient Memory
			//assert(0);
		 }
		 memset(queue_start_ptr,0,sizeof (adc_val)* MAX_QUEUE_SIZE); // clean Memory
		 
		 queue_end_ptr = queue_start_ptr;		
	
	return sucess;
}

status_t post_message_queue(adc_val *queue_ptr)
{
	if( MAX_QUEUE_SIZE-1 < present_entry_queue)
	{
		printf("Queue Is full Data Loss");
		return fail;
	}
	if(MAX_QUEUE_SIZE-1 == start)
	{
		start = 0;
	}
	memcpy((queue_start_ptr + start),queue_ptr,sizeof (adc_val));	//Source Destinition 
	present_entry_queue++;
	start++;			// just to increment
	
	printf("\nmessage in queue %d \n",queue_ptr->sensor);
	return sucess;
}

adc_val get_message_queue()
{
	if(NO_ENTRY == present_entry_queue)
	{
		printf("No Entry\n");		// return something Meaning full
		return;
	}
	if(MAX_QUEUE_SIZE-1 == end)
	{
		end = 0;
	}
	adc_val queue_adc_val;
	
	memset(&queue_adc_val, 0 , sizeof (adc_val));	//Clearing the buffer
	memcpy( &queue_adc_val,(queue_end_ptr + end),sizeof (adc_val));
	present_entry_queue--;
	end++;
		
	return queue_adc_val;
}

void main()
{
	if(sucess != queue_init())
	{
			exit(0);
	}
	
	while(1)
	{
		adc_val obj;
		int user_input;
		printf("\n1.Post Messgae to Queue\n2.get message to queue\n 3.queue Entry\n4.Exit\n");
		scanf("%d",&user_input);
		
		switch(user_input)
		{
			printf("\n in Switch Case\n");
			case 1:
			{
				printf("\nEnter Value to post in queue\n");
				scanf("%d",&obj.sensor);
				printf("\n obj.sensor = %d \n",obj.sensor); 
				if(fail != post_message_queue(&obj))
				{
					printf("\n *** Write Sucess ***");
					printf("\n No. of Queue Entry = %d",present_entry_queue);
					break;
				}
				printf("\n *** Write Fail ***");
				
				break;
			}
			
			case 2:
			{
				printf("\n get message to queue \n");
				obj = get_message_queue();
				printf("\n queue entry Value %d\n",obj.sensor);
				printf("\n No. of Queue Entry = %d",present_entry_queue);
					
				break;
			}
			
			case 3:
			{
				for(int i=0; i<present_entry_queue;i++)
				{
					printf("\n  Queue Entry = %d value =%d",present_entry_queue, *(queue_end_ptr + i) );
				}
				break;
			}
			
			case 4:
			{
				printf("\n Exiting....");
				exit(0);
				break;
			}
			
			default:
			{
				printf("\nNo Valid Input\n");
				break;
			}
		}
		
		
		
	}
	printf("\n Hello World \n");
	
	
}