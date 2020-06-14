
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{   
    char str1[100] = "Hi everyone hope so everyone is fine ";
    char *find_str="everyone";
    char *replace_str= "everyonepp"; 
    
    char *find_ptr = NULL;    
    int replace_str_len = strlen(replace_str);
    int dif_len = (strlen(find_str) - strlen(replace_str));
    
    int add = strlen(str1)+(dif_len);
    char *str = (char*)(malloc(add));
    str = str1;


    
    if(dif_len >=0){
        while(find_ptr = strstr(str,find_str)){
            for(int i = 0;i<replace_str_len;i++){
                *(find_ptr + i) = replace_str[i];
            }
            
            for(int j=0;*(find_ptr + replace_str_len + j)!='\0';j++){
                *(find_ptr + replace_str_len + j) = *(find_ptr + replace_str_len + j + dif_len);
            }
            str = find_ptr +  replace_str_len;
        }
     }
   else{
        while((find_ptr = strstr(str,find_str))){ 
            for(int i = strlen(str);i>=(strlen(str)-strlen(find_ptr));i--){
                *(str + i + abs(dif_len) + 1) =  *(str + i +1);
            }
            
            for(int i = 0;i<replace_str_len;i++){
                *(find_ptr + i) = replace_str[i];
            }
            
                str = find_ptr +  replace_str_len;
        
        }
    }
    printf("\n%s",str1);
    return 0;
}


    








