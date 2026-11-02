#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Stack
{
    vector<T> arr;

public:
    void push(T value)
    {
        arr.push_back(value);
    }

    void pop()
    {
        if (arr.empty())
        {
            cout << "Stack Underflow" << endl;
        }
        else
        {
            cout << "Popped Element: " << arr.back() << endl;
            arr.pop_back();
        }
    }

    void display()
    {
        if (arr.empty())
        {
            cout << "Stack is Empty" << endl;
        }
        else
        {
            cout << "Stack Elements: ";

            for (int i = arr.size() - 1; i >= 0; i--)
            {
                cout << arr[i] << " ";
            }

            cout << endl;
        }
    }
};

int main()
{
    Stack<int> s1;

    s1.push(10);
    s1.push(20);
    s1.push(30);

    cout << "Integer Stack" << endl;
    s1.display();

    s1.pop();
    s1.display();

    return 0;
}