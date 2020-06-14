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
free(mainStr);
free(findStr);
free(repWithStr);
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

	return str;

	
}

/***************************************************************************************************************************
* while doing realloc for findStr<ReplaceStr we need to take care of reallocation address
* in case if page size for string is not available then the address of allocated memory may change 
* in this case we also need to change our strstr pointer address if not done so the strstr return pointer will point to 
* previous memory location.
****************************************************************************************************************************/
char *findAndReplace(char *replaceIn,char *findThis,char* replaceWith)
{
   char *str = NULL;
	unsigned int lenFindStr = strlen(findThis);
	unsigned int lenRepStr = strlen(replaceWith);
	unsigned int PtrDiff = 0;   // to check difference between current allocated address and strstr return pointer

   char found =0;
   unsigned int mainLen = 0U;
	str = strstr(replaceIn,findThis);
   
	while(str != NULL)
	{
      found = 1U;
      if(lenFindStr > lenRepStr)
      {
         // <--shift and deallocate
         strncpy(str,replaceWith,lenRepStr);
         
         
         memmove((str+lenRepStr),(str+lenFindStr),strlen(str+lenFindStr)+1);
        
         replaceIn = (char*)realloc(replaceIn,strlen(replaceIn)+1);
         if(NULL == replaceIn)
         {
            puts("realloc failed");
            exit(0);
         }	

      }
      else if(lenFindStr < lenRepStr)
      {
         //allocate and --> shift
         
         mainLen =strlen(replaceIn);
         PtrDiff = str - replaceIn; //finding strstr current pointer
         replaceIn = (char*)realloc(replaceIn,(mainLen+(lenRepStr-lenFindStr)+1));
         if(NULL == replaceIn)
         {
            puts("realloc failed");
            exit(0);
         }

         memmove(replaceIn+PtrDiff+lenRepStr,replaceIn+PtrDiff+lenFindStr,strlen(replaceIn+PtrDiff+lenFindStr)+1); //updating pointer
         memmove(replaceIn+PtrDiff,replaceWith,lenRepStr);
         str = replaceIn+PtrDiff+lenRepStr;
        

      }
      else
      {
         strncpy(str,replaceWith,lenRepStr);

      }
      
      str = strstr(str,findThis);
	}
	if(found == 0)
	{
      
      return NULL;
	}	
	return replaceIn;

}
