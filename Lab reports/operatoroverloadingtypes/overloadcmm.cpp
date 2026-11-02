#include <iostream>
using namespace std;

class Length
{
    int meter, centimeter;

public:
    Length(int m, int cm)
    {
        meter = m;
        centimeter = cm;
    }

    bool operator > (Length l)
    {
        return (meter * 100 + centimeter) >
               (l.meter * 100 + l.centimeter);
    }
    bool operator < (Length l){
        return (meter*100 +centimeter) < (l.meter*100 + l.centimeter);
    }
};

int main()
{
    Length l1(5, 20);
    Length l2(4, 80);

    if(l1 > l2)
        cout << "First length is greater";
    else if (l1 < l2)
        cout << "Second length is greater";
    else
        cout << "Both lengths are equal";

    return 0;
}