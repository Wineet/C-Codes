#include<stdlib.h>  
#include<stdio.h>
#include<string.h>
int main() 
{

char *p = (char*)malloc(10000);
FILE *File_Pointer;
char Search_win[] = "IPv4 Address. . . . . . . . . . . : ";
char Search_lin[] = "inet ";
char File_Data_buffer[10000];


remove("dummy.txt");

#ifdef _WIN32
{
	printf("Operating System: Windows OS\n");
	system("C:\\Windows\\System32\\ipconfig > dummy.txt"); 
	File_Pointer = fopen("dummy.txt","r");

	if(File_Pointer != NULL){
				fread(File_Data_buffer,sizeof(File_Data_buffer),1,File_Pointer);
		
		p = strstr(File_Data_buffer,Search_win);
		p = strstr(p+0,Search_win);

		if(p != NULL)
			printf("My IP = %.15s",p+strlen(Search_win));
}
	fclose(File_Pointer );

}
#elif __linux__
{
	printf("Operating System: Linux OS\n");
	system("/sbin/ifconfig > dummy.txt"); 

	File_Pointer = fopen("dummy.txt","r");

	if(File_Pointer != NULL){
				fread(File_Data_buffer,sizeof(File_Data_buffer),1,File_Pointer);
		p = strstr(File_Data_buffer,Search_lin);
		while((strstr(p,Search_lin)))
		{
			p += 1;
		}
			
		//p = strstr(p+x,Search_lin);

		if(p != NULL)
			printf("My IP = %.15s",(p-1)+strlen(Search_lin));
}
	fclose(File_Pointer );

}
#else
{
	printf("Operating System: Not a Windows or Linux OS\n");
	return 0;
}
#endif

remove("dummy.txt");
return 0;
} 