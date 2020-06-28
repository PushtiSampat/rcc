


// =================================================================
// Q16
// Command Line Rename File

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int main(int argc, char **argv)
{
    if(argc != 3) {
        printf("Invalid Arguments\n");
        printf("Example\n objFile oldFile.txt newFile.txt\n");
        exit(1);
    }

    if(rename(argv[1], argv[2]) == 0)
    {
        printf("File renamed successfully.\n");
        exit(0);
    }
    printf("Cannot rename File\n");

    return 0;
}

/* ==========================================================
 *
 * Output:
 *
 * ajinzrathod@ajinz:~/Documents/Assgn/cla$ ./objFile collegeNemes.c collegeNames.c
 * File renamed successfully.
 *
 * ======================================================== */


