/*
*This is Menu Driven program that can be run using
*user@user-VirtualBox:~$ gcc file2.c
*user@user-VirtualBox:~$ ./a.out
*
*Once you run the program, it will ask for an option. You must enter a numerical value for the program to run. Enter a number 1-5 to go through 
*
*1. Name (Enter a String value that is less than 100 characters)
*2. Age (Enter an Int value)
*3. Points (Enter a Float Value)
*4. Display (Will display the data and indicate which value are unknown)
*5. Clear  (Will clear the data)
*
*Option 6 will exit the program
*If you enter a number that is not 1-6 then the program will repeat the menu again and give directions to follow
*If you enter a any value that is not numerical, the program will crash
*/

#include <stdio.h>

/*Method: main
*Purpose: Menu driven program to input and display data of a person
*Parameters: void
*Returns: int 1
*/

int main(void){
   int num; // the number to decide which option
   char name[]="unknown";// the string for the name 
   int age; // the integer for the age 
   float points; // the integer for the points 
   int nameCount, ageCount, pointsCount;//times variables have been inputed
   
   printf("Person Menu\n");
   do{/*does the action of repeating the menu as long as num = 1-5*/
      printf("\n1. Name\n");
      printf("2. Age\n");
      printf("3. Points\n");
      printf("4. Data\n");
      printf("5. Clear\n");
      printf("6. Exit\n");
      printf("\nChoose an Option 1-6: ");
      scanf("%d",&num);
      
      switch(num){ //uses the user input "num" to go through the menu
         case 1:
            printf("\nEnter a Name: "); 
            scanf("%s",name); //gets user input name
            nameCount++;
            break;
            
         case 2:
            printf("\nEnter an Age: ");
            scanf("%d",&age); //gets user input age
            ageCount++;
            break;
            
         case 3:
            printf("\nEnter a Points Value: ");
            scanf("%f",&points); //gets user input points
            pointsCount++;
            break;
            
         case 4: //returns age,name,points data & prints message for unknown
            if(ageCount==0) {printf("\nAge is Unknown\n");}
            if(pointsCount==0) {printf("Points is Unknown\n");}
            if(nameCount==0) {
               printf("Name is Unknown\n\n");
               printf("Name: Unknown\n");
            } 
            if(nameCount>0){printf("\nName: %s\n", name);}
            printf("Age: %d\n", age);
            printf("Points: %f\n", points);
            break;
            
         case 5: 
         //resets all # variables and counters to 0 
            age = 0;
            points = 0;
            ageCount = 0;
            pointsCount = 0;
            nameCount = 0;
            break;
            
         case 6:
            printf("\nExiting the Menu\n"); //exits the menu
            break;
            
         default:
            //prints if user chooses none of the options 1-6
            printf("\n\nError: Did not input a valid option from Menu\n\n");
            break; //menu exits as a result
      }
   } 
   //as long as the user puts in a # 1-5, the menu repeats
   while(num !=6); 
  return 1; /*needed for the function to run*/
}
