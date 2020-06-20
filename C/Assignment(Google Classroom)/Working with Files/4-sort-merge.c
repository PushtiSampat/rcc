 /* ===========================================================
 
 * Roll No: 30
 * 
 * File:      4-sort-merge.c
 * Copyright: 18-May-2020 by Ajinkya Rathod(ajinzrathod)
 * 
 * Content: The files DATA1 and DATA2 
 *			contain sorted list of integers. 
 			Write a program to produce a third file DATA
 			which holds a single sorted merged list
 			 of these two lists.  
 * 
 * ========================================================== */


 /* * * * * * * * * * * * * N O T E * * * * * * * * * * * * * * * *
 *
 * 1. If       "file1.txt" exists, data will be overwritten 
 * 2. If       "file2.txt" exists, data will be overwritten 
 * 3. If "sorted-data.txt" exists, data will be overwritten 
 *
 /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


#include <stdio.h>
#include <stdlib.h>

#define DIGIT 3

int * readandsort()
{
    int i = 0, j, index;
    static int myarray[10];
    int swap;
    char line[1000];

    FILE *f1 = fopen ("file1.txt", "r"); 
    FILE *f2 = fopen ("file2.txt", "r"); 

    if (f1 && f2) {

        while (fgets(line, sizeof line, f1)) {
            myarray[i++] = atoi(line);
        }

        while (fgets(line, sizeof line, f2)) {
            myarray[i++] = atoi(line);
        }
        
        for (i = 0; i < DIGIT * 2 - 1; i++) {

            index = i;

            for (j = i + 1; j < DIGIT * 2; j++) {

                if (myarray[j] < myarray[index]) {
                    index = j;
                }

            }

            swap = myarray[i];
            myarray[i] = myarray[index];
            myarray[index] = swap;
        }

    }

    else {
        printf("Unable to open files");
        exit (1);
    }

    return myarray;
}


void writeSortedData(int *p)
{
    int i;
    FILE *f = fopen ("sorted-data.txt", "w");
    
    for (i = 0; i < DIGIT * 2; i++) {
        fprintf(f, "%d ", *(p + i));
    }

    printf ("Write success to \"sorted-data.txt\"");
}


int main()
{
    int num = DIGIT, data, *p;
    FILE *f1 = fopen ("file1.txt", "w"); 
    FILE *f2 = fopen ("file2.txt", "w"); 


    if(f1 && f2) {
        printf("Enter %d numbers in FILE1\n", DIGIT);
        while(num--) {
            scanf   ("%d",&data);
            fprintf (f1, "%d\n", data);
        }

        num = DIGIT;

        printf("Enter %d numbers in FILE2\n", DIGIT);
        while(num--) {
            scanf   ("%d",&data);
            fprintf (f2, "%d\n", data);
        }

        fclose (f1);
        fclose (f2);        

        p = readandsort();
        writeSortedData(p);
    } 

    else {
        puts ("Unable to open files");
        exit(1);
    }

    printf("\n");

    return 0;
}


/* =================================================================

 * Output :
     Enter 3 numbers in FILE1
    12 22 11
    Enter 3 numbers in FILE2
    1 212 121
    Write success to "sorted-data.txt"

 ================================================================= */
