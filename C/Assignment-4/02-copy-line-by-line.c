 /* ===========================================================
 
 * Roll No: 30
 * 
 * File:      2-copy-line-by-line.c
 * Copyright: 18-May-2020 by Ajinkya Rathod(ajinzrathod)
 * 
 * Content: Write a program to copy the contents 
 *			of one file to another and also 
 *			print the no. of lines in the first file.
 * 
 * ========================================================== */
 

 /* * * * * * * * * * * * * N O T E * * * * * * * * * * * * * * * *
 *
 * 1. Make sure file name "readlinebyline.txt" exists			      
 * 2. If "copy-readlinebyline.txt" exists, data will be overwritten 
 *
 /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
 
 
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int no_of_lines = 0;
    char line[1000];
    FILE *f1 = fopen("readlinebyline.txt", "r");
    FILE *f2 = fopen("copy-readlinebyline.txt", "w");
    if(f1 && f2) {
		if (fgetc(f1) == EOF) {
			printf ("No data found\n");
		    exit(0);
        } 

        while(fgets(line, sizeof line, f1)) {
            no_of_lines++;
            // fputs (line, stdout);
            fputs (line, f2);
        }
         
        printf("\n%d lines yanked and pasted", no_of_lines);

        fclose(f1);
        fclose(f2);

    }

    else {
        ferror(f1);
        ferror(f2);
    }
    puts ("\n");
}

/* =================================================================
 * Output :
 
    5 lines yanked and pasted

 ================================================================= */
