#include <iostream>
using namespace std;
class Sample {
public:
    int x;          // instance member variable
    static int y;   // static member variable
};
int Sample::y = 10; // definition of static member
int main() {
    cout << Sample::y << endl; // access without object
    Sample s1;
    cout << s1.y; // access with object
    return 0;
}