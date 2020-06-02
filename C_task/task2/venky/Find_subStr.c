#include<stdio.h>
#include<stdlib.h>
#define msg(x) printf("%s : ",x)
int main()
{
	char ipStr[100] = {'\0',},sub[10];
	char i=0, found =0;
	fflush(stdin);
	msg("enter string");
	scanf("%[^\n]s",ipStr);
	
	msg("enter SUBstring");
	scanf("%s",sub);
	while(ipStr[i]!= '\0' && i<101)
	{
		if(ipStr[i] == sub[0] && ipStr[i+1] == sub[1])
		{
			if(i== 0 || ipStr[i-1] == ' ')
			{
				while(i<101 && ipStr[i] != ' ' /*|| ipStr[i] != '\n' */)
				{
					printf("%c",ipStr[i]);
					i++;
				}
				found = 1;

				
			}
			printf("\n");
			
		}
   // getchar();
   i++;
	}
    if (0 == found)
    {
       msg("--->sub string not found<---");
    }

	return 0;
}
