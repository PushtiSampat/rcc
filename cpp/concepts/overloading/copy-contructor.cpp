#include <iostream>

class Bottle
{
    private :
        int litre;

    public :
        Bottle (int x) { litre  = x; }
        int getLitre() { return litre; }
};

class Pot
{
    private :
        int litre;

    public :
        Pot (){ litre = 0; } // Default Constructor

        Pot(Bottle b){ // Copy Constructor
            std :: cout << "The water of bottle is now in pot" << std :: endl;
            litre = b.getLitre();
        }

        void showPot() {
            std :: cout << litre << std :: endl;
        }
};

int main()
{
    Bottle b1(20);
    Pot p1;

    p1.showPot();

    //p1 belongs to pot and b1 belongs to Bottle
    //so destination class is a Constructor
    p1 = b1; // Think like : p1 = Pot(b1);

    p1.showPot();

    return 0;
}
