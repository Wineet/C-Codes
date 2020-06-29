
#include<stdio.h>
#include <string.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>

int check_input_format (char *string);
void Time (char * buf);
void Dummy_File(char *System_time, char *string );
FILE *filePointer ; 
void decide_time_string();
int main ()
{
remove("Dummy_file.txt");

for(int i = 0; i<60; i++){
    sleep(1);
    decide_time_string();
}
printf("The file is now closed.") ;   
   
  return 0;
}

void decide_time_string(){
    
  char string[12];
  char System_time[12];
  char temp[11];
  char buffer[3];
  Time(string);

  for (int i = 0; i < 11; i++)
    {
      temp[i] = string[i];
      System_time[i] = string[i];
    }

  int yy = atoi (strtok (temp, ":"));


  if ((yy <= 23) && (yy >= 13))
    {

      yy = yy - 12;

    if (yy < 10)
	{
	  sprintf (buffer, "0%d", yy);
	  string[0] = buffer[0];
	  string[1] = buffer[1];

	}
    else
	{
	  sprintf (buffer, "%d", yy);
	  string[0] = buffer[0];
	  string[1] = buffer[1];
	}
      string[8] = 'P';
      string[9] = 'M';
      string[10] = '\0';
    }
    else
    {
      string[8] = 'A';
      string[9] = 'M';
      string[10] = '\0';
    }
  printf ("System time: %s\n", System_time);
  printf ("Normal time: %s\n", string);
  
  Dummy_File(System_time,string);    
    
}

void Time (char * buf)
{
  time_t now;
  struct tm ts;
  
  time (&now);
  ts = *localtime (&now);
  //for online GDB we have to write [now = now + 19800;]
 
  now = now;
  ts = *localtime (&now);
  strftime (buf, 12, "%H:%M:%S", &ts);
  
}


void Dummy_File(char *System_time, char *string ) 
{ 
    filePointer = fopen("Dummy_file.txt", "a") ; 
    if ( filePointer == NULL ) 
    { 
        printf( "Dummy_file.c file failed to open." ) ; 
    } 
    else
    { 
        fputs("System_time: ", filePointer) ;
        fputs(System_time, filePointer) ;
        fputs("\n", filePointer) ;
        fputs("Normal_time: ", filePointer) ;
        fputs(string, filePointer) ;
        fputs("\n", filePointer) ;
        fclose(filePointer) ; 
    } 
      
}