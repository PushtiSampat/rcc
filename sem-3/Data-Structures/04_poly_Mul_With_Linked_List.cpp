/* ===========================================================

 * Roll No: 30
 *
 * File:      poly_Mul_With_Linked_List.cpp
 * Copyright: 21-Aug-2020 by Ajinkya Rathod(ajinzrathod)
 *
 * Content:  Write a program to Multiply two Polynomials
 *           using Linked List
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
        if (nextTerm) {delete nextTerm;}
    }
};

class Poly
{
    int degree;
    Term *head;

public:
    Poly()
    {
        degree = 0;
        head = NULL;
    }

    Poly(int degree)
    {
        this->degree = degree;
        head = NULL;
    }

    Poly(const Poly &p)
    {
        this->degree = p.degree;
        this->head = p.head;
    }

    int getDegree()
    {
        return degree;
    }

    Term *getInitialTerm()
    {
        return this->head;
    }

    void setDegree(int degree)
    {
        this->degree = degree;
    }

    void add(Term *newTerm)
    {
        if (!head)
            head = newTerm;
        else
        {
            Term *iterator = head;
            while (iterator->getNextTerm()){
                iterator = iterator->getNextTerm();
            }
            iterator->setNextTerm(newTerm);
        }
    }

    void print()
    {
        Term *currentTerm = head;
        cout << "(";
        if (currentTerm)
        {
            currentTerm->print();
            currentTerm = currentTerm->getNextTerm();
        }

        while (currentTerm)
        {
            cout << " + ";
            currentTerm->print();
            currentTerm = currentTerm->getNextTerm();
        }
        cout << ") = 0";
    }

    void read()
    {
        for (int i = degree; i >= 0; i--){
            float coeff;
            cout << "Enter co-efficient of degree " << i << ": ";
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
        while (currentTerm) {
            if (currentTerm->getPower() == power)
                currentTerm->setCoeff(coeff);
            currentTerm = currentTerm->getNextTerm();
        }
    }

    void zeroes()
    {
        for (int i = degree; i >= 0; i--) {
            add(new Term(0, i));
        }
    }

    Poly operator*(Poly p2)
    {
        int resultantDegree = this->degree + p2.getDegree();

        Poly result(resultantDegree);
        result.zeroes();

        Term *iter = head;
        while (iter)
        {
            Term *iterator2 = p2.getInitialTerm();
            while (iterator2)
            {
                float power1 = iter->getPower();
                float power2 = iterator2->getPower();
                float coeff = result.getCoeff(power1 + power2);

                coeff += this->getCoeff(power1) * p2.getCoeff(power2);
                result.setCoeff(coeff, (power1 + power2));

                iterator2 = iterator2->getNextTerm();
            }
            iter = iter->getNextTerm();
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
    int degree;

    // Reading First Polynomial
    cout << "Enter the degree of first Poly: ";
    cin >> degree;

    Poly p1(degree);
    p1.read();

    // Reading Second Polynomial
    cout << "\nEnter the degree of second Poly: ";
    cin >> degree;

    Poly p2(degree);
    p2.read();

    // Multiplying Polynomials
    Poly multipliedPoly = p1 * p2;
    multipliedPoly.print();
    cout << endl;

    // Freeing Memory
    p1.free();
    p2.free();
    
    multipliedPoly.free();

    return 0;
}

/* ===========================================================
Output:
    Enter Max deg of first Poly: 1
    Enter co-efficient of deg 1: 10
    Enter co-efficient of deg 0: 20

    Enter Max deg of second Poly: 1
    Enter co-efficient of deg 1: 20
    Enter co-efficient of deg 0: 10
    ((30x) + (30)) = 0

 * ========================================================== */

