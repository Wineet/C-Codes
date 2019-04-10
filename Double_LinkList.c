// Implementing Double link list


#include<stdio.h>
#include<stdlib.h>

struct node{
	        struct node *prev;
		int val;
		struct node *next;
};


void display(struct node **);
void InsertEnd(struct node **,int );
void InsertPos(struct node **,int ,int);
void DeletePos(struct node **, int );
void Rev_display(struct node **);
void main()
{

	struct node *head=NULL;			// To keep starting address

	int choice=0,num=0,pos=0;
	while(1)
	{
         	printf("Enter a choice\n");
        	printf("1.Enter At End\n2.Display List\n3.Insert At position\n4. Delete At Pos\n5.Rev_Display\n6.Exit\n");
		scanf("%d",&choice);

		switch(choice)
		{
		case 1:
			printf("Enter Value to insert at End\n");
			scanf("%d",&num);
			InsertEnd(&head,num);
			break;
		case 2:
			printf("<----Display List---->\n");
			display(&head);
			break;
		case 3:
			printf("Enter Value\n");
			scanf("%d",&num);
			printf("Enter Position\n");
			scanf("%d",&pos);
			InsertPos(&head,num,pos);
			break;
		case 4:
			printf("Enter the position to be deleted\n");
			scanf("%d",&pos);
			DeletePos(&head,pos);
			break;
		case 5:
			printf("<---Rev_Disp--->\n");
                         Rev_display(&head);
			break;
		case 6:
			exit(0);

	
		}

	}
}


void InsertEnd(struct node **p,int num)
{
 struct node *temp;
 struct node *p1;
 p1=*p;				// Assign head value

 temp=(struct node *)malloc(sizeof(struct node));
temp->prev=NULL;
 temp->val=num;
 temp->next=NULL;

 if(*p==NULL)
{
 *p=temp;		// Assigning head value
}
	else
     {
        while(p1->next!=NULL)
	{
		p1=p1->next;
	}
	p1->next=temp;
	temp->prev=p1;
    }

}

 void InsertPos(struct node **p,int num,int pos)
{
 struct node *p1;
 struct node *temp;
struct node *p2;
p1=*p;
p2=*p;

 temp=(struct node *)malloc(sizeof(struct node));
temp->prev=NULL;
 temp->val=num;
 temp->next=NULL;

        for(int i=1;i<pos;i++)// Ahead Positon
        {
           p1=p1->next;
        }
	for(int i=2;i<pos;i++)// Behind position
	{
	  p2=p2->next;
	}
	temp->next=p1;
	temp->prev=p2;
	p2->next=temp;
	p1->prev=temp;
}

void DeletePos(struct node **p, int pos)
{
 struct node *p1;
 struct node *p2;
struct node *temp;
 p1=*p;
p2=*p;

        for(int i=1;i<pos;i++)// Ahead Positon
        {
           p1=p1->next;
        }
	temp=p1;
	p1=p1->next;

	for(int i=2;i<pos;i++)// Behind position
	{
	  p2=p2->next;
	}
	p2->next=p1;
	p1->prev=p2;
	free(temp);



}

void display(struct node **p)
{
 struct node *p1;
 p1=*p;
     while(p1->next!=NULL)
     {
	printf("%d\n",p1->val);
        p1=p1->next;
     }

  printf("%d\n",p1->val);

}			

void Rev_display(struct node **p)
{
struct node *p1;
p1=*p;
  while(p1->next!=NULL)
  {
   p1=p1->next;
  }
  while(p1->prev!=NULL)
  {
	printf("%d\n",p1->val);
	p1=p1->prev;
  }
	printf("%d\n",p1->val);

}

			/*
			if(p1->next==NULL)
			{
         		printf("***Invalid Position***\n");
			return;
			}*/

