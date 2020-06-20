#include <iostream>

using namespace std;

class Fan
{
    private:
        int speed;
    public:
        Fan() { this-> speed = 0; }

        Fan(int speed) { this -> speed = speed; }

        Fan operator() (int decreaseSpeed)
        {
            Fan f;
            f.speed = this -> speed - decreaseSpeed;
            return f;
        }

        void display() { cout << this -> speed << endl; }
};

int main ()
{
    int decreaseSpeed = 0;

    Fan havells, usha;
    havells = Fan(100);

    cout << "We know usha's fan is slower than havells" << endl;
    cout << "How much slow it is: " << endl;

    cin >> decreaseSpeed;

    usha = havells(decreaseSpeed); //invoke operator

    cout << "Havells: ";
    havells.display();

    cout << "Usha: ";
    usha.display();

    return 0;
}
