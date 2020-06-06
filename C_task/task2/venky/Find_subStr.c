
#include<stdio.h>
#include<stdlib.h>
/*My changes Here*/
#define msg(x) printf("%s : ",x)

char * strstr_case_insensitive(const char *ipStr,const char *sub);
int main()
{
	char ipStr[100] ={'\0',},sub[100];
	char i=0, found =0;
	char * ptr =NULL;
	fflush(stdin);
	msg("enter string");
	scanf("%[^\n]s",ipStr);
	msg("enter SUBstring");
	scanf("%s",sub);
	ptr = strstr_case_insensitive(ipStr,sub);
    if (NULL == ptr)
    {
       msg("--->sub string not found<---");
    }
    else
    {
	    printf("-------\n%s\n-------\n",ptr);
    }

	return 0;
}
char * strstr_case_insensitive(const char *ipStr,const char *sub)
{
	char * point = NULL;
	int i = 0,j= 0;
	for(i=0;ipStr[i]!= '\0';i++)
	{
		if(((ipStr[i]>=97?ipStr[i]:ipStr[i]+32) ==(sub[j]>=97?sub[j]:sub[j]+32 ) )&& (i==0 || ipStr[i-1]== ' '))
		{
              		for(j=0;ipStr[i]!='\0' && sub[j]!='\0';i++,j++)
	      		{
				
		               if((ipStr[i]>=97?ipStr[i]:ipStr[i]+32) !=(sub[j]>=97?sub[j]:sub[j]+32 ) )
				{
					break;
				}
		      
	      		}


			if(sub[j] == '\0')
			{
				point = (char *)ipStr+i-j;
				break;
			}
			else
			{
				j=0;
			}
			
		}

               
	}

	return point;
}
