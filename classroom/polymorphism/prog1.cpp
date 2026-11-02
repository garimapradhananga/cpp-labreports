#include <iostream>
using namespace std;
class Animal
{
public:
      virtual void sound()
    {
        cout << "Animal makes a sound";
    }
};
class Dog : public Animal
{
public:
    void sound()
    {
        cout << "Dog barks";
    }
};
class cat : public Animal
{
public:
    void sound()
    {
        cout << "cat barks";
    }
};
int main()
{
    Animal *ptr;
    cat c;
    ptr = &c;
    ptr->sound();
    return 0;
}