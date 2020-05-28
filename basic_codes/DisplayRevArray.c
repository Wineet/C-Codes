
//Display and reverse display the array element


#include<stdio.h>
void display(char *,int);

int main()
{
    int x=5;
     printf(" char in  Name\n");
    scanf("%d",&x);
  
     printf("Enter the Name(%d char)\n",x);
     
       x++;           //because \n or \r taken as a character input from keyboard
    char name[x];
         for(int i=0;i<x;i++)
         {
         scanf("%c",&name[i]);
         }
         //char *p=(char *)(&name+1);
        display((char *)(&name+1),x);   //   &name+1 is imp to get last address
      
 return 0;
}

 void display(char *p,int size)
 {
    printf("Entered string\n");

     for(int  i=size;i>0;i--)
   {
    printf("%c",*(p-i));
    }
      
   printf("\n");
   printf("reverse string\n");

   for(int  i=0;i<=size;i++)
   {
    printf("%c",*(p-i));
   }
    printf("\n");
}
    
  
   
 
