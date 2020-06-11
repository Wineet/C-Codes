#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//read string : alloc
//find string : strstr
//replace


char *getStr(void);
char *findAndReplace(char *replaceIn,char *findThis,char* replaceWith);

int main()
{
	char *mainStr = NULL,*findStr = NULL,*repWithStr =NULL,*newStr=NULL;
	puts("enter main str :");
	mainStr = getStr();
	puts("enter str to find :");
	findStr = getStr();
	puts("enter str to replace :");
	repWithStr = getStr();
	newStr = findAndReplace(mainStr,findStr,repWithStr);
   if(NULL != newStr)
      printf("%s\n",newStr);
   else
      printf("\n ====>no match found for \"%s\" in \"%s\"\n",findStr,mainStr);

	return 0;

}
char *getStr(void)
{
	char *str = NULL,ch=0;
   unsigned int Allocate = 0U;
	
	while((ch=getchar()) != '\n')
	{
		str = (char*)realloc(str,(Allocate+1)*sizeof(char));
		str[Allocate] = ch;
		Allocate++;
	}
	str = (char*)realloc(str,(Allocate+1)*sizeof(char));
	str[Allocate] = '\0';
	//Allocate++; //check

	return str;

	
}
char *findAndReplace(char *replaceIn,char *findThis,char* replaceWith)
{
   char *str = NULL;
	unsigned int lenFindStr = strlen(findThis);
	unsigned int lenRepStr = strlen(replaceWith);
   char found =0;
   unsigned int mainLen = 0U;
	str = strstr(replaceIn,findThis);
   
	while(str != NULL)
	{
    // puts("founddddddd"); 
      found = 1U;
      if(lenFindStr > lenRepStr)
      {
         // <--shift and deallocate
         strncpy(str,replaceWith,lenRepStr);
         
         
         memmove((str+lenRepStr),(str+lenFindStr),strlen(str+lenFindStr)+1);
         //memset((str+strlen(replaceIn)),'\0',diff - strlen(replaceIn));
        
         replaceIn = (char*)realloc(replaceIn,strlen(replaceIn)+1);
         

      }
      else if(lenFindStr < lenRepStr)
      {
         //allocate and --> shift
         
         //ven mahind
         //venkatesh 
         mainLen =strlen(replaceIn);
         printf("mainStr->%s\n",replaceIn);
        
         replaceIn = (char*)realloc(replaceIn,(mainLen+(lenRepStr-lenFindStr)+1));
         memmove(/*str+(lenRepStr-lenFindStr)+1 */str+lenRepStr,str+lenFindStr,strlen(str+lenFindStr)+1);
         printf("      1->%s\n",replaceIn);
         //strncpy(str,replaceWith,lenRepStr);
         memmove(str,replaceWith,lenRepStr);
         printf("  %ld   2->%s\n",strlen(replaceIn),replaceIn);
         str = str+lenRepStr;
         printf("Update3->%s\n",str);
        

      }
      else
      {
         strncpy(str,replaceWith,lenRepStr);

      }
      
      str = strstr(str,findThis);
	}
	if(found == 0)
	{
      
//		printf("\n--------------\nno match found\n--------------\n");
      return NULL;
	}	
	return replaceIn;

}
