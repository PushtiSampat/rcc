#include <iostream>

using namespace std;

class Drinks
{
    private :
        int ml;

    public :
        Drinks() { this -> ml = 0; } 

        Drinks(int ml){ this -> ml = ml; }

        void operator = (const Drinks &D);

        void display () { cout << this -> ml << endl; }
};

void Drinks :: operator = (const Drinks &D)
{
    this -> ml = D.ml;
}

int main()
{
    Drinks sprite;
    Drinks fanta;

    sprite = Drinks (200);

    fanta = sprite; 
    
    sprite.display();
    fanta.display();

    return 0;
}
