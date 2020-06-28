#include<stdio.h>
#include<stdlib.h>


float avg(int argc, char **argv)
{
    int i;
    float average, total = 0;
    if (argc < 2) {
        printf("Enter atleast 1 number");
        return 0;
    }
    

    for (i = 1; i < argc; i++) {
        total = total + atoi(argv[i]);
    }

    average = total / (argc - 1);

    return average;
}


int main(int argc, char **argv)
{
    float avrg;

    avrg = avg(argc, argv);
    printf("Average: %.2f \n", avrg);

    return 0;
}



/* =================================================
 *
 ajinzrathod@ajinz:~/Documents/Assgn$ ./objectFile 78 96 84 45
    Average: 75.75

 ================================================= */
