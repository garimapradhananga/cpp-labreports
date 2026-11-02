#include <iostream>
using namespace std;
class Sample {
    int x;
public:
    Sample(int a) {
        x = a;
    }
    void operator--() {      
        --x;
        cout << "Pre-decrement value = " << x << endl;
    }
    void operator--(int) {   
        int temp = x;
        x--;
        cout << "Post-decrement value = " << temp << endl;
    }
    void display() {
        cout << "Current value = " << x << endl;
    }
};

int main() {
    int n;
    cout << "Enter value: ";
    cin >> n;
    Sample s(n);
    --s;
    s.display();
    s--;
    s.display();
    return 0;
}