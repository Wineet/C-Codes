#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define FILE_NAME       "me.conf"
#define MAX_FILE_READ   1024
#define FILE_KEY_WORD   "bind_address"
#define MAX_SIZE_KEY    20
#define TRUE            1

void main()
{
    char conf_file_buffer[1024]={0};
    char key_ip[MAX_SIZE_KEY]={0};
    char topic[50]={0};
    FILE *conf_file_ptr=NULL;
    int return_size=0; 
    char *char_ptr=NULL;
    conf_file_ptr=fopen(FILE_NAME,"r");
    if(!conf_file_ptr)
    {
        printf("File Open Error\n");
        exit(1);
    }
    while(TRUE)
    {
        return_size=fread(conf_file_buffer,MAX_FILE_READ,1,conf_file_ptr);
    
        char_ptr=strstr(conf_file_buffer,FILE_KEY_WORD);
        if(return_size<MAX_FILE_READ)
        {
            printf("End of file reached\n");
            if(char_ptr == NULL)
            {
                printf("No Keyword Found");
                exit(0);
            }
            break;
        }
        else
        {
            if(char_ptr != NULL)
            {
                break;
            }
            continue;
        }
        
    }
    char_ptr+=sizeof(FILE_KEY_WORD);
    for(int i=0;i<MAX_SIZE_KEY;i++)
    {
        if( (char_ptr[i] ==' ') || (char_ptr[i]=='\n')  || (char_ptr[i]=='\t') || (char_ptr[i]=='\r') )
        {
            break;
        }
        else
        {
             key_ip[i]=char_ptr[i];
        }    
                
    }
    printf("Ip=%s\n",key_ip);
    sprintf(topic,"bcds/%s/General\n",key_ip);
    printf("Topic=%s\n",topic);
    fclose(conf_file_ptr);
}