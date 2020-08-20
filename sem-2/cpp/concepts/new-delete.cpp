#include <iostream>
#include <new> // nothrow
#include <stdlib.h>

class Animals
{
    private :
        int stamina;
        int tigerNo;

    public :
        Animals ()
        {
            this->stamina = 100;
            std :: cout << "A new Tiger took birth" << std :: endl;
        }
        void walk()
        {
            this->stamina -= 10;
            std ::cout << "My stamina decreased by 10 points" << std :: endl;
            std :: cout << this->stamina << std :: endl;
        }
        void eat()
        {
            this->stamina += 10;
            std :: cout << "Tiger no " << this->tigerNo  << "'s stamina increased by 10 points" << std :: endl;
            std :: cout << "New Stamina " << this->stamina << std :: endl;
        }

        void assignTigerNo (void);
        void showStamina (void);

        void * operator new[] (size_t);
        void operator delete[] (void *);

        void friend provideFood (int, Animals tigers[], int tiger_no);
};


void Animals :: assignTigerNo (void)
{
    std :: cout << "Enter Tiger no: ";
    std :: cin >> this->tigerNo;
    
}


void Animals :: showStamina (void) 
{
    std:: cout << this -> stamina << std :: endl;
}


void provideFood (int n, Animals tigers[], int tiger_no)
{
   for (int i = 0; i < n; i++) {
        if (tigers[i].tigerNo == tiger_no) {
            tigers[i].eat(); 
        }
   }
}


void * Animals :: operator new[] (size_t size)
{
    //std :: cout << size << std :: endl;
    void *p =  :: new(std :: nothrow) Animals();
    //void *p = malloc (size);
    return p;
}


void Animals :: operator delete[] (void *p)
{
    free (p);
    std :: cout << "Array of objects which were created dynamically is deleted" << std :: endl;
}



int main ()

{
    int n, tiger_no;

    printf ("How much tigers do you want ");
    scanf ("%d",&n);

    Animals *tigers = new Animals[n - 1];
    //Animals *tigers =  new(std :: nothrow) Animals[n];

    if(!tigers) {
        perror ("Error");
        exit (0);
    }
    
    for (int i = 0; i < n; i++) {
        tigers[i].assignTigerNo(); 
    }
    
    std :: cout << "Which tiger should be given Food: ";
    std :: cin >> tiger_no;

    provideFood (n, tigers, tiger_no);
 
    for (int i = 0; i < n; i++) {
        tigers[i].showStamina();
    }


    // delete [] tigers;
    
    for (int i = 0; i < n; i++) {
        tigers[i].showStamina();
    }

    

    return 0;
}
