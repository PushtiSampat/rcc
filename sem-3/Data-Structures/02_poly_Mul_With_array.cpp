/* ===========================================================
 
 * Roll No: 30
 * 
 * File:      poly_Mul_With_array.cpp
 * Copyright: 21-Aug-2020 by Ajinkya Rathod(ajinzrathod)
 * 
 * Content:  Write a program to Multiply two Polynomials using Array
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

        for (int i = deg - 1; i > 0; i--)
        {
            if (!this->coEff[i])
                continue;
            else {
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

    void zeros()
    {
        for (int i = 0; i <= this->deg; i++)
            this->coEff[i] = 0;
    }

    // Multiplying Polynomials
    Poly operator*(Poly p2)
    {
        int resDeg = this->deg + p2.getDeg();

        Poly result(resDeg);
        result.zeros();  // Setting All Coeff to zeros

        for (int i = 0; i <= deg; i++)
        {
            for (int j = 0; j <= p2.getDeg(); j++) {
                float coeff = result.getCoeff((i + j));
                coeff += (this->getCoeff(i) * p2.getCoeff(j));
                result.setCoeff(coeff, (i + j));
            }
        }
        return result;
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
    cout << endl << "Enter Max deg of second Poly: ";
    cin >> deg;

    Poly p2(deg);
    p2.readPoly();

    // Multiplying Polynomials
    Poly multipliedPoly = p1 * p2;

    multipliedPoly.printPoly();

    printf("\n");
    return 0;
}

/* ===========================================================
Output:

    Enter Max deg of first Poly: 2
    Co-eff of deg 2: 10
    Co-eff of deg 1: 12
    Co-eff of deg 0: 23

    Enter Max deg of second Poly: 3
    Co-eff of deg 3: -10
    Co-eff of deg 2: -5
    Co-eff of deg 1: 4
    Co-eff of deg 0: 8
    -100x**5 - 170x**4 - 250x**3 + 13x**2 + 188x + 184

 * ========================================================== */

