#include <iostream>

using namespace std;

class Time
{
    private :
        int hrs;
        int mins;

    public :
        friend istream & operator >> (istream &, Time &);
        friend ostream & operator << (ostream &, const Time &);

};

istream & operator >> (istream & input, Time & T)
{
    cout << "Enter Hours and minutes: ";
    input >> T.hrs >> T.mins;

    return input;
}


ostream & operator << (ostream &output, const Time & T) 
{
    output << endl;
    output << T.hrs << ":" << T.mins;

    return output;
}
int main ()

{
    Time t1, t2;

    cin >> t1;
    cin >> t2;

    cout << t1;
    cout << t2;
   
    puts ("\n");
    return 0;
}
