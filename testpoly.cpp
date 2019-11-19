#include <iostream>
#include "poly.h"

using namespace std;

int main() {
	Poly p1;															// Declare object representing polynomial p1	
	p1[3] = 0;															// Specify coefficients of p1 = 2x^3 + 3.6x + 7
	p1[1] = 3.6;
	p1[0] = 7;

	cout << "Polynomial p1: " << p1 << endl;							// Print p1 	
	
	Poly p2 = 5;														// Declare object representing polynomial p2 = 5
	p2[4] = 1;															// Specify additional coefficients of p2 = x^4 - 6x^2 + 3x + 5
	p2[2] = -6;
	p2[1] = 3;

	cout << "Polynomial p2: " << p2 << endl;							// Print p2

	Poly p3 = p1 + p2;													// Add p1 and p2 	
	cout << "Sum of polynomials p1 and p2: " << p3 << endl;

	p3 = p1 + 3;														// Add p1 and 3
	cout << "Sum of polynomial p1 and 3: " << p3 << endl;

	p3 = 3 + p1;														// Add 3 and p1
	cout << "Sum of 3 and polynomial p1: " << p3 << endl;

	p3 = p1 - p2;														// Subtract p2 from p1
	cout << "Difference of polynomials p1 and p2: " << p3 << endl;

	p3 = p1 - 7;														// Subtract 7 from p1
	cout << "Difference of polynomial p1 and 7: " << p3 << endl;

	p3 = 7 - p1;														// Subtract p1 from 7
	cout << "Difference of 7 and polynomial p1: " << p3 << endl;

	p3 = p1 * p2;														// Multiply p1 by p2 	
	cout << "Product of polynomials p1 and p2: " << p3 << endl;

	p3 = 2 * p1;														// Multiply p1 by 2 	
	cout << "Polynomial p1 multiplied by 2: " << p3 << endl;

	p3 = -p2;															// Calculate negation of p2
	cout << "Negation of polynomial p2: " << p3 << endl;

	double val = p1(1.5);												// Calculate value of p1 at point 1.5
	cout << "Value of polynomial p1 at point 1.5: " << val << endl;
}
