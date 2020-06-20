#include<iostream>

class A;
class B;

// Writing class B before class A will cause an Error
// Beacuse Class B does NOT know that function showB exists
// so it will cause an Error

class A 
{
    private :
        int a;

    public :
        A ()
        {
            this->a = 0;
        }

        void showB(B&);
};

class B
{
    private :
        int b;
    public :
        B()
        {
            this->b = 10;
        }

        friend void A :: showB(B &);

};

void A :: showB (B &b)
{
    std :: cout << b.b;
}


int main()

{
    A a;
    B b;
    a.showB (b);    
    return 0;
}
