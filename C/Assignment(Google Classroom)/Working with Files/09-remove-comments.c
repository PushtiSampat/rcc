 /* ===========================================================
 
 * Roll No: 30
 * 
 * File:      9-remove-comments	.c
 * Copyright: 18-May-2020 by Ajinkya Rathod(ajinzrathod)
 * 
 * Content: Write a program a program to remove all the comments
 *          from a C file. 
 * 
 * ========================================================== */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void copyFile()
{
    int delFile;
    char line[1000];
    FILE *f1 = fopen("tempFile.txt", "r");
    FILE *f2 = fopen("readlinebyline.txt", "w");
    if(f1 && f2) {

        while(fgets(line, sizeof line, f1)) {
            fputs (line, f2);
        }

        fclose(f1);
        fclose(f2);

        delFile = remove("tempFile.txt");

        if(delFile) {
            printf ("File not deleted");  
        }
    }

    else {
        ferror(f1);
        ferror(f2);
    }
}

int main()
{
    char prev = 'A', c;
    int stop = 0, first_occurence = 0, second_occurance = 0, long_comments = 0;
    FILE *f = fopen ("readlinebyline.txt", "r+"); 
    FILE *f1 = fopen ("tempFile.txt", "w");

    if (f) {
        while((c = fgetc(f)) != EOF){
            if(long_comments == 1) {
                if (c == '/' && prev == '*') {
                    long_comments = 0;
                }
            }
            if (first_occurence == 1) {
                if (c == '*') {
                    long_comments = 1;
                }
                else if(c != '/') {
                    stop = 0;
                }else {
                    second_occurance = 1;
                }
                first_occurence = 0;
            }
            if(stop == 1) {
                if (c == '\n') {
                    stop = 0;
                    second_occurance = 0;
                }
            }

            else if(c == '/') {
                first_occurence = 1;
                stop = 1;
            }    

            if(stop == 0 && second_occurance == 0 && long_comments == 0) {
                if (prev == '/' && c != '\n'){
                    fprintf (f1, "/");
                }
                fprintf (f1, "%c", c);
            }
            prev = c;
        }
        fclose(f);
        fclose(f1);
        copyFile();

        printf("Comments Removed");

    }
    else {
        puts ("Cannot open file to read");
    } 
    printf ("\n");
    return 0;
}


/* =================================================================
C File:
#include<stdio.h>

/* This program adds divides by 2 */

/* // ** /* /* /* /* /* / * /* */
/////
///


int main ()
{
    int a = 10;

    // dividing a by 2
    a /= 2;

    return 0;
}

Output :

Comments Removed



/*
"New C File"

#include<stdio.h>





int main ()
{
    int a = 10;
    
    a /= 2;
    return 0;
}
*/
 // ================================================================= */
