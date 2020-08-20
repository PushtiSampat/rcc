/* 
Name: Ajinkya Rathod
Roll : 30
*/

#include<stdio.h>
int main(int argc, char** argv)
{
    int i, minimun;

    if(argc < 3) {
        printf("Enter more than 1 numbers\n");
        exit(0);
    }

    minimun = atoi(argv[1])

    for (i = 1; i < argc; i++) {

        if(atoi(argv[i]) < minimun) {
            minimun = atoi(argv[i]);
        }

    }

    printf("Output: %d", minimun);

    return 0;
}


/* Output:

objectfile 3 5 4 8 6 2 9
Output: 2

*/
