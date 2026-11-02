#include <iostream>
using namespace std;
class LandMeasure
{
    int ropani, ana, paisa, dam;
public:
    LandMeasure(int r = 0, int a = 0, int p = 0, int d = 0){
        ropani = r;
        ana = a;
        paisa = p;
        dam = d;
    }
    void getData()
    {
        cout << "Enter Ropani, Ana, Paisa and Dam: ";
        cin >> ropani >> ana >> paisa >> dam;
    }
    LandMeasure operator+(LandMeasure l)
    {
        LandMeasure temp;
        temp.dam = dam + l.dam;
        temp.paisa = paisa + l.paisa + temp.dam / 4;
        temp.dam %= 4;
        temp.ana = ana + l.ana + temp.paisa / 4;
        temp.paisa %= 4;
        temp.ropani = ropani + l.ropani + temp.ana / 16;
        temp.ana %= 16;
        return temp;
    }
    void display()
    {
        cout << ropani << " Ropani "<< ana << " Ana "<< paisa << " Paisa "<< dam << " Dam" << endl;
    }
};
int main(){
    LandMeasure l1, l2, l3;
    cout << "Enter first land measurement:" << endl;
    l1.getData();
    cout << "Enter second land measurement:" << endl;
    l2.getData();
    l3 = l1 + l2;
    cout << "\nSum = ";
    l3.display();
    return 0;
}