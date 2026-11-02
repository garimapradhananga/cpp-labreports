#include <iostream>
using namespace std;
template <class T>
class Stack
{
    T arr[10];
    int top;
public:
    Stack()
    {
        top = -1;
    }
    void push(T value)
    {
        if (top == 9)
        {
            cout << "Stack Overflow" << endl;
        }
        else
        {
            top++;
            arr[top] = value;
        }
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
        }
        else
        {
            cout << "Popped Element: " << arr[top] << endl;
            top--;
        }
    }
    void display()
    {
        if (top == -1)
        {
            cout << "Stack is Empty" << endl;
        }
        else
        {
            cout << "Stack Elements: ";
            for (int i = top; i >= 0; i--)
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
    Stack<char> s2;
    s2.push('A');
    s2.push('B');
    s2.push('C');
    cout << "\nCharacter Stack" << endl;
    s2.display();
    s2.pop();
    s2.display();
    Stack<double> s3;
    s3.push(1.5);
    s3.push(2.5);
    s3.push(3.5);
    cout << "\nDouble Stack" << endl;
    s3.display();
    s3.pop();
    s3.display();
    return 0;
}