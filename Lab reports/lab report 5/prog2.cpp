#include <iostream>
using namespace std;
class Number {
    int num;
public:
    Number(int n) {
        num = n;
    }
    void display() {
        cout << num << endl;
    }
    Number operator--() {
        --num;
        return *this;
    }
    Number operator--(int) {
        Number temp = *this;
        num--;
        return temp;
    }
};
int main() {
    int x;
    cout << "Enter a number: ";
    cin >> x;
    Number n(x);
    cout << "Original: ";
    n.display();
    --n;
    cout << "After Pre-decrement: ";
    n.display();
    n--;
    cout << "After Post-decrement: ";
    n.display();
    return 0;
}