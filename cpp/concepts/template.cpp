#include <iostream>
#include <string>

using namespace std;

//template <typename T>
//OR
template <class T>

T maximum(T x, T y)
{
    return x > y ? x : y;
}

int main ()
{
    cout << maximum ('1', '2') << endl; // implicit
    cout << maximum <int> ('1', '2') << endl; // explicit

    cout << maximum (21.34, 21.21) << endl;

    return 0;
}
