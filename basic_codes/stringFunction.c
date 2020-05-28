// Q1. Define your own iterative functions for
// (using array notation as well as exclusively using pointers)

// i) finding a substring in a main string
// j) Whether a string starts or ends with a particular sub string

#include<stdio.h>

int str_len(char *);
void str_cpy(char *,char *);
int str_cmp(char *,char *);
void str_rev(char *,char *);
void str_concat(char *,char *, char *);
void str_ch_occ(char *,char );
int str_first_occ(char *,char );
int occ_num(char *,char );

void main()
{

   char str[50];
   char str1[50];
   char str_cat[100];

   char user_ch=0;
   int length=0;
 
      printf("Enter a string \n");
      fgets(str,50,stdin);
      length=str_len(str);
      printf("string Length=%d\n",length);
      str_cpy( str1,str);
      printf("string copy=%s\n",str1);
      printf("string cmp=%d\n",str_cmp(str1,str));
      str_rev(str1,str);
      printf("string Rev=%s\n",str1);
      str_concat(str,str1,str_cat);
      printf("Concat string=%s\n",str_cat);
      printf("Enter a char to see occurance of it\n");
      scanf("%c",&user_ch);
      str_ch_occ(str,user_ch);
      printf("First Ch occ.=%d\n",str_first_occ(str,user_ch) );
      printf("Number of occ.=%d\n",occ_num(str,user_ch) );

}



int str_len(char *str)
{
 int flag=0;    
    while(*str!='\0')
    {
    ++flag;
    str++;
    }
  return flag;
}

void str_cpy(char *str_d,char *str_s)
{   
 while(*str_s!='\0')
    {
         (*str_d)=(*str_s);
         (str_s)++;
         (str_d)++;
    }
      
     *(str_d)='\0';
    
}

int str_cmp(char *str_d,char *str_s)
{   
    int flag=0;
         while(*str_s!='\0')
            {
               if(  (*str_d)!=(*str_s))
               {
                  flag++;
               }
                  (str_s)++;
                  (str_d)++;
         }
            if(flag!=0)
            {
               return 0;
            }
            return 1;
}

void str_rev(char *str_d,char *str_s)
{
   int len=0;
  len=str_len( str_s);
 while(*str_s != '\0')
 {
     str_s++;
 }
    str_s--;
    int i=0;
    for(i=0;i<len;i++)
    {
       str_d[i]= *(str_s);
        str_s--;
    }
 str_d[i]='\0';
  

}

void str_concat(char *str_d,char *str_s, char *str_cat)
{
  int len_s=str_len(str_s);
  int len_d=str_len(str_d);
      len_s=len_s+len_d;
  while(*str_d !='\0')
  { 
   *str_cat = *str_d;
   str_cat++;
   str_d++;
  }
  while(*str_s !='\0')
  { 
   *str_cat = *str_s;
   str_cat++;
   str_s++;
  }
  *str_cat='\0';
}

void str_ch_occ(char *str_s,char user_ch)
{
  int flag=1;
  while(*str_s!='\0')
  {
      if(user_ch==*str_s)
      {
        printf("char at Position=%d\n",flag);
      }
      flag++;
      str_s++;
  }
}

int str_first_occ(char *str_s,char user_ch)
{
  int flag=1;
  while(*str_s!='\0')
  {
      if(user_ch==*str_s)
      {
        return flag;
      }
      flag++;
      str_s++;
  }
   return 0;
}

 int occ_num(char *str_s,char user_ch )
 {
    int flag=0;
    while(*str_s!='\0')
    {
      if(user_ch==*str_s)
       {
           flag++;
       }  
      str_s++;
    }
     return flag;
 }