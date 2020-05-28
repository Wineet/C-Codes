// Implementing Stack

#include<stdio.h>
#include<stdlib.h>
#define stack_size 5
int pop(int *, int *);
void push(int *, int ,int *);
void display(int *, int *);


void main()
{
int choice=0,num=0;
int stack[stack_size]={0};	// Stack of size of 5
int sp=0;	// Stack pointer
//int *stack_p=&sp;
  while(1)
  {
printf("Enter The Choice\n");
printf("1.Push\n2.Pop\n3.Display Stack\n4.Exit\n");
scanf("%d",&choice);
	switch(choice)
	{
	case 1:
		printf("Enter the Number To be pushed\n");
		scanf("%d",&num);
		push(stack,num,&sp);
		break;
	case 2:
		printf("Popped NUmber=%d\n",pop(stack,&sp));
		break;
	case 3:
		printf("Stack Displaying\n");
 		display(stack, &sp);
		break;
	case 4:
		exit(0);


	}

  }
}

void push(int *stack,int num,int *sp)
{
	if(*sp>=5)
	{
	printf("Stack Is Full\n");
	return ;
	}
	stack[*sp]=num;
	(*sp)++;
}

int pop(int *stack,int *sp)
{
	if(*sp<=0)
	{
        	 printf("Stack is Empty");
  		 return 0;
	}

      int num=stack[*sp-1];
       stack[*sp]=0;
	(*sp)--;
	return num;
}

void display(int *stack, int *sp)
{

 	for(int i=0;i<(*sp);i++)
	{
		printf("%d\n",stack[i]);
	}

}

