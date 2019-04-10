#include<stdio.h>

typedef union cors{
	char name[20];
	int id;
}crs;
struct student{
	char name[20];
	crs course;
};

void main(){
	struct student s1;
	char ch;
	printf("Enter name: ");
	scanf("%s",s1.name);
	printf("Enter course or course id\n1> Name\n2> ID\n");
	getchar();
	scanf("%c",&ch);
	if(ch==1){
		printf("Enter course name\n");
	scanf("%s",s1.course.name);}
	else{
		printf("Enter course id\n");
	scanf("%d",&s1.course.id);}
	printf("----------entered student record-------------\n");
	printf("Name= %s\n",s1.name);
	if(ch==1)
	printf("course name= %s\n",s1.course.name);
	else
		printf("course id= %d\n",s1.course.id);
}
