
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    // const char input_string[] = "myNameIstiniv";
    // char Find_shuffled_String[] = "vinit";
    
    // const char input_string[] = "Goodpumorningne"; 
    // char Find_shuffled_String[] = "pune";
    
    // const char input_string[] = "Goodmorning"; 
    // char Find_shuffled_String[] = "morningGood"; 
    
    const char input_string[] = "hellorolwdhi"; 
    char Find_shuffled_String[] = "world";
    
    int n = strlen(Find_shuffled_String);
    int Output = 0,i,j,k;
    
    char Temp_String[n*2];
    char Temp_Find_shuffled_String[n + 1];
    
    strcpy(Temp_String,Find_shuffled_String);
    strcat(Temp_String,Find_shuffled_String);
    printf("input_string = %s\n",input_string);
    printf("Find_shuffled_String = %s\n",Find_shuffled_String);
   
    for(i=0;i<n;i++){
     
        for(j=0;j<n;j++){
            Temp_Find_shuffled_String[j] = Temp_String[i+j];
        }
        Temp_Find_shuffled_String[j] = '\0';
      
        if(strstr(input_string,Temp_Find_shuffled_String)){
            Output = 1;
        }

    }
    
     for(i=n*2;i>n;i--){
        for(k=i;k>i-n;k--){
            Temp_Find_shuffled_String[i-k] = Temp_String[k-1];
        }
        Temp_Find_shuffled_String[i-k] = '\0';
        
        if(strstr(input_string,Temp_Find_shuffled_String)){
            Output = 1;
        }

    }

    for(int m = 0;m<1000;m++){
        for (int l = 0; l < n; ++l) {
            Temp_Find_shuffled_String[l] = Find_shuffled_String[rand() % n];
        }
        Temp_Find_shuffled_String[n] = '\0';
        
        if(strstr(input_string,Temp_Find_shuffled_String)){
            Output = 1;
        }    
    }


    if( Output == 1)
        printf("Output = YES");
    else
        printf("Output = NO");
        
    return 0;
}

