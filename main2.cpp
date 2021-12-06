#include <iostream>

using namespace std;

class Resistance{
    protected:
        double r1, r2;
    public:
        void getData()       
        {
            cout << "enter resistance amounts:" << endl;
            cin >> r1 >> r2;
        }        
        virtual double calculateResistance(){}
};

class SeriesResistance : public Resistance {
    public:
        double calculateResistance(){
            return r1+r2;
        }
};

class ParallelResistance : public Resistance {
    public:
        double calculateResistance(){
            return (r1*r2)/(r1+r2);
        }
};

class Circuit{
    public:
        double voltage, current;
        Resistance *resistance;
        
        void getVoltage()       
        {
            cout << "enter voltage:" << endl;
            cin >> voltage;
        }
        void getCurrent()       
        {
            cout << "enter current:" << endl;
            cin >> current;
        }
        void getResistance()       
        {
            resistance->getData();
        }
        
        void setVoltage(double v){
            voltage = v;
        }
        void setCurrent(double i){
            current = i;
        }
        void setResistance(Resistance *r){
            resistance = r;
        }
        double calculateVoltage(){
            return current * resistance->calculateResistance();
        }
        double calculateCurrent(){
            return voltage / resistance->calculateResistance();
        }
};

int main()
{
    Circuit c;
    c.getVoltage();
    Resistance *r = new Resistance;
    cout << "enter 1 if you have parallel resistances, or 2 if series" << endl;
    int temp;
    cin >> temp;
    if(temp == 1){
        ParallelResistance pr;
        r = &pr;
    }
    else{
        SeriesResistance sr;
        r = &sr;
    }
    c.setResistance(r);
    c.getResistance();
    cout << "The resistance is " << c.resistance->calculateResistance() << endl;
    cout << "The current is: " << c.calculateCurrent() << endl;
    
    return 0;
}
