// Implemented simple queue
//ONLY



#include<stdio.h>
#include<stdlib.h>

#define queue_size 5

void insert(int *, int *,int,int * );

int delete(int *, int *,int *);
void display(int *,int *,int *);

void main()
{
 int choice=0;
 int num=0;
 int rear=-1,front=-1;
 int queue[queue_size]={0};
 
 while(1)
 {
   printf("1.Insert In queue\n2.Delete In queue\n3.Display queue\n4.Exit\n");
   printf("Enter the choice\n");
   scanf("%d",&choice);

  switch(choice)
 {
	 case 1:
		 printf("Enter Element to insert\n");
		 scanf("%d",&num);
		insert(&rear,&front,num,queue);
		break;
	 case 2:
		 printf("Deletied item in queue=%d\n", delete(&rear,&front,queue));
		 break;
	 case 3:
         	printf("Display Members of queue\n");
		display(&rear,&front,queue);
		break;
	case 4:
		exit(0);
 }

}

}
void insert(int *rear, int *front,int num,int *queue)
{

	 if( (*rear)>=5 )
	{
	printf("Queue Is Full");
	return ;
	}
	
	if( (*front) ==-1)
	{
		(*front)++;
	}

	++(*rear);
	queue[*rear]=num;

}


int delete(int *rear, int *front,int *queue)
{

	if(*front>0)
	{
          printf("Queue Is Empty\n");
	}

   int del_num=0;
   del_num=queue[*front];
   queue[*front]=0;

   if((*front)==(*rear))
   {
        *front=-1;
	*rear=-1;
     printf(" Values Reset\n");	
   return 0;
   }
   (*front)++;

  return del_num;

}

void display(int *rear,int *front,int *queue)
{
	if(*front<0){
		printf("\nQueue is Empty\n");
	}

	for(int i=(*front);i<=(*rear);i++)
	{
		printf("%d\n",queue[i]);

	}

}


