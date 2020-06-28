#include<stdio.h>
#include<stdlib.h>

int copyFile(char sourceFile[], char destinationFile[])
{
    int no_of_lines = 0, success = 1;
    char line[1000];

    FILE *f1 = fopen(sourceFile, "r");
    FILE *f2 = fopen(destinationFile, "a+");

    printf("Working on \"%s\" file:\n", sourceFile);

    if(f1 && f2) {
        while(fgets(line, sizeof line, f1)) {
            no_of_lines++;
            // fputs (line, stdout);
            fputs (line, f2);
        }

        printf("%d lines yanked and pasted", no_of_lines);

        fclose(f1);
        fclose(f2);

    }

    else {
        success = 0;
        printf("No such File exists");
        // ferror(f1);
        // ferror(f2);
    }
    puts ("\n");
    return success;
}

int copyFiles(int argc, char **argv)
{
    int i, allSuccess = 1, success;
    
    if (argc < 3) {
        printf("Enter atleast 2 File Names\n");
        exit(1);
    }

    FILE *destinationFile = fopen(argv[argc - 1], "w");
    fclose(destinationFile);
    // // open in write mode to remove previous data


    for (i = 1; i < argc - 1; i++) {
        success = copyFile(argv[i], argv[argc - 1]);
        if(success && allSuccess) {
            allSuccess = 1;
        }
        else {
            allSuccess = 0;
        }
    }

    return allSuccess;

}

// objectFile srcFile3 srcFile2 srcFile1 ... destinationFile
int main(int argc, char **argv)
{
    int success;
    
    success = copyFiles(argc, argv);

    if(success) {
        printf("All File are copied Successfully\n");
    }
    else {
        printf("All files are NOT copied\n");
    }

    return 0;
}


/* =================================================
ajinzrathod@ajinz:~/Documents/Assgn/cla$ ./a a.txt b.txt c.txt destination.txt 

    Working on "a.txt" file:
    2 lines yanked and pasted

    Working on "b.txt" file:
    5 lines yanked and pasted

    Working on "c.txt" file:
    2 lines yanked and pasted

    All File are copied Successfully


    ==========IF WE WRITE WRONG FILE NAME=========

ajinzrathod@ajinz:~/Documents/Assgn/cla$ ./a b.txt e2.txt c.txt d.txt 

    Working on "b.txt" file:
    5 lines yanked and pasted

    Working on "e2.txt" file:
    No such File exists

    Working on "c.txt" file:
    3 lines yanked and pasted

    All files are NOT copied

 ================================================= */
