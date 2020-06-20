 /* ===========================================================
 
 * Roll No: 30
 * 
 * File:      6-count-characters-whitespaces.c
 * Copyright: 18-May-2020 by Ajinkya Rathod(ajinzrathod)
 * 
 * Content: Write a function to read a file and 
 *           count the no. of 
 *           characters, 
 *           spaces, 
 *           tabs, 
 *           newlines and 
 *           no. of words in a given text file.  
 * 
 * ========================================================== */

#include <stdio.h>
#include <string.h>

void findOccurences(char *mystring, char data[][1])
{
    FILE *f1 = fopen("readlinebyline.txt", "r");
    char line[1000], *cptr;
    int new_lines = -1, tabs = 0, spaces = 0, words = 0, characters = 0, others = 0;

    while(fgets(line, sizeof line,f1)) {
        cptr = line;

        while (*cptr != '\0') {

            if(*cptr == '\n') {
                new_lines++;
                cptr++;
                if(*cptr != EOF) {
                    words++;
                }
                cptr--;
            }  
            else if(*cptr == '\t') {
                tabs++;                
            }  
            else if(*cptr == ' ') {
                spaces++;                
                words++;
            }  
            else if((*cptr > 64 && *cptr < 91) || (*cptr > 96 && *cptr < 124)) {
                characters++; 
            }  
            else {
                others++;              
            }  
            cptr++;

        }
    }
    printf ("new_lines = %d\ntabs = %d\nspaces = %d\n"
           "words = %d\ncharacters = %d\nothers = %d\n",
           new_lines, tabs, spaces, words, characters, others);
}

int main()
{
    char mystring[50], data[50][1];

    findOccurences(mystring, data);

    printf("\n");
    return 0;
}

/* =================================================================
 * Data in txt file

    Lorem Ipsum dolor set amet.
Lorem Ipsum.
dolor set amet.
Ipsumset    amet.

 * Output :

new_lines = 2
tabs = 2
spaces = 8
words = 11
characters = 56
others = 4

 ================================================================= */
