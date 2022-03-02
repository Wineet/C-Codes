/*
 * Author : Vinit
 * Task: Reverse the string by words which entered by user from standard Input \
 *       and reverse the words which are separated by space. And print Final string as output.
 *	     string header File use is allowed
 *
 * Lesson Learned: 1. memcpy same pointer passed one is \
				      const argument tried to change Unknown Behaviour Observed
 *				   2. Tried to change Concat char pointer Unknown behaviour observed\
 *						As Strings are immutable
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void str_join(char *dum, char* output_str)
{
      char temp[50]={0};
      memcpy(temp,output_str,50);
      memcpy(output_str+strlen(dum),temp,48-strlen(dum));
      memcpy(output_str,dum,strlen(dum));
   // printf("dum=%s\n",dum);
     
}

int main()
{
    char input_str[50] ={0};//"Hi me Vinit Kumar myself"; // for user input change it to {0};
    char output_str[50]={0};
    char *dum = NULL;
    fgets(input_str,sizeof(input_str)-1,stdin); // for user input un comment this
	int i=0;
	for( i=0;(input_str[i]!='\n');i++);
		input_str[i]=0;						// to remove '\r' Enter Character
		
    printf("I/p= %s\n",input_str);
    
    dum=strtok(input_str," ");
    strncpy(output_str,dum,strlen(dum)+1);
    
    while(1)
    {
        char temp[20]={0};
        dum=NULL;
        dum=strtok(NULL," ");
        if(dum == NULL)
        {
            break;
        }
        strncpy(temp,dum,strlen(dum));
        strcat(temp," ");
       // printf("%s \n",dum);  // For Debug purpose
        str_join(temp,output_str);
        
    }
    
    printf("O/p= %s\n",output_str); // Final output_str
     
    return 0;
}
