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
#include<sys/wait.h>
#include<unistd.h>
#include<time.h>

//Debugging is OFF
//
#define DEBUG 0
 
#if DEBUG == 1
 		#define dbug(arg,...) printf(arg,##__VA_ARGS__)
#else
 		#define dbug(arg,...)  
#endif


/*Function Declaration Here*/


/*Global Variable Here*/


int  main(int argc,char *argv[])
{

		char ip_time[30]={0};
		char op_time[30]={0};

		char min_str[3]={0};
		char hour_str[3]={0};
		char sec_str[3]={0};
		
		/*Time in UTC Format*/
		FILE *file_ptr=NULL;

		unlink("dummy.txt");	//delete dummy.txt 	
		file_ptr = fopen("dummy.txt","a+");
		if(file_ptr == NULL)
		{
			printf("file failed to open %s\n",strerror(errno));
			exit(1);
		}

	for(int i=0;i<60;i++)
	{
		unsigned long sys_time = time(NULL);
		dbug("sys_time =%ld\n",sys_time);	
		int hours = (sys_time/3600)%(24);
		int min   = (sys_time/60)%(60);
		int sec	  = sys_time%(60) ;

		dbug("hours =%d min =%d sec=%d\n",hours,min,sec);

	/*Converting time in Indian Std
	 * Indian time is 5:30 more than UTC
	 *  Converted Time will be in 24 hrs Format*/
		
		hours+=5;
		if(hours>23)
		{
		  hours=hours-24;
		
		}
			if(hours>=10)
				sprintf(hour_str,"%d",hours);
			else
				sprintf(hour_str,"0%d",hours);

		min+=30;
		if(min>59)
		{
		  min=min-60;
		  hours++;
		}
			if(min>=10)
				sprintf(min_str,"%d",min);
			else
				sprintf(min_str,"0%d",min);

				
			if(sec>=10)
				sprintf(sec_str,"%d",sec);
			else
				sprintf(sec_str,"0%d",sec);

		
		sprintf(ip_time,"System Time: %s:%s:%s",hour_str,min_str,sec_str);
		
		if(hours>12)
		{
			/*PM Loop*/	
			if((hours-12)>=10)
				sprintf(op_time,"Normal Time: %d:%s:%s PM",hours-12,min_str,sec_str);
			else
				sprintf(op_time,"Normal Time: 0%d:%s:%s PM",hours-12,min_str,sec_str);
					
		}	
		else
		{
			/*AM Loop*/
			sprintf(op_time,"Normal Time: %s:%s:%s AM",hour_str,min_str,sec_str);	
		}
		
		printf("(24hrs) input time = %s\n",ip_time);
		printf("(12hrs) output time= %s\n\n",op_time);

	
		

		fwrite(ip_time,1,strlen(ip_time),file_ptr);
		fwrite("\n",1,1,file_ptr);
		
		fwrite(op_time,1,strlen(op_time),file_ptr);
		fwrite("\n",1,1,file_ptr);
		fwrite("\n",1,1,file_ptr);
		
		memset(ip_time,0,sizeof(ip_time));
		memset(op_time,0,sizeof(op_time));
	
		sleep(1);
	}



	if( 0 != fclose(file_ptr))
	{
		printf("Failed to close the File %s",strerror(errno));
		exit(1);
	}


return 0;
}
