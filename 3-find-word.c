 /* ===========================================================
 
 * Roll No: 30
 * 
 * File:      3-find-word.c
 * Copyright: 18-May-2020 by Ajinkya Rathod(ajinzrathod)
 * 
 * Content: Write a program to search a particular word 
 *			in an existing file and display the 
 *			no. of occurrences and the position 
 *			of first occurrence of that word. 
 *			If the word is not found 
 *			display the appropriate message  
 * 
 * ========================================================== */

  /* * * * * * * * * * * * * N O T E * * * * * * * * * * * * * * * *
 *
 * 1. Make sure file name "readlinebyline.txt" exists                 
 *
 /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()

{
    int i = 0, length = 0, count = 0, finding = 0, first_occurance = 0;
    char search_this_word[50], search;
    char c;
    FILE *f = fopen ("readlinebyline.txt", "r"); 

    printf("Enter the word you want to search: ");
    scanf("%s", search_this_word);

    length = strlen (search_this_word);

    if (f) {
        if(!length) {
            exit(0);
        }

        search = search_this_word[0];

        while((c = fgetc(f)) != EOF){
            if (count == 0) {
                first_occurance++;
            }

            if (search == c) {
                finding = 1;

                if(length == i + 1) {

                    i = finding = 0;
                    count++;
                    search = search_this_word[i];
                }

                else {
                    search = search_this_word[++i];
                }

            }
            else {
                finding = 0;
            }
        }

        if (count > 0) {
            printf ("\"%s\" found 1st time at %d position \n", search_this_word, first_occurance - length + 1);
            printf ("\"%s\" found %d times\n", search_this_word, count);
        }
        else {
            printf ("\"%s\" not found\n", search_this_word);
        }
    }
    else {
        puts ("Cannot open file to read");
    } 
    printf ("\n");
    return 0;
}

/* =================================================================
 * Data in file :

    Lorem Ipsum dolor set amet.
    Lorem Ipsum.
    dolor set amet.
    Ipsumset amet.

 * Output :


    Enter the word you want to search: set
    "set" found 1st time at 19 position 
    "set" found 3 times

 ================================================================= */
