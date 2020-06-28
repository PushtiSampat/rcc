#include<stdio.h>
#include<stdlib.h>


int* factorial(int argc, char **argv, int *arr)
{
    if (argc < 2) {
        printf("Enter atleast 1 number\n");
        exit(0);
    }

    int fact(int num)
    {
        if(num == 0)
            return 1;
        return num * fact(num - 1);
    }

    int i;

    for (i = 1; i < argc; i++) {
        arr[i - 1] = fact(atoi(argv[i]));
    }

    return arr;
}


int main(int argc, char **argv)
{
    int arr[10], i;
    int *ptr = factorial(argc, argv, arr);

    puts("Factorials are as follows:\n");
    for (i = 1; i < argc; i++)
        printf("%02d: %5d\n", atoi(argv[i]), ptr[i - 1]);

    return 0;
}


/* =================================================
 ajinzrathod@ajinz:~/Documents/Assgn$ ./objectFile 3 5 8 2 4

    Factorials are as follows:

    03:     6
    05:   120
    08: 40320
    02:     2
    04:    24
 ================================================= */
