#include <iostream>
#include <math.h>
#include <iomanip>
#include <iterator>
#include <map>
#include <numeric>
#include "poly.h"

using namespace std;

Poly::Poly(){}

Poly::~Poly()
{
    this->powerCoefficients.clear();
}

Poly::Poly(double freeCoefficient) 
{
	powerCoefficients.insert(pair<int, double>(0, freeCoefficient));
}

double &Poly::operator [] (int index)
{
	return powerCoefficients[index];
}

ostream& operator << (ostream& out, const Poly& p) 
{
	bool firstElement = true;
	map<int, double>::const_reverse_iterator powerOfX = p.powerCoefficients.rbegin();//Returns a const_reverse_iterator pointing to the theoretical element preceding the first element in the container (which is considered its reverse end).
	for(; powerOfX != p.powerCoefficients.rend(); powerOfX++) 
    {
		if(powerOfX->second == 0) 
        {
			continue;
		}
		if(powerOfX->second > 0)
        {
			if(!firstElement) out << " + ";
		}
		else 
        {
			out << " - ";
		}
		firstElement = false;
		if(abs(powerOfX->second) != 1)
        {
            out << abs(powerOfX->second);
        }
		if(powerOfX->first == 0) continue;
		out << "x";
		if(powerOfX->first != 1)
        {
            out << "^" << powerOfX->first;
            
        }
	}
	return out;
}

Poly Poly::operator - () 
{
	Poly negated;
	for(const auto& powerOfX : powerCoefficients) //const auto &items = someObject.someMethod();//const T& // I'm reading this
    {
		negated[powerOfX.first] = -powerOfX.second;
	}
	return negated;
}

Poly& Poly::operator = (const Poly& p) 
{
	powerCoefficients = p.powerCoefficients; 
	return *this;
}

double Poly::operator () (double valueX) // to check Value of polynomial p1 at given  point
{
	double polyValue = 0;
	for(const auto& powerOfX : powerCoefficients) 
    {
		polyValue += powerOfX.second * pow(valueX, powerOfX.first);
	}
	return polyValue;
}
 

Poly operator * (const Poly& p1, const Poly& p2) 
{
	Poly product;
	for(const auto& powerOfX1 : p1.powerCoefficients) 
    {
		for(const auto& powerOfX2 : p2.powerCoefficients)
        {
			product[powerOfX1.first + powerOfX2.first] = powerOfX1.second * powerOfX2.second;
		}
	}

    return product;

}


Poly operator + (const Poly& p1, const Poly& p2)
{   
    map<int, double>::const_iterator p1Iter = p1.powerCoefficients.begin();
    map<int, double>::const_iterator p2Iter = p2.powerCoefficients.begin();
    Poly sum ;
    while(p1Iter!=p1.powerCoefficients.end() || p2Iter!=p2.powerCoefficients.end())
    {
        if(p1Iter==p1.powerCoefficients.end())
        {
            while(p2Iter!=p2.powerCoefficients.end())
            {
                sum[p2Iter -> first] = p2Iter -> second;
                p2Iter++;
            }
            break;
        }else if(p2Iter==p2.powerCoefficients.end())
        {
            while(p1Iter!=p1.powerCoefficients.end())
            {
                sum[p1Iter -> first] = p1Iter -> second;
                p1Iter++;
            }
            break;
        }
        if(p1Iter->first == p2Iter->first)
        {
            if((p1Iter->second) != -(p2Iter->second))
            {
                sum[p1Iter->first] = (p1Iter->second) + (p2Iter->second);
            }
        p1Iter++;
        p2Iter++;
        }else if(p1Iter->first > p2Iter->first)
        {
            sum[p2Iter->first] = p2Iter->second;
            p2Iter++;
        }else if(p2Iter->first > p1Iter->first)
        {
            sum[p1Iter->first] = p1Iter->second;
            p1Iter++;
        }
    }
    return sum;
}


Poly operator - (const Poly& p1, const Poly& p2)
{   
    map<int, double>::const_iterator p1Iter = p1.powerCoefficients.begin();
    map<int, double>::const_iterator p2Iter = p2.powerCoefficients.begin();
    Poly difference;
    while(p1Iter!=p1.powerCoefficients.end() || p2Iter!=p2.powerCoefficients.end())
    {
        if(p1Iter==p1.powerCoefficients.end())
        {
            while(p2Iter!=p2.powerCoefficients.end())
            {
                difference[p2Iter -> first] = -(p2Iter -> second);
                p2Iter++;
            }
            break;
        }else if(p2Iter==p2.powerCoefficients.end())
        {
            while(p1Iter!=p1.powerCoefficients.end())
            {
                difference[p1Iter -> first] = (p1Iter -> second);
                p1Iter++;
            }
            break;
        }
        if(p1Iter->first == p2Iter->first)
        {
            if((p1Iter->second) - (p2Iter->second) != 0)
            {
                difference[p1Iter->first] = (p1Iter->second) - (p2Iter->second);
            }
        p1Iter++;
        p2Iter++;
        }
        else if(p1Iter->first > p2Iter->first)
        {
            difference[p2Iter->first] = -(p2Iter->second);
            p2Iter++;
        }
        else if(p2Iter->first > p1Iter->first)
        {
            difference[p1Iter->first] = p1Iter->second;
            p1Iter++;
        }
    }

    return difference;
}

