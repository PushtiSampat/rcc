

// =================================================================
// Q16
// Command Line Check Exectutable Files



#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int isExecutable(char fileName[])
{
    struct stat sb;
    if (stat(fileName, &sb) == 0 && sb.st_mode & S_IXUSR) {
        return 1;
    }
    else {
        return 0;
    }
}


int main(int argc, char **argv)
{
    char folderName[50];
    DIR *d;
    struct dirent *dir;
    int count = 0;

    if (argc == 2) {
        strcpy(folderName, argv[1]);
        d = opendir(folderName);       
    }
    else if (argc == 1){
        printf("Checking current directory\n");
        d = opendir(".");   
    }
    else {
        printf("Enter only 1 directory");
    }
    if (d) {
        while ((dir = readdir(d)) != NULL)
        {
            if(isExecutable(dir -> d_name)) {
                count++;
                printf("%s" ,dir->d_name);
                printf(" is executable\n");
            }
        }
        if(!count) {
            printf("No executables Found");
        }
    }   
    else{
        printf("Directory Path Invalid\n");
    }
    return 0;
}




/* =================================================


ajinzrathod@ajinz:~/Documents/Assgn/cla$ ./objFile

Checking current directory
a is executable
.. is executable
. is executable

 ================================================= */


