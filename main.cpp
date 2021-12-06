#include <iostream>
#include <cmath>

using namespace std;

double myformula (int t,int y)
{
    double dydt;
    dydt = exp(y) - 5*pow(y,6) + 1;
    return dydt;
}
int main()
{
    int number = 24;
    cout << number <<" the value number " << endl;
    cout << myformula(8,5) << endl << "------------------------------------------" << endl;
    cout << &myformula << endl;

    return 0;
}
