/* ===========================================================
 
 * Roll No: 30
 * 
 * File:      poly_Add_With_array.cpp
 * Copyright: 21-Aug-2020 by Ajinkya Rathod(ajinzrathod)
 * 
 * Content:  Write a program to add two Polynomials using Array
 * 
 * ========================================================== */
 
#include <iostream>
#include <math.h>

using namespace std;

class Poly
{
    int deg;
    float *coEff;

    void printTerm(float coeff, int power)
    {
        if (fabs(coeff) == 1)
            cout << "x";
        else
            cout << coeff << "x";

        if (power != 1)
            cout << "**" << power;
    }

public:
    Poly()
    {
        deg = 0;
        this->coEff = NULL;
    }

    Poly(int deg)
    {
        this->deg = deg;
        this->coEff = new float[deg + 1];
    }

    void readPoly()
    {
        for (int i = deg; i >= 0; i--){
            cout << "Co-eff of deg " << i << ": ";
            cin >> this->coEff[i];
        }
    }

    void printPoly()
    {
        printTerm(this->coEff[deg], deg);

        for (int i = deg - 1; i > 0; i--){
            if (!this->coEff[i])
                continue;
            else
            {
                if (this->coEff[i] < 0)
                    cout << " - ";
                else
                    cout << " + ";
                printTerm(fabs(this->coEff[i]), i);
            }
        }
        if (this->coEff[0] < 0)
            cout << " - ";
        else
            cout << " + ";
        cout << fabs(this->coEff[0]);
    }

    void setCoeff(float coeff, int power)
    {
        this->coEff[power] = coeff;
    }

    float getCoeff(int power)
    {
        if (power > deg || power < 0)
            return 0;
        else
            return this->coEff[power];
    }

    int getDeg()
    {
        return deg;
    }

    void setDeg(int deg)
    {
        this->deg = deg;
        this->coEff = new float[deg + 1];
    }

    // Adding Both Polynomials
    Poly operator+(Poly p2)
    {
        int resultDeg = this->deg > p2.getDeg() ? this->deg : p2.getDeg();

        Poly res(resultDeg);

        for (int i = 0; i <= resultDeg; i++){
            float coeff = this->getCoeff(i) + p2.getCoeff(i);
            res.setCoeff(coeff, i);
        }
        return res;
    }
};

// Driver Code
int main()
{
    int deg;

    // Reading First Polynomial
    cout << "Enter Max deg of first Poly: ";
    cin >> deg;

    Poly p1(deg);

    p1.readPoly();

    // Reading Second Polynomial
    cout << endl << "Enter max deg of second Poly: ";
    cin >> deg;

    Poly p2(deg);

    p2.readPoly();

    // Adding Both Polynomials
    Poly addedPoly = p1 + p2;
    addedPoly.printPoly();

    printf("\n");
    return 0;
}


/* ===========================================================
Output:
    Enter Max deg of first Poly: 3
    Co-eff of deg 3: 2
    Co-eff of deg 2: 4
    Co-eff of deg 1: 5
    Co-eff of deg 0: 6

    Enter max deg of second Poly: 2
    Co-eff of deg 2: 7
    Co-eff of deg 1: 2
    Co-eff of deg 0: 3
    2x**3 + 11x**2 + 7x + 9

 * ========================================================== */
