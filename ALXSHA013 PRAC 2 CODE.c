#include <stdio.h>
#include <math.h>
//creating constants
#define TITLE "DECIMAL TO RADIX-i converter"
#define AUTHOR "Shaun"
#define YEAR "2022"



int main(void)
{
   printf("*******************************\n");
   printf(TITLE "\n");                     //print TITLE defined earlier to ouput terminal
   printf("Written by: "  AUTHOR "\n"); //print NAME defined earlier leaving a space
   printf("Date: "  YEAR "\n");         //print YEAR defined earlier leaving a space
   printf("*******************************");
   int d, r, result, rem;
   int decValue, radValue;  //initialise variables
   double log;
   int answer;

     while (d>=0){                         //loop to run code continiously while user input is positive

     printf("\nEnter a decimal number: ");
     scanf("%d", &d);                         //scan user decimal input into memory
     if (d<0)                                //checks if user input is negative and exits loop if so
     {
        printf("EXIT");
     }
     else if (d>=0)
     {
        printf("The number you have entered is ""%d" ,d); //display user decimal input on screen
        printf("\nEnter a radix for the converter between 2 and 16: ");
        scanf("%d", &r);                         //scan user radix input into memory
        printf("The radix you have entered is " "%d" ,r);//display user radix input on screen

        log = log2(d);    //find log base 2 of the number
        printf("\nThe log2 of the number is " "%.2f" ,log); //print float with two decimal points

        result = d/r;          //result of number divided by radix

        printf("\nThe integer result of the number divided by " "%d", r);
        printf(" is " "%d", result);

        rem = d%r;            //use modulo to find remainder
        printf("\nThe remainder is ""%d", rem);
        printf("\nThe radix-""%d",r ); printf(" value is " );
        answer = Dec2RadixI(d,r);

     }}

   return;
  }

  void Dec2RadixI(int decValue, int radValue){
    int i, n=0, remainder;             //intitialise variables
    char radChars[]= "0123456789ABCDEF";     //create array of base characters to be used
    char answer [64]; //create array to store values - max 64 characters

    for(n=0; n<(decValue)*64 || n==0; n++){               // for loop to run through characters ensuring correct number of bits
        remainder = decValue%radValue;   //find modulo to indexed against chars
        decValue = decValue/radValue;     // keep dividing until remainder is less than radix
        answer[n] = radChars[remainder];  //store each character corresponding to remainder value in an array

    }
    for(i = n-1; i>=0;i--){            // for loop to reverse chars stored in array to print from MSB
        printf("%c", answer[i]);

    }
    return 0;
}

