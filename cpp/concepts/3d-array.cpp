#include <iostream>

using namespace std;

int main ()
{
    int a[3][2][3] = 
    {
        {
            {1, 2, 3},
            {4, 5, 6},
        },
        {
            {10, 11, 12},
            {13, 14, 15},
        },
        {
            {19, 20, 21},
            {22, 23, 24},
        }
    };


    cout << a[1][1][1] << endl;

    int ***p1;
    int **(p2[3]);
    int *(p3[6]);

    p3[0] = a[0][0];
    p3[1] = a[0][0];
    p3[2] = a[0][1];
    p3[3] = a[1][1];
    p3[4] = a[1][2];
    p3[5] = a[1][2];

    cout << *(p3[0]) << endl;

    p2[0] = &(p3[0]);
    p2[1] = &(p3[2]);
    p2[2] = &(p3[4]);
    
    cout << *(*(p2[0])) << endl;

    p1 = p2;
    int i = 1, j = 1, k = 1;
    
    cout << *(*(*(p1 + i) + j) + k) << endl;
    cout << p1[i][j][k]  << endl;

    return 0;
}
