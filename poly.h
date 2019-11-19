#include <map>
 
using namespace std;
 
class Poly
{
public:
    Poly();
    Poly(double); //the constructor to initialize a polynomial equal to the given constant
    ~Poly();
    double &operator[] (int);
    std::map<int, double> powerCoefficients;
    Poly operator - ();
    Poly& operator = (const Poly& p);
    double operator() (double);
};
 
ostream& operator << (ostream& out, const Poly& p);
Poly operator + (const Poly& p1, const Poly& p2);
Poly operator - (const Poly& p1, const Poly& p2);
Poly operator * (const Poly& p1, const Poly& p2);
