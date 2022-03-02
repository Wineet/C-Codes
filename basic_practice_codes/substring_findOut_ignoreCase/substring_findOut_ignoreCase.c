/*
 * Author:   vinit 
 * Task:     Implementing strstr C function by ignoring case sensitive ness
 *			 Function should return char * after sucess incase of fail NULL should return 
 * Hw  : 	   R-pi 3B+
 * Platform: Linux
 *
 */


#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>


/*Function Declaration Here*/

char * my_substr(const char * , const char*);
/*Global Variable Here*/


int  main(int argc,char *argv[])
{
	char main_str[50]={0};
	char sub_str[50]={0};
    printf("Enter Main String: ");
    fgets(main_str,50,stdin);
    printf("Enter Sub String: ");
    fgets(sub_str,50,stdin);

	printf(" Sub string =%s\n",my_substr(main_str,sub_str));

/*---- Write code here ---*/


return 0;
}


char *my_substr(const char * main_str,const char * sub_str)
{
	int l=0;
	int j=0;
	
		for(int i=0; *(main_str+i) != '\0' || *(main_str+i) != '\n' ;i++)
			if( (*sub_str<97?*(sub_str)+32:*(sub_str)) == ( *(main_str+i)<97?*(main_str+i)+32:*(main_str+i) ) )
			{
				for( j=0,l=i;*(sub_str+j)!= '\0' || *(sub_str+j)!= '\n' ;j++,l++)
				{
					if( ( *(sub_str+j)<97?*(sub_str+j)+32:*(sub_str+j) ) != ( *(main_str+l)<97?*(main_str+l)+32:*(main_str+l) ) )
					{
						break;
					}
				}
				if(*(sub_str+j) == '\0' || *(sub_str+j) == '\n' )
					return (char *)main_str+i;
			}
		
	   
	printf("Stirng Not Found\n");
	return (char *)NULL;

}
