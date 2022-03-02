/*
 * File parser Code 
 * Author : Vinit
 * Machine: Linux Personal PC
 * Platform: Linux
 * */

#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

#define MAX_FILE_NAME 20
#define MAX_LINE_LENGTH 50

void main(int argc,char *argv[])
{

	int ret_val=0;
	int file_fd=0;
    char prev_line[MAX_LINE_LENGTH]={0};
    char curr_line[MAX_LINE_LENGTH]={0};
    FILE *fp=NULL;
    char *line=NULL;
    size_t len = 0;
    ssize_t read;
    int line_number=1;
	//char read_buf[20]={0};
	if(1 == argc || (strlen(argv[1]) > MAX_FILE_NAME ) )
	{
		printf("No Argument or Max Size exceed\n");
		exit(EXIT_FAILURE);
	
	}
    fp=fopen(argv[1],"r");
    printf("Opening File %s\n",argv[1]);
    if(fp == NULL)
    {
        printf("file Open Failed \n");
         exit(EXIT_FAILURE);
    }
    while ((read = getline(&line, &len, fp)) != -1) 
    {
        strcpy(curr_line,line);
        if(0==strcmp(prev_line,curr_line))
        {
            printf("Duplicate Match at line %d\n",line_number);
            printf("%s", line);
        }
        strcpy(prev_line,curr_line);
        line_number++;
    }

    fclose(fp);
    if (line)
    {
        free(line);
    }
    
    printf("Done at line %d\n",line_number);
    return;
}