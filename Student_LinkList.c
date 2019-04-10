// Implementing student Data Via Link List

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student{

char name[50];
int roll_no;
float marks;
struct student *next; 
};

void student_info(struct student **);
void display(struct student **);
void stu_search(char *,struct student **);
void delete(struct student **, char *);
void main()
{

	struct student *head=NULL;
	struct student s;
	int choice=0;
	char arr[50]={0};
	while(1)
	{
	printf("Enter Choice\n");
	printf("1.Enter New Student Log\n2.Display All  Student Data\n3.Search Student by name\n4.Delete Student\n5.Exit\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			printf("New Student Data Log\n");
			student_info(&head);
				break ;
		case 2:
			printf("<-----Display Student Data----->\n");
			display(&head);	
  				break ;
		case 3:
				printf("Search By Name\n");
				scanf("%s",arr);
				stu_search(arr,&head);
				break ;

		case 4:
				printf("Enter Name to Delete student Log\n");
				scanf("%s",arr);
				delete(&head,arr);
				break ;
		case 5:
				exit(0);
	
	}

	}
}


void student_info(struct student **p)
{
	struct student *p1;
	struct student *temp;
	p1=*p;				// Assigning Head Pointer
	int roll;
	float marks;	
	temp=(struct student*)malloc(sizeof(struct student));

	temp->next=NULL;
	printf("Enter Name\n");
	scanf("%s",temp->name);
	
	printf("Enter Roll No\n");
	scanf("%d",&roll);
	
	printf("Enter Marks\n");
	scanf("%f",&marks);

	temp->roll_no=roll;
	temp->marks=marks;

	if(*p==NULL)
	{
	  *p=temp;
	}
        	else{
	
	        	while(p1->next!=NULL)
		     {
			p1=p1->next;
		     }
		    p1->next=temp;
	
	
	       }


}

void stu_search(char *arr,struct student **p)
{
struct student *p1;
p1=*p;
  while(p1->next!=NULL)
 {
   if(!(strcmp(p1->name,arr)))
     {
		  
	printf("Student name=%s\n",p1->name);
	printf("Student Roll No=%d\n",p1->roll_no);
	printf("Student Marks=%f\n",p1->marks);
		  
     }
   p1=p1->next;
 }

  if(!(strcmp(p1->name,arr)))
     {
		  
	printf("Student name=%s\n",p1->name);
	printf("Student Roll No=%d\n",p1->roll_no);
	printf("Student Marks=%f\n",p1->marks);
		  
     }
}

void delete(struct student **p, char *arr)
{


struct student *p1;
p1=*p;
struct student *p2;
p2=*p;
struct student *temp;
int flag=0,match=0;
  while(p1->next!=NULL)
 {
	
   if(!(strcmp(p1->name,arr)))
     {
	     match=1;
	break;
     }
   p1=p1->next;		
 }

  if(match !=1)	// For Last Node
  {
   while(p2->next!=p1) // Previous Node
   {
     p2=p2->next;
   }
  
  p2->next=NULL;
  free(p1);//Last Node
  return;
  }

  
  temp=p1->next;	// temp front node

while(p2->next!=p1)	//Behind node
{
p2=p2->next;
}

p2->next=temp;
free(p1);


}






void display(struct student **p)
{
struct student *p1;
p1=*p;
 while(p1->next!=NULL)
  {
	printf("Student name=%s\n",p1->name);
	printf("Student Roll No=%d\n",p1->roll_no);
	printf("Student Marks=%f\n",p1->marks);
	p1=p1->next;
	printf("\n");
  }
	printf("Student name=%s\n",p1->name);
	printf("Student Roll No=%d\n",p1->roll_no);
	printf("Student Marks=%f\n",p1->marks);
	printf("-----------*****----------");

}



