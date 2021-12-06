#include <iostream>

using namespace std;
// I used my experience to write the theorem
//I hope you like it

// Nikzad Dehghani

int main()
{
    cout <<"Fibonacci series:"<<endl;
    cout <<"Enter the number of therms"<<endl;
    int n;
    cin >>n;
    int first=0;
    cout <<first;
    int second=1;
    cout <<"\n"<<second;
    int third;
    for(third=1;third<=n;third++)
    {
        third=first+second;
        cout <<"\n"<<third;
        first=second;
        second=third;
    }
}
