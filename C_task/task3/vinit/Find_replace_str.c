#include<stdio.h>
#include<string.h>
#include<stdlib.h>


void main()
{
	char arr_ip[50]={0};		//	"Hello Vinit you are Vinit in pune";
	char arr_sub_str[50]={0};	//	"Vinit";
	char replace_str[50]={0};	// "Vinay";
	char output_str[50]={0};
//Enable if want to get user input
#if 1	
	printf("Enter Input String\n");
	fgets(arr_ip,50,stdin);
	memset(arr_ip+strlen(arr_ip)-1,0,2);			// to remove '\n' and '\r'
	printf("Enter Find String\n");
	fgets(arr_sub_str,50,stdin);
	memset(arr_sub_str+strlen(arr_sub_str)-1,0,2);
	printf("Enter Replace String String\n");
	fgets(replace_str,50,stdin);
	memset(replace_str+strlen(replace_str)-1,0,2);
#endif
	printf("Entered String >> %s\n",arr_ip);
	printf("Enterd sub string >> %s\n",arr_sub_str);
	printf("Enterd replace string >> %s\n",replace_str);
	char *next_itr=arr_ip;
	int output_buff = 0;
	//while( NULL != strstr(arr_ip+next_itr,arr_sub_str))
	//for(int i=0;i<3;i++)
	while(1)
	{
		char *FirsStradd = strstr(next_itr,arr_sub_str);
			//	printf("First Add =%s\n",FirsStradd);
		if( NULL != FirsStradd )
		{
			strncpy(output_str+output_buff,next_itr, ( FirsStradd - next_itr ));
			//printf("output = %s\n",output_str);
			strcat(output_str+output_buff,replace_str);
			next_itr = FirsStradd + strlen(arr_sub_str);
			output_buff = strlen(output_str);
		}
		else{
				strcat(output_str+output_buff,next_itr);
				break;
		}
		
		
	}
		printf(" output_str = %s \n",output_str);
}
