#include <iostream>

using namespace std;

class NUM2;

class NUM1
{
    private :
        int value1;
    public :
        void getData(int set) {
            value1 = set;
        }
        void display(void) {
            cout << value1 << endl;
        }
        friend void swap(NUM1 &, NUM2 &);
};

class NUM2 {
    private :
        int value2;
    public :
        void getData(int set) {
            value2 = set;
        }
        void display (void) {
            cout << value2 << endl; 
        }

        friend void swap(NUM1 &, NUM2 &);
};

void swap (NUM1 &x, NUM2 &y) {
    int swap = x.value1;
    x.value1 = y.value2;
    y.value2 = swap;
}


int main ()
{
    NUM1 n1;
    NUM2 n2;

    n1.getData(10);
    n2.getData(20);

    cout << "Values before Swap" << endl;

    n1.display();
    n2.display();

    swap(n1, n2);

    cout << "Values after Swap" << endl;

    n1.display();
    n2.display();

    return 0;
}
