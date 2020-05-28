#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define messege(x) printf("%s\n",x)
#define messege1(x) printf("%s ",x)
int i = -1;

char** input()
{
   static char **ip = NULL, ch;						
   int ix=0,j=0;
   while((ch = getchar()) != '\n')
   {
      if(ch == ' ' || ch == ',' || i == -1)  		  // <Vinit: why ',' delimeter is here >
      {
        if(i!= -1 && ip!= NULL && ip[i]!= NULL)
        {
           ip[i] = realloc(ip[i],(j+1)*sizeof(char)); //<Vinit: realloc returns void pointer typede\
																casting is missing >
           ip[i][j] = '\0';
           j=0;
           
        }
         i++;
         ip = realloc(ip,(i+1)*sizeof(char**));
         if(ip == NULL) messege("realloc failed");
         //messege("-1 or spl char i++");
         if(i==0 && ch != ' ' && ch!= ',')
         {
            ip[i] = realloc(ip[i],(j+1)*sizeof(char));	//<Vinit: for every Char you are performing realloc\
															>
            ip[i][j] = ch;
            j++;
														//<Vinit: I think this whole realloc thing can be\
																 avoide if you took input as string not as character by character>
         }
      }
      else{
      ip[i] = realloc(ip[i],(j+1)*sizeof(char));
      ip[i][j] = ch;
      j++;
      }
      
   }
   ip[i] = realloc(ip[i],(j+1)*sizeof(char));
      ip[i][j] = '\0';
      
      
      
      
   return ip;
}

char ** logic(char** ip)
{
   char *temp;   
   int ix=0,iy =i;
   for(ix =0;ix<=iy;ix++,iy--)
   {
      temp= ip[ix];
      ip[ix]= ip[iy];
      ip[iy]=  temp;
   }
   return ip;
   
}
void output(char **array)
{
   int ix;
      for(ix=0 ;ix<=i;ix++)
      {
         messege1(array[ix]);
      }
}
int main()
{
   char **array = NULL;
   int ix = 0;
   messege("enter string below");
   
 
 output(logic(input()));
  
                 


   
}