#include<stdio.h>

int main()
{
char c;
printf("enter the character");
scanf("%c",&c);

if(((c=='a')||(c=='e')||(c=='i')||(c=='o')||(c=='u'))||((c=='A')||(c=='E')||(c=='I')||(c=='O')||(c=='U')))
	printf("Entered character is vowel");
else
{	printf("Entered character is not a vowel");
	}
return 0;
}
