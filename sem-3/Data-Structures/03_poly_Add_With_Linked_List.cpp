/* ===========================================================

 * Roll No: 30
 *
 * File:      poly_Add_With_Linked_List.cpp
 * Copyright: 21-Aug-2020 by Ajinkya Rathod(ajinzrathod)
 *
 * Content:  Write a program to add two Polynomials using
 *           Linked List
 *
 * ========================================================== */

#include <iostream>
#include <math.h>

using namespace std;

class Term
{
    float coEff;
    int power;
    Term *nextTerm;

public:
    Term()
    {
        this->coEff = 0;
        this->power = 0;
        this->nextTerm = NULL;
    }

    Term(float coeff, int power)
    {
        this->coEff = coeff;
        this->power = power;
        this->nextTerm = NULL;
    }

    void setCoeff(int coeff)
    {
        this->coEff = coeff;
    }

    void setPower(int power)
    {
        this->power = power;
    }

    void setNextTerm(Term *nextTerm)
    {
        this->nextTerm = nextTerm;
    }

    float getCoeff()
    {
        return this->coEff;
    }

    float getPower()
    {
        return this->power;
    }

    Term *getNextTerm()
    {
        return this->nextTerm;
    }

    void print()
    {
        cout << "(";
        if (!power)
            cout << coEff;
        else
        {
            if (coEff == 1)
                cout << "x";
            else if (coEff == -1)
                cout << "-x";
            else
                cout << coEff << "x";

            if (power != 1)
                cout << "**" << power;
        }
        cout << ")";
    }

    ~Term()
    {
        if (nextTerm)
            delete nextTerm;
    }
};

class Poly
{
    int deg;
    Term *head;

public:
    Poly()
    {
        deg = 0;
        head = NULL;
    }

    Poly(int deg)
    {
        this->deg = deg;
        head = NULL;
    }

    Poly(const Poly &p)
    {
        this->deg = p.deg;
        this->head = p.head;
    }

    int getDegree()
    {
        return deg;
    }

    Term *getInitialTerm()
    {
        return this->head;
    }

    void setDegree(int deg)
    {
        this->deg = deg;
    }

    void add(Term *newTerm)
    {
        if (!head) {head = newTerm;}
        else
        {
            Term *iterator = head;
            while (iterator->getNextTerm())
            {
                iterator = iterator->getNextTerm();
            }
            iterator->setNextTerm(newTerm);
        }
    }

    void print()
    {
        Term *currentTerm = head;
        cout << "(";
        if (currentTerm){
            currentTerm->print();
            currentTerm = currentTerm->getNextTerm();
        }

        while (currentTerm){
            cout << " + ";
            currentTerm->print();
            currentTerm = currentTerm->getNextTerm();
        }
        cout << ") = 0";
    }

    void read()
    {
        for (int i = deg; i >= 0; i--){
            float coeff;
            cout << "Enter co-efficient of deg " << i << ": ";
            cin >> coeff;
            add(new Term(coeff, i));
        }
    }

    float getCoeff(int power)
    {
        Term *currentTerm = head;
        while (currentTerm){
            if (currentTerm->getPower() == power)
                return currentTerm->getCoeff();
            currentTerm = currentTerm->getNextTerm();
        }
        return 0;
    }

    void setCoeff(float coeff, int power)
    {
        Term *currentTerm = head;
        while (currentTerm){
            if (currentTerm->getPower() == power)
                currentTerm->setCoeff(coeff);
            currentTerm = currentTerm->getNextTerm();
        }
    }

    void zeroes()
    {
        for (int i = deg; i >= 0; i--){
            add(new Term(0, i));
        }
    }

    // Adding Both Polynomials
    Poly operator+(Poly p2)
    {
        int resDeg = this->deg > p2.getDegree() ? this->deg : p2.getDegree();

        Poly result(resDeg);
        result.zeroes();

        for (int i = resDeg; i >= 0; i--){
            float coeff = (this->getCoeff(i) + p2.getCoeff(i));
            result.setCoeff(coeff, i);
        }
        return result;
    }

    void free()
    {
        if (head) delete head;
    }
};

int main()
{
    int deg;

    // Reading First Polynomial
    cout << "Enter Max deg of first Poly: ";
    cin >> deg;

    Poly p1(deg);
    p1.read();

    // Reading First Polynomial
    cout << "\nEnter Max deg of second Poly: ";
    cin >> deg;

    Poly p2(deg);
    p2.read();

    // Adding Both Polynomials
    Poly addedPoly = p1 + p2;
    addedPoly.print();

    p1.free();
    p2.free();
    
    addedPoly.free();

    cout << endl;

    return 0;
}

/* ===========================================================
Output:
    Enter Max deg of first Poly: 2
    Enter co-efficient of deg 2: -5 
    Enter co-efficient of deg 1: 6
    Enter co-efficient of deg 0: 4

    Enter Max deg of second Poly: 3
    Enter co-efficient of deg 3: -4
    Enter co-efficient of deg 2: 6
    Enter co-efficient of deg 1: 5
    Enter co-efficient of deg 0: 2
    ((-4x**3) + (x**2) + (11x) + (6)) = 0

 * ========================================================== */

