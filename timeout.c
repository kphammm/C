/*
*This is timeout program 
*user@user-VirtualBox:~$ gcc file2.c
*user@user-VirtualBox:~$ ./a.out
*
*Once you run the program, it will scan for the input, which must be given in this format
*
*filename -t #
*
*# is the seconds the program will sleep for
*
*the program will print out the time the terminal has been idle and the last modification time
*
*/

#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <signal.h>

/*Method: main
*Purpose:program to timeout
*Parameters: void
*/

int main(void){

   char name[]="unknown";// the string for the "file name"
   char option[]="unknown"; //contains the string "-t"
   float seconds = 10; //contains count for seconds
   time_t currentTime;
   struct stat filestat;

   scanf("%s",name); //scans file name    
   scanf("%s",option); //scans for "-t"
   
      
   //if -t is inputed in option, then seconds is scanned
   if(strcmp("-t", option) ==0){
      scanf("%f",&seconds); //scans for amount of seconds
      
      while(1){
         sleep(seconds); //program goes to sleep
         stat(name, &filestat); //gets the last modtime of the file
         time(&currentTime);//gets the current time
         
         float modTime = difftime(currentTime, filestat.st_mtime); //gets the time difference from last mod time to current
         printf("Modification Time: %f seconds\n", modTime);
         printf("File Last Changed: %s\n", ctime(&filestat.st_mtime));
        
        //if the modtime is at least greater than the seconds, then kill is called
         if(modTime >= seconds){
           kill(getpid(), SIGKILL);
         }
     } 
   }      
}
      
   
  
      
 

 


