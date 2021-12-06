#include <iostream>

using namespace std;

 int reading_from_input ()
    {
        int totall;

        again :
        cout << " enter the number form 1 to 1000 : " ;
        cin >> totall;

        if (totall>=1 && totall<=1000)
        {
            cout << "drink volume in liters : " << totall << " Liters " << endl;
        }
       else
        {
            goto again;
        }

    return totall;
}


void cal_for_vessel (int totall)
{
    int volume;
    int num = 1000; // in Cm^3
    int v0 = 30*40*100; // volume of vessel in liters
    int v2  ; // the occupied volume as out input

    v2= totall ;

    cout << "total volume of vessel is in cm^3 : " << v0 << endl;
    cout << "total volume of vessel in liters is : " << v0/num << endl;

    if (v2==(v0/num) )
    {
        cout << " the vessel if full and nothing remains " << endl;
        return;
    }

    if (v2>(v0/num))
    {
        cout << "the vessel con not hold  "<< v2-120 << " liters " << endl;
        cout <<" the remaining is : " << v2-120 << " Liters " << endl;
    }
    else if (v2<(v0/num))
    {
        cout << "vessel can hold : " << v2 << " liters" << endl;
    }


}

int main ()
{
    int entervalue;
   entervalue = reading_from_input ();
   cal_for_vessel(entervalue);

}

