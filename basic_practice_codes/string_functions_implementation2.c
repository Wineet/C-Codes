
/* Program include all user defined String Function 
 *
 * 
 */

#include<stdio.h>
#include<stdlib.h>

char *my_strcpy(char *dest, char *src);
int my_strlen(char *src);
int my_strcmp(char *dest, char *src);
char *my_strcat(char *dest, char *substr);

void main()
{
    char str_buff[512]={0};
 #if 1
    my_strcpy(str_buff,"I_am_vinit");
    //printf("str_buff %s",str_buff);
    //printf("cmp_res = %d\n",my_strcmp("VinitQ","VinitQ"));
 #endif
    my_strcat(str_buff," From Pune");
    printf("str_buff %s",str_buff);

    return;
}

char *my_strcpy(char *dest, char *src)
{
    int src_str_lenght= my_strlen(src);
    int loop_i=0;
    printf("strLen =%d ",src_str_lenght);
    while(src_str_lenght--)
    {
        dest[loop_i]=src[loop_i];
        loop_i++;
    }
return dest;
}

int my_strlen(char *src)
{
    int str_len=0;
    while(*src++)
    {
        str_len++;
    }
    return str_len;
}

int my_strcmp(char *dest, char *src)
{
    int dest_lenght = my_strlen(dest);
    int src_lenght  = my_strlen(src);
    int ret =0;
    int loop_i=0;
    if( 0 == (ret=dest_lenght - src_lenght) )
    {
        while(dest_lenght--)
        {
                if(dest[loop_i] != src[loop_i])
                {
                    return dest[loop_i] - src[loop_i];
                }
                loop_i++;
        }
        return 0;
    }
    else
    {
        return ret>0?1:-1;
    }

}


char *my_strcat(char *dest, char *substr)
{
    int dest_str_lenght=my_strlen(dest);
    int sub_str_lenght=my_strlen(substr);
    int loop_i=0;
    while(sub_str_lenght--)
    {
        dest[dest_str_lenght+loop_i]=substr[loop_i];
        loop_i++;
    }
    return dest;
}