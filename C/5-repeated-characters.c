 /* ===========================================================
 
 * Roll No: 30
 * 
 * File:      5-repeated-characters.c
 * Copyright: 18-May-2020 by Ajinkya Rathod(ajinzrathod)
 * 
 * Content: Write a program to read line by line from a file
 *			and print all the repeated characters
 *			on the screen along with their frequency  
 * 
 * ========================================================== */

#include <stdio.h>
#include <string.h>

void findOccurences(char *mystring, char data[][1])
{
    FILE *f1 = fopen("readlinebyline.txt", "r");
    char line[1000], *cptr;
    int i, break_me, count = 0, numbers[50] = {0};

    while(fgets(line, sizeof line,f1)) {
        cptr = line;
        fputs (line, stdout);
        while (*cptr != '\0') {
            break_me = 0;

            if(*cptr == '\n') {
                *cptr = '^';
            } else if(*cptr == ' ') {
                *cptr = '_';
            }  
            for (i = 0; i < count; i++) {
                if(data[i][0] == (*cptr)) {
                    numbers[i]++;
                    break_me = 1;
                    break;
                }
            }

            if (!break_me) {
                data[count][0] = (*cptr);
                count++;
                numbers[i]++;
            }

            cptr++;

        }
    }
    printf ("\n\n ^ is for new line\n _ stand for spaces");
    printf ("\n\n");
    for (i = 0; i < count; i++) {
        printf ("%2c : %2d\t\t", data[i][0], numbers[i]);
        if((i + 1) % 4 == 0) {

            printf ("\n");
            printf ("=============================================================\n");
        }
    }
}

int main()
{
    char mystring[50], data[50][1];

    findOccurences(mystring, data);

    printf("\n");
    return 0;
}


/* =================================================================
 * In "readlinebyline.txt"
    Lorem Ipsum dolor set amet.
    Lorem Ipsum.
    dolor set amet.
    Ipsumset amet.

 * Output :

    Lorem Ipsum dolor set amet.
    Lorem Ipsum.
    dolor set amet.
    Ipsumset amet.

     ^ is for new line
     _ stand for spaces

     L :  2      o :  6      r :  4      e :  8     
    =============================================================
     m :  8      _ :  8      I :  3      p :  3     
    =============================================================
     s :  6      u :  3      d :  2      l :  2     
    =============================================================
     t :  6      a :  3      . :  4      ^ :  3     
    =============================================================


 ================================================================= */
