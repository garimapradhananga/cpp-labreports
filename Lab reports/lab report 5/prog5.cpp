#include <iostream>
using namespace std;
class Dollar {
    float dollar;
public:
    Dollar(float d = 0) : dollar(d) {}
    void show_dollar() {
    cout << "Money in Dollar: " << dollar << endl;
    }
    float get_dollar() { 
        return dollar; 
    }
};
class Ruppee {
    float ruppee;
    public:
    Ruppee(float r = 0) : ruppee(r) {}
    Ruppee(Dollar d) {
    ruppee = d.get_dollar() * 124.89;
    }
    void show_ruppee() {
    cout << "Money in Ruppee: " << ruppee << endl;
    }
};
int main() {
    float rup;
    cout<<"enter value: "<<endl;
    cin>>rup;
    Dollar d1(rup);
    Ruppee r1;
    d1.show_dollar();
    r1 = d1;
    r1.show_ruppee();
    return 0;
}
