/*
 * Author:   vinit 
 * Task:     --Here--
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
//#include<sys/wait.h>		// file giving Error at windows side
#include<unistd.h>

#define DEBUG 0
 
#if DEBUG == 1
 		#define dbug(arg,...) printf("Debug:"arg,##__VA_ARGS__)
#else
 		#define dbug(arg,...)  
#endif

#ifdef __linux__
char *ip_cmd = " ifconfig | grep -a \"inet \" | tail -n 1 >my_ip.txt ";
#endif

#ifdef _WIN32
char *ip_cmd = " ipconfig | findstr \"IPv4\"  > my_ip.txt ";
#endif

/*Function Declaration Here*/


/*Global Variable Here*/


int  main(int argc,char *argv[])
{
	char ip_buff[200]={0};
	char ip_buff1[200]={0};
		FILE *file_ptr = NULL;
		
#ifdef __linux__
	dbug("Linux OS\n");
#endif

#ifdef _WIN32
	dbug("Windows OS\n");
#endif

	if(-1 == system(ip_cmd))
		// gets only last line of ip //considering last line of i[ will be of wifi
	{
		printf(" IP command Failed\n");
		exit(1);
	}

	file_ptr = fopen("my_ip.txt","r");
	if( NULL == file_ptr)
	{
		printf("File Opening Error\n");
		exit(1);
	}

		int i=0;

		while(1)
		{
			if(0==fread(ip_buff+i,1,1,file_ptr))
			{
				break;
			}
			if ( i > (sizeof(ip_buff)/sizeof(char)) )
			{	
				printf("ip_buffer Overflow\n");
				exit(1);	
			}
			else
			{
				i++;
			}
		}
		
#ifdef __linux__

		dbug("strlen(ip_buff)=%d",strlen(ip_buff));
		char *dum1 = strstr(ip_buff,"inet ");
		char *dum2 = strstr(dum1,"netmask");
		dbug(" dum1=%s\n",dum1);
		dbug(" dum2=%s\n",dum2);
		strncpy(ip_buff1,dum1+5,(dum2-dum1)-5 );
#endif

#ifdef _WIN32

char* dum1=strtok(ip_buff,":");
		char *dum=dum1;
		while(NULL != dum)
		{
			dum = strtok(NULL,":");
			if(dum != NULL)
			{
				dum1=dum;
			}
		}
		
	dbug("Ip = %s\n",dum1+1);
	strncpy(ip_buff1,dum1+1,strlen(dum1+1));
#endif 

	printf("IP = %s\n",ip_buff1);
	fclose(file_ptr);
	unlink("my_ip.txt");


return 0;
}
