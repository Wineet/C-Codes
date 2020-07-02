#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<unistd.h>

enum tm_T{tm_min,tm_hour,tm_seconds,AM,PM}a;
typedef struct tm Tstruct;
struct mytime
{
	unsigned int hours;
	unsigned int minutes;
	unsigned int seconds;
	unsigned int AMPM;

};
struct mytime convTime(int timeArr[3]);
int main()
{
	struct tm *time1=NULL;
  int timearr[8]={0,},i=0;
  struct mytime normalTime = {0,0,0,0};

  for(int j=0;j<60;j++)
  {
   const time_t time_get = time(NULL);
	time1 = localtime(&time_get);
	if(time1 == NULL) 
	{
		puts("time not found\n");
		exit(0);
	}
   timearr[tm_min] = time1->tm_min;
   timearr[tm_hour] = time1->tm_hour; 
   timearr[tm_seconds] = time_get%60;

  // timearr[tm_mon] = time1->tm_mon; 
  // timearr[tm_mon]+=1;
  // timearr[tm_year] = time1->tm_year;
   //timearr[tm_year] +=(2000-100);

  // timearr[tm_wday] = time1->tm_wday;  
  // timearr[tm_yday] = time1->tm_yday;
  // timearr[tm_isdst] = time1->tm_isdst;

 normalTime = convTime(timearr);

   printf("systime: %u : %u : %u \n ",timearr[tm_hour],timearr[tm_min],timearr[tm_seconds]);
   printf("normal : %u : %u : %u  ",normalTime.hours,normalTime.minutes,normalTime.seconds);
   if(normalTime.AMPM == AM)
   {
	   printf("AM \n");
   }
   else
   {
	   printf("PM \n");
   }


   sleep(1);
  }
}

struct mytime convTime(int timeArr[3])
{
	struct mytime CalTime ={0,0,0,0};

	if(timeArr[tm_hour]>12)
	{
		CalTime.hours = timeArr[tm_hour]-12;
		CalTime.AMPM = PM;
	}
	else
	{
		CalTime.AMPM = AM;
		if(timeArr[tm_hour]==0)
		{
			CalTime.hours = 12;

		}
		else
		{
			CalTime.hours = timeArr[tm_hour];
		}
	}
	CalTime.minutes = timeArr[tm_min];
	CalTime.seconds = timeArr[tm_seconds];
	return CalTime;

}
