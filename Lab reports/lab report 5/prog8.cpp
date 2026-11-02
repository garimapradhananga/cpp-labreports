#include <iostream>
#include <cmath>
using namespace std;
class Polar;
class Rectangle {
    float x, y; 
public:
    Rectangle(float a, float b) {
        x = a;
        y = b;
    }
    operator Polar();
};
class Polar {
    float r, theta;
public:
    Polar(float radius = 0, float angle = 0) {
        r = radius;
        theta = angle;
    }
    void display() {
        cout << "Radius = " << r << endl;
        cout << "Angle (in degrees) = " << theta << endl;
    }
};
Rectangle::operator Polar() {
    float radius = sqrt(x * x + y * y);
    float angle = atan(y / x) * 180 / 3.14159;
    return Polar(radius, angle);
}
int main() {
    float x, y;
    cout << "Enter x coordinate: ";
    cin >> x;
    cout << "Enter y coordinate: ";
    cin >> y;
    Rectangle rect(x, y);
    Polar p;
    p = rect;
    p.display();
    return 0;
}
/*In case of udf to udf conversion by writing the conversion routine in destination class
#include<iostream>
#include<cmath>
using namespace std;

class Rectangle
{
    float x, y;

public:
    Rectangle(float a=0, float b=0)
    {
        x = a;
        y = b;
    }

    float getx()
    {
        return x;
    }

    float gety()
    {
        return y;
    }
};

class Polar
{
    float r, theta;

public:
    Polar(float radius=0, float angle=0)
    {
        r = radius;
        theta = angle;
    }

    // Constructor Conversion
    Polar(Rectangle rect)
    {
        r = sqrt(rect.getx()*rect.getx() +
                 rect.gety()*rect.gety());

        theta = atan(rect.gety()/rect.getx()) * 180 / 3.14159;
    }

    void display()
    {
        cout<<"Radius = "<<r<<endl;
        cout<<"Angle = "<<theta<<endl;
    }
};

int main()
{
    Rectangle rect(3,4);

    Polar p = rect;

    p.display();
}
*/