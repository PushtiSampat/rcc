 /* ===========================================================
 
 * Roll No: 30
 * 
 * File:      1-remove-occurances.c
 * Copyright: 18-May-2020 by Ajinkya Rathod(ajinzrathod)
 * 
 * Content: Write a function to accept a string 
 *          from the keyboard and 
 *          remove all occurrences of that string 
 *          from a given file  
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
        printf ("Error: ");
        ferror(f1);
        ferror(f2);
    }
}
int main()

{
    int i = 0, j, length = 0, count = 0, finding = 0;
    char search_this_word[50], search;
    char c;
    FILE *f = fopen ("readlinebyline.txt", "r+"); 
    FILE *f1 = fopen ("tempFile.txt", "w");

    printf("Enter the word you want to search: ");
    scanf("%s", search_this_word);

    length = strlen (search_this_word);

    if (f) {
        if(!length) {
            exit(0);
        }

        search = search_this_word[0];

        while((c = fgetc(f)) != EOF){
                fprintf (f1, "%c", c);
            if (search == c) {
                finding = 1;
                if(length == i + 1) {
                    i = finding = 0;
                    count++;

                    fseek (f1, -length, SEEK_CUR);
                    for (j = 0; j < length; j++) {
                        //fprintf (f1, "*");
                    }

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
        printf ("\"%s\" found %d times", search_this_word, count);
        if (count) {
            printf (" and deleted every time from the file");
        }
        fclose(f);
        fclose(f1);
        copyFile();

    }
    else {
        puts ("Cannot open file to read");
    } 
    printf ("\n");
    return 0;
}



/* =================================================================
 * In "txt" file
    Lorem Ipsum dolor set amet.
    Lorem Ipsum.
    dolor set amet.
    Ipsumset amet.

 * Output :
    Enter the word you want to search: set
    "set" found 3 times and deleted every time from the file
 ================================================================= */
