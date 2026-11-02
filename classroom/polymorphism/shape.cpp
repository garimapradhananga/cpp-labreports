#include <iostream>
using namespace std;
class Shape
{
public:
    virtual void area()
    {
        cout << "Area of Shape" << endl;
    }
};
class Circle : public Shape
{
public:
    void area()
    {
        cout << "Area of Circle = πr²" << endl;
    }
};

class Rectangle : public Shape
{
public:
    void area()
    {
        cout << "Area of Rectangle = l × b" << endl;
    }
};

int main()
{
    Shape *ptr;

    Circle c;
    Rectangle r;

    ptr = &c;
    ptr->area();

    ptr = &r;
    ptr->area();

    return 0;
}