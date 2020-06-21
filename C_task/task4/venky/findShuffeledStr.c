#include<stdio.h>
#include<string.h>
#include<stdlib.h>



void sort(char *arr);
int main()
{
	char SubStr[100] = "venkatesh",MainStr[100] = "hsetaknev";
	char subTemp[100]={'\0',},mainTemp[100]={'\0',},temp3[100]={'\0',};
	int i=0,lentExceed =0;



   puts("enter main str:");
   fscanf(stdin,"%s",MainStr);
   puts("enter sub str:");
   fscanf(stdin,"%s",SubStr);
   //copy strings in temp strings
   strcpy(subTemp,SubStr);
	strcpy(mainTemp,MainStr);
   
   /*
   * check if string length of mainStr and SubStr is same or not
   * ---> if it is same then sort both the strings and compare 
   * -----> if comparision is successful then string shuffeled string exist
   * -----> else no match
   */  
	if(strlen(SubStr)==strlen(MainStr))
	{
      /*
      * if both strings are same there is match 
      * string found!!
      * and exit
      */
		if(0==strcmp(SubStr,MainStr))
		{
			printf("\n---------------------------\nstring exist\n---------------------------\n");
			exit(0);
		}
      //sort both strings 
		sort(subTemp);
		sort(mainTemp);
      //if match found --> string exists
		if(0==strcmp(subTemp,mainTemp))
		{
			printf("\n---------------------------\nshuffeled string exist\n---------------------------\n");
			exit(0);
		}
		else
		{
			printf("\n---------------------------\nshuffeled string does not exist\n---------------------------\n");
			exit(0);

		}


	}
   /*if substring is bigger than mainstring then perfect match will not be there*/
   else if(strlen(SubStr)>strlen(MainStr))
   {
      printf("\n---------------------------\nshuffeled string does not exist\n---------------------------\n");
      exit(0);
   }
   //if substring length is less than MainStr
	else
	{
      //if direct occurance of substring is there in mainstr then match found
		if(NULL!=strstr(MainStr,SubStr))
		{
			printf("\n---------------------------\nstring exist\n---------------------------\n");
			exit(0);
		}
      //if direct occurance not found
		else
		{
         /*
         * check for the first occurance of the characters of MainStr in SubStr
         * if occurance found the copy strlen(SubStr) number of elements from substring from adderss of occurance of the character in Temp3
         * make temp3 a string by adding '\0'
         * now sort subTemp and temp3
         * if comparision successful then match found
         */

         
         for(i=0;i<strlen(MainStr);i++)
         {
            char *strr= NULL;
            if(NULL!=(strr=strchr(SubStr,MainStr[i])) && (strlen(MainStr+i)>=strlen(SubStr)))
            {
              
               if((strlen(MainStr+i)==strlen(SubStr)))
               {
                  lentExceed++;
               }                  
               strncpy(temp3,MainStr+i,strlen(subTemp));

               temp3[strlen(SubStr)]= '\0';
             
               sort(subTemp);
               sort(temp3);
              
               if(strcmp(subTemp,temp3) == 0)
               {
                  printf("\n---------------------------\nshuffeled string exist!! \n---------------------------\n");
                  exit(0);
               }
               
            }
            
         }
         //if(lentExceed == 1)
           // {
               printf("\n---------------------------\nstring match not found\n---------------------------\n");
               exit(0);
            //}
		}
	}

}

void sort(char *arr)
{
   unsigned char i=0,j=0;
   
   for(i=0;arr[i]!= '\0';i++)
   {
      for(j=0;j<strlen(arr)-1;j++)
      {
         if(arr[j]>arr[j+1])
         {
            arr[j]=arr[j]^arr[j+1];
            arr[j+1]=arr[j]^arr[j+1];
            arr[j]=arr[j]^arr[j+1];
         }
    //     printf("sort : %s\n",arr);
      }
   }
  // printf("\nsort :\n%s\n",arr);
}

