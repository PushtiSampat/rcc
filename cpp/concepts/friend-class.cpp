#include<iostream>

class B;

class A 
{
    private :
        int a;

    public :
        A()
        {
            puts ("A set");
            this->a = 20;
        }

        friend class B;
        void showB(B& b);
};

class B
{
    private :
        int b;

    public :
        B()
        {
            puts ("B set");
            this->b = 10;
        }

        friend class A;

        void showA (A a)
        {
            std :: cout << a.a << std::endl;
        }

        void showMyself()
        {
            std :: cout << this->b;
        }
};

void A :: showB (B& b)
{
    std :: cout << b.b << std::endl;
    b.b = 50;
    std :: cout << b.b << std::endl;
}

int main ()
{
    A a;
    B b;

    b.showA(a);
    a.showB(b);

    b.showMyself();

    std :: cout << std :: endl;

    return 0;
}
