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
        
        virtual double calculateResistance(){
        }
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
};

int main()
{
    Circuit c;
    c.getCurrent();
    Resistance *r = new Resistance;
    SeriesResistance sr;
    r = &sr;
    c.setResistance(r);
    c.getResistance();
    cout << c.calculateVoltage() << endl;
    
    return 0;
}
