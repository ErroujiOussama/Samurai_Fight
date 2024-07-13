#include <iostream>
using namespace std;

class insured{
    protected:
    int amount;
    string type;
public:
    insured(float amt,string tp){
        amount = amt;
        type = tp;
    }
     virtual void diplay() const{
        cout << "amount: " << amount <<"\n" << "type: " << type <<endl;
    }
};

class computer: public virtual insured{
protected:
    int ram, hd;
public:
    computer(float amt,string tp, int vhd, int vram):insured(amt, tp),hd(vhd),ram(vram){
        ram = vram;
        hd = vhd;
    }
     virtual void diplay() const{
        insured::diplay();
        cout << "ram: " << ram <<"\n" << "hd: " << hd <<endl;
    }
};

class baggage: public virtual insured{
protected:
    float weight;
public:
    baggage(float amt,string tp, float v_weight):insured(amt, tp),weight(v_weight){};
     virtual void diplay() const{
        cout << "weight: " << weight <<endl;
    }
};

class laptop: public  computer, public baggage{
    float thickness;
public:
    laptop(float amt,string tp, int vhd, int vram, float v_weight,float v_thickness):
    insured( amt, tp),
    computer(amt, tp, vhd, vram),baggage( amt, tp, v_weight), thickness(v_thickness){};
    void diplay() const{        
	     baggage::diplay();
        computer::diplay();
        cout << "thickness: " << thickness <<endl;
    }
};

int main()
{
    cout<<"---------------\n";
    laptop obj3(1,"iii",2, 3, 99,0.9);
    obj3.diplay();
}