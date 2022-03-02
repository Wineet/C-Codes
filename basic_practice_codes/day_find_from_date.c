//Author Vinit
//Day Find out calender Program


#include<stdio.h>

void main()
{

    int const r_day=1,r_month=1,r_year=1970;
int days=0,month=0,year=0,year1=0,month_sum=0;
int flag=0;
int arr[13]={31,28,31,30,31,30,31,31,30,31,30,31};

char *week[8]={"Thursday","Friday","Saturday","Sunday","Monday","Tuesday","Wednesday"};

printf("Enter\n Day  Month  Year\n");
scanf("%d%d%d",&days,&month,&year);

year1=year;
    while( r_year!=year1)
    {
            if(year1%4==0 &&(year1%100!=0 || year1%400==0) ){
            flag++;
            }
            year1--;
    }
  printf("flag %d \n",flag);
    printf("Year1 %d \n",year1);
    printf("Year %d \n",year);

     for(int i=0;i<month-1;i++)
    {
      month_sum=month_sum+arr[i];
    }

    if(flag!=0)
    {  
      month_sum+=flag;
    }

year=year-r_year;
year=year*365;
days=month_sum+year+days;
days=days-1;
printf("%d Number of days\n",days);
while(days>=7)
{
days=days-7;
}
printf("\n %d Number of days \n",days);
printf("%s\n",week[days]);
}

