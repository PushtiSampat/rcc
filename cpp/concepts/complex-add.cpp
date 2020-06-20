#include<iostream>

class Complex
{
    private : // by default
        int a, b;
    
    public :
        Complex () {}
        Complex (int, int);

        void display ();
        friend Complex sum(Complex, Complex);
};

Complex :: Complex (int x, int y)
{
   this -> a = x;
   this -> b = y;
}

void Complex :: display ()
{
    std :: cout << this -> a << std :: endl;
    std :: cout << this -> b << std :: endl;
}

Complex sum (Complex c1, Complex c2)
{
    Complex result;

    result.a = c1.a + c2.a;
    result.b = c1.b + c2.b;
    
    return result;
}

int main ()
{
    Complex A (10, 20); // Constructor called implicitly
    Complex B = Complex (30, 40); // Constructor called explicitly

    Complex ans;

    A.display ();  
    B.display ();

    ans = sum (A, B);
   
    puts ("Answer ");
    ans.display();

    return 0;
}
