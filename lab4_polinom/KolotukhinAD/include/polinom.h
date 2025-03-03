#ifndef __POLINOM_H__
#define __POLINOM_H__
#pragma once
#include <iostream>
#include <math.h>
#include "list.h"

using namespace std;
struct Point
    {
        int x;
        int y;
        int z;
        Point(int _x, int _y, int _z): x(_x), y(_y), z(_z) {}
    };
struct Monom
{
    double multiplier;
    char variable;
    int varPower;
    Monom(double _multiplier, char _variable, int _varPower): multiplier(_multiplier), variable(_variable), varPower(_varPower) {};
    friend ostream& operator<<(ostream& os, const Monom& m) 
    {
        os << m.multiplier << m.variable << "^" << m.varPower;
        return os;
    }
    bool operator==(Monom& _other)
    {
        return (this->variable == _other.variable && this->varPower == _other.varPower);
    }
    Monom operator+(const Monom& _other)
    {
        return Monom(multiplier + _other.multiplier, variable, varPower);
    }
    Monom& operator=(const Monom& other)
    {
        if(this != &other)
        {
            multiplier = other.multiplier;
            variable = other.variable;
            varPower = other.varPower;
        }
        return *this;
    }
};

class Polinom
{
private:
    List<Monom> LIST;
public:
    Polinom(){}
    
    Polinom(const Polinom& other) 
    {
        LIST = other.LIST;
    }

    friend istream& operator>>(istream& is, Polinom& polinom)
    {
        int YesOrNot = 0;
        double mul = .0;
        char var = '0';
        int pow = 0;
        
        do
        {
            cout << "multiplier: "; cin >> mul;
            cout << "variable: "  ; cin >> var;
            cout << "power: "     ; cin >> pow;
            
            polinom.LIST.pushBack(Monom(mul, var, pow));    
            
            cout << "Continue? : "; cin >> YesOrNot;
            cout << endl;
        } while (YesOrNot != 0);
        return is;
    }

    friend ostream& operator<<(ostream& os, Polinom& polinom)
    {
        if (!polinom.LIST.isEmpty())
        {
            os << polinom.LIST[0];
            for (size_t i = 1; i < polinom.LIST.getSize(); i++)
            {
                os << " + " << polinom.LIST[i];
            }
        }
        return os;
    }

    void reduce()
    {
        int unicMonomIndex = 0;
        while (unicMonomIndex < LIST.getSize())
        {
            int c = unicMonomIndex + 1;
            while (c < LIST.getSize())
            {
                if (LIST[unicMonomIndex] == LIST[c])
                {
                    LIST[unicMonomIndex] = LIST[unicMonomIndex] + LIST[c];
                    LIST.removeFrom(c);
                } else
                    c++;
            }
            unicMonomIndex++;
        }
    }

    double calculate(Point p)
    {
        double res = 0.0;
        for (size_t i = 0; i < this->LIST.getSize(); i++)
        {
            if (LIST[i].variable == 'x')
            {
                res += LIST[i].multiplier * pow(p.x, LIST[i].varPower);
            }
            else if (LIST[i].variable == 'y')
            {
                res += LIST[i].multiplier * pow(p.y, LIST[i].varPower);
            }
            else if (LIST[i].variable == 'z')
            {
                res += LIST[i].multiplier * pow(p.z, LIST[i].varPower);
            }
        }
        return res;
    }

    Polinom operator+(const Polinom& other)
    {
        Polinom result(*this);
        for (int i = 0; i < other.LIST.getSize(); i++)
        {
            result.LIST.pushBack(other.LIST[i]);
        }
        result.reduce();
        return result;
    }

    Polinom& operator=(const Polinom& other)
    {
        if (this != &other)
        {
            LIST = other.LIST;
        }
        return *this;
    }

    Polinom& operator+=(const Polinom& other)
    {
        for (int i = 0; i < other.LIST.getSize(); i++)
        {
            LIST.pushBack(other.LIST[i]);
        }
        return *this;
    }
};
#endif
