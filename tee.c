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

#define MAX_LINE 1024

/*Method: main
*Purpose:program subset of tee
*Parameters: void
*/

int main(void){

   char tee[]="unknown";// the string for tee
   char line[MAX_LINE]; //contains the string for lines
   
   char fileName[MAX_LINE]; //contains the string "-t"
    FILE *file;
    int condition = 1;

   scanf("%s",tee); //scans file name   
   
      
   //if -t is inputed in option, then seconds is scanned
   
      if(strcmp("tee", tee) ==0){
      	
         scanf("%s",line);
         if(strcmp("-a", line) == 0){
            scanf("%s\n",fileName);
            file = fopen(fileName , "a");
            while(condition == 1){
      	       
      	        fgets(line, MAX_LINE, stdin);
      	        if(strcmp(line,"quit\n")==0){
      	           fclose(file);
      	           break;
		}
      	        fputs(line, file);
      	        
      	        printf("%s",line);
      	        
      	        
            }
         }
         else{
           //file name is in line
            
            file = fopen(line , "w");
	    while(condition == 1){
      	      fgets(fileName, MAX_LINE, stdin);
      	        if(strcmp(fileName,"quit\n")==0){
      	           fclose(file);
      	           break;
		}
      	        fputs(fileName, file);
      	        
      	        printf("%s",fileName);
       	    } 
	 }
         
      }
      
           
}
      
   
  
      
 

 


