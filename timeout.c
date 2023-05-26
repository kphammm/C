/*
*Kenneth Pham
*ID: 015145546
*CS2600, Fall 2022
*Programming Assignment #5
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
      
   
  
      
 

 


