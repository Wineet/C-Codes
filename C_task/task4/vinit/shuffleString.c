#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* find_string_in_main(char * , char * );

void main()
{
	
	char main_str[50]="hellorlowd";
	char find_str[50]="world";
		printf(" Main Str =%s\n",main_str);
		printf(" find Str =%s\n",find_str);
		printf("Result = %s\n",find_string_in_main(main_str ,find_str));

		memset(main_str,0,50);
		memset(find_str,0,50);
		strcpy( main_str,"myNameIstiniv");
		strcpy(find_str,"vinit");
		printf(" Main Str =%s\n",main_str);
		printf(" find Str =%s\n",find_str);
		printf("Result = %s\n",find_string_in_main(main_str ,find_str));
		
		memset(main_str,0,50);
		memset(find_str,0,50);
		strcpy( main_str,"hellorolwdhi");
		strcpy(find_str,"world");
		printf(" Main Str =%s\n",main_str);
		printf(" find Str =%s\n",find_str);
		printf("Result = %s\n",find_string_in_main(main_str ,find_str));
		
		memset(main_str,0,50);
		memset(find_str,0,50);
		strcpy( main_str,"Goodpumorningne");
		strcpy(find_str,"pune");
		printf(" Main Str =%s\n",main_str);
		printf(" find Str =%s\n",find_str);
		printf("Result = %s\n",find_string_in_main(main_str ,find_str));
	
		memset(main_str,0,50);
		memset(find_str,0,50);
		strcpy( main_str,"Goodmorning");
		strcpy(find_str,"morningGood");
		printf(" Main Str =%s\n",main_str);
		printf(" find Str =%s\n",find_str);
		printf("Result = %s\n",find_string_in_main(main_str ,find_str));	
	
}


char * find_string_in_main(char *main_str,char *find_str)
{
	
	int k=0,section_count=0,char_count=0;
	char formed_arr[50]={0};				// took Hard Coded For Now
	
	int find_str_size=strlen(find_str);
	int main_str_size=strlen(main_str);
	if(main_str_size < find_str_size)
	{
		printf("Main string is small to search\n");
		return 0;
	}
	
	for(int j=0;j<main_str_size-strlen(find_str)+1;j++)
	{	
		// Loop Responsible For New Section
		//Make string here
		memset(formed_arr,0,sizeof(formed_arr));	// clear array
		for(int i=section_count;i<strlen(find_str)+section_count;i++)
		{
			strncat(formed_arr,main_str+i,1);	
		}
		section_count++;
	//	printf("Formed String %s\n",formed_arr );		// For Debugging
	
		for(int i=0;i<find_str_size;i++)
		{
			for(int j=0;j<find_str_size;j++)
			{
		//		printf("Comparing Char %c %c\n", formed_arr[j],find_str[i]);
				if( formed_arr[j] == find_str[i] )
				{
					j=find_str_size;	//once Hit Found skip this Loop
					char_count++;
		//			printf("char_count =%d \n",char_count);
					
				}
			
			}
			if( (i+1) != char_count)
			{
				char_count=0;
			}
			
		}
		if(char_count == strlen(find_str))
			{
				return "Yes";
			}
			else{
				char_count = 0;
			}
	
	}
	return "No";
}

