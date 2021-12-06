#include <iostream>

using namespace std;

class REsistance{
    protected:
    int resistance1, resistane2, resistance3, voltage ;
    public:
    int set_values (int a,int b,int c,int d)
    {resistance1=a;resistane2=b;resistance3=c;voltage=d;}
    virtual double averageresistance(void) =0 ;
    int printaverageresistance(void)
    {
        cout << this->averageresistance() << endl;
    }

};

class Avpr: public REsistance{ // Avpr = average parallel resistance
    public:
    double averageresistance (void)
    {
        return 1.0/(1.0/resistance1+1.0/resistane2+1.0/resistance3);
        
    }
};

class Avcr:public REsistance { // Avcr = average series resistance
    public:
    double averageresistance(void)
    {
        return(resistance1+resistane2+resistance3);
    }
};
    
class parallelcurrent:public REsistance{
    public:
    double averageresistance(void)
    {
        return double(voltage) / (1.0/(1.0/resistance1+1.0/resistane2+1.0/resistance3));
    }
};

class seriescurrent:public REsistance{
    public:
    double averageresistance(void)
    {
        return double(voltage) / (resistance1+resistane2+resistance3);
    }
};

int main()
    {
        again:
        int a;
        cout << " resistanc1 from (1 to 100) = " << endl;
        cin >>a;
        if (a>=1 && a<=100){}
        else
        {
                cout << "the value is not in the range" << endl;
                goto again;
        }
        again2:
        int b;
        cout << "resistance2 from (1 to 100) = " << endl;
        cin >>b;
        if (b>=1 && b<=100){}
        else
        {
            cout << "the value is not in the range" << endl;
            goto again2;
        }
        again3:
        int c;
        cout << "resistance3  from (1 to 100) = " << endl;
        cin >>c;
        if(c>=1 && c<=100){}
        else
        {
            cout << "the values is not in the range" << endl;
            goto again3;
        }
        again4:
        int d;
        cout << " what is the voltage ? " << endl;
        cin >> d;
        if(d>=0){}
        else{goto again4;}
        REsistance * ppoly1=new Avpr;
        REsistance * ppoly2=new Avcr;
        REsistance * ppoly3=new parallelcurrent;
        REsistance * ppoly4=new seriescurrent;
        ppoly1->set_values (a,b,c,0);
        ppoly2->set_values (a,b,c,0);
        ppoly3->set_values (a,b,c,d);
        ppoly4->set_values (a,b,c,d);
        cout << "the average parallel resistance is :" << endl;
        ppoly1->printaverageresistance();
        cout << " Ohms" << endl;
        cout << "the average series resistance is :" << endl;
        ppoly2->printaverageresistance();
        cout << " Ohms" << endl;
        cout << "the curent in parallel connectin is : " << endl;
        ppoly3->printaverageresistance();
        cout << " AMPs" << endl;
        cout << "the current in series connection is : " << endl;
        ppoly4->printaverageresistance();
        cout << " AMPs" << endl;
        delete ppoly1;
        delete ppoly2;
        delete ppoly3;
        delete ppoly4;
        return 0;
    }
