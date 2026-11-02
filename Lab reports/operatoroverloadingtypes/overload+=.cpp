#include <iostream>
using namespace std;

class Number
{
    int num;

public:
    Number(int n = 0)
    {
        num = n;
    }

    void operator+=(Number n)
    {
        num = num + n.num;
    }

    void show()
    {
        cout << num;
    }
};

int main()
{
    Number n1(10);
    Number n2(5);

    n1 += n2;

    n1.show();

    return 0;
}