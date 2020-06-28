 /* ===========================================================
 
 * Roll No: 30
 * 
 * File:      8-remove-blank-lines.c
 * Copyright: 18-May-2020 by Ajinkya Rathod(ajinzrathod)
 * 
 * Content: Write a program to remove all the blank lines 
 *          from a given file.  
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
    char prev = '\n', c;
    int count_lines = 0;
    FILE *f = fopen ("readlinebyline.txt", "r+"); 
    FILE *f1 = fopen ("tempFile.txt", "w");

    if (f) {
        while((c = fgetc(f)) != EOF){
            if(c == '\n' && prev == '\n') {
                count_lines = 1;
            }    
            else {
                fprintf (f1, "%c", c);
            }
            prev = c;
        }
        fclose(f);
        fclose(f1);
        copyFile();
        
        printf ("Unwanted lines deleted");

    }
    else {
        puts ("Cannot open file to read");
    } 
    printf ("\n");
    return 0;
}


/* =================================================================
 in txt file (numbers repersent <line number>)
 * 1. 
 * 2. 
 * 3. Lorem Ipsum dolor  amet.
 * 4. 
 * 5.
 * 6. Lorem Ipsum.
 * 7. 
 * 8. dolor  amet.
 * 9. 

 * Output :

 * Unwanted lines deleted

 ================================================================= */
