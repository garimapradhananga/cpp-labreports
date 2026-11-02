//src conversion
#include <iostream>
using namespace std;

const float pi = 3.14;

class degree;   // forward declaration

class radian
{
    float rad;

public:
    radian()
    {
        rad = 0;
    }

    radian(float r)
    {
        rad = r;
    }

    void getdata()
    {
        cin >> rad;
    }

    operator degree();
};

class degree
{
    float deg;

public:
    degree()
    {
        deg = 0;
    }

    degree(float d)
    {
        deg = d;
    }

    void show()
    {
        cout << deg;
    }
};

radian::operator degree()
{
    return degree((rad * 180) / pi);
}

int main()
{
    degree d;
    radian r;

    cout << "Enter angle in radians: ";
    r.getdata();

    d = r;

    cout << "Angle in degrees: ";
    d.show();

    return 0;
}