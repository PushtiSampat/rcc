#include <iostream>

using namespace std;

class Weight
{
    private :
        float total_weight;
    public:

        // Default constructor with no arguments
        Weight() {this -> total_weight = 0; };

        Weight(int kilos, int grams)
        {
            // Converting to float and storing in "total_weight"
            this -> total_weight = stof (to_string(kilos) + "." + to_string(grams));
        }

        void display() { cout << this-> total_weight << endl; }

        friend bool operator < (Weight, Weight);
};


bool operator < (Weight w1, Weight w2)
{
    if (w1.total_weight < w2.total_weight) {
        return true;
    }

    else if (w1.total_weight > w2.total_weight) {
        return  false;
    }

    return false; //if both weight are same
}


int main ()
{
    Weight mobile, stone;

    mobile =  Weight(120, 0); //arg1 = kilos, arg2 = grams
    stone = Weight (120, 0); //arg1 = kilos, arg2 = grams

    if (mobile < stone) {
        cout << "Mobile's Weight is less than stone" << endl;
    }

    else {
        cout << "Mobile's Weight is not less than stone" << endl;
    }

    return 0;
}
