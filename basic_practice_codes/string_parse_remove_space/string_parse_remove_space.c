#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main()
{
    char ip_buffer[]={"7E 0A 0B CD 1A 2B 2C 2D"};
    char op_buffer[50]={0};

    for(int i=0,j=0;i<strlen(ip_buffer);i++)
    {
        if(ip_buffer[i]!= ' ')
        {
            op_buffer[j]=ip_buffer[i];
            j++;
        }
    }
    printf("Input string= %s\n",ip_buffer);
    printf("Output string=%s\n",op_buffer);

}