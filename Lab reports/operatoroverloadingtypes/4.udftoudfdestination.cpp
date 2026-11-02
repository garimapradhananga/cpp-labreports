#include<iostream>
using namespace std;

class Meter {
    float m;
public:
    Meter() { m = 0; }

    void getdata() {
        cout << "Enter distance in meters: ";
        cin >> m;
    }

    float getMeter() { return m; }
};

class KM {
    float km;
public:
    KM() { km = 0; }

    KM(Meter m) {
        km = m.getMeter() / 1000;
    }

    void showdata() {
        cout << "Distance in kilometers = " << km << " km";
    }
};

int main() {
    Meter m;
    KM k;

    m.getdata();
    k = m;
    k.showdata();

    return 0;
}