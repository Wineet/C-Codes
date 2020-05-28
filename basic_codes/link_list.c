#include<stdio.h>
#include<stdlib.h>
struct node{
int val;
struct node *next;

};


void InsertAtend(struct node **,int );
void InsertAtbeg(struct node **,int );
void display(struct node *);
void InsertAtpos(struct node **,int ,int );
void deleteLastNode(struct node **);

void main()
{
struct node  *start=NULL;
int choice=0,val=0,pos=0,del=0;
while(1)
{
  printf("Enter the choice\n");
  printf("1.Insert at End \n2.Display\n3.Enter at Beg\n4.Insert At position\n5.Delete Last Node\n6.Exit\n");
  scanf("%d",&choice);
 
  
	switch(choice)
	{
	case 1: 
		printf("Enter the Number\n");
		scanf("%d",&val);
		InsertAtend(&start,val);
		break;
	case 2:
                printf("\n------------------------\n");
		display(start);
		break;
	case 3:
		printf("Enter the Number Beg\n");
		scanf("%d",&val);
		InsertAtbeg(&start,val);
		break;
	case 4:
		printf("Enter the value\n");
		scanf("%d",&val);
		printf("Enter the position\n");
		scanf("%d",&pos);
		InsertAtpos(&start,val,pos);
		break;

	case 5:
		printf("Delete Last Node");
		deleteLastNode(&start);
		break;
	case 6:
        	exit(0);
	}
   }
}


void InsertAtend(struct node **p,int val)
 {
struct node *temp;
struct node *t;
t=*p;
temp=(struct node *)malloc(sizeof(struct node));
temp->val=val;		///user defined value
temp->next=NULL;	// block pointer	

  if(*p==NULL)  
  {
   *p=temp;
  }
  else
  {
       while(t->next!=NULL)
      {
	t=t->next;
      }
	t->next=temp;  
     
  }

}

void InsertAtbeg(struct node **p,int val)
{
struct node *temp;
temp=(struct node *)malloc(sizeof(struct node));
temp->val=val;
temp->next=*p;
*p=temp;
}

void display(struct node *p)
{
 while(p->next!=NULL)
 {
 printf("%d\n",p->val);
  p=p->next;
   }
 printf("%d\n",p->val);
}


void InsertAtpos(struct node **p,int val,int pos)
{
struct node *temp;
struct node *p1;
struct node *p2;

p1=*p;		// Taking two extra pointer
p2=*p;

temp=(struct node *)malloc(sizeof(struct node));
temp->val=val;
temp->next=NULL;
	for(int i=1;i<pos;i++)	// AFTER block pointer is set
	{
	  p1=p1->next;
	}

	for(int j=2;j<pos;j++) // before inserting block pointer is set
	{
         	p2=p2->next;
	}
   temp->next=p1;
  p2->next=temp;

}

void deleteLastNode(struct node **p)
{
 struct node *del;
 struct node *del1;
 del=*p;
 del1=*p;
  while(del->next!=NULL)  // Deleting Node
  {
    del=del->next;
  }

  while(del1!=del)  // Previous Node 
  {
    del1=del1->next;
  }

 del1->next=NULL;// Assign Null to Last Location
 free(del);	// Free last location.
}





