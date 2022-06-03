#include <stdio.h>
#include <stdlib.h>
#include <string.h>// to use strlen()
#include <conio.h>// to use getch()
#include <ctype.h>// to use isdigit(), isspace()

void read(char *typed, int *boundary) {
    char c; // stores each user typed character
    int i=0; // variable to control the character array index and the last loop
    // type only *boundary characters
    do {
       c=getch(); // capture the user typed character
       if (isdigit(c)!=0 || isalpha(c)!=0 || isspace(c)!=0 || (c=='-') || (c=='.')){
          if (i < *boundary){ // if the array index is less than *boundary
              typed[i] = c; // stores in the character array
              i++; // increases the character array index
              printf ("%c", c);
          }
       }
       else if(c==8&&i) { // if the backspace key is pressed and there are typed characters
                typed[i]='\0'; // the current index of the character array is terminated from the string
                i--; // the character array index is decreed
                printf("\b \b"); // The typed character is erased from the screen
       }
    } while(c!=13); // the loop will be performed until the press is the ENTER (code 13 in the ASCII table)
    typed[i]='\0'; // the current index of the character array is terminated from the string
    *boundary = strlen(typed);        
}

int main(){
	int maxsize = 50; // max size of string
	char typed[maxsize]; // stores what was typed by the user
	while(1) {
		int boundary = 8;
		printf ("Type only %d characters: ", boundary);
		read(typed, &boundary);
		//int x = atoi(typed);
		double x = atof(typed);
		if (x != 0) {
			printf ("\n\nNumber typed: %f", x);
		}
		else {
			printf ("\n\nWord/phrase typed: ");
		   	//for (i=0;i<strlen(typed);i++){
	    	for (int i=0;i<boundary;i++)
    	        printf ("%c", typed[i]); // displays the character in the current index of the array
		}	
			
    	printf ("\n\n q to quit - ");
    	//system ("pause");
    	char aux = getch(); if (aux == 'q') break;
	}
    return 0;
}

// Freely inspired by Matheus Patrick's original code (https://www.clubedohardware.com.br/forums/topic/1138816-limitar-numero-de-caracteres-cc/)
