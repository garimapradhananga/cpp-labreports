#include <iostream>
#include <cstring>
using namespace std;
class String {
    char *s;
    int len;
public:
    void getstring(int size) {
        len = size + 1;      // space for '\0'
        s = new char[len];
        cin >> s;
    }
    String operator+(String obj) {
        String temp;
        temp.len = strlen(s) + strlen(obj.s) + 1;
        temp.s = new char[temp.len];
        strcpy(temp.s, s);
        strcat(temp.s, obj.s);
        return temp;
    }
    void display() {
        cout << s;
    }
    ~String() {
        delete[] s;
    }
};
int main() {
    String s1, s2;
    int n1, n2;
    cout << "Enter size of string 1: ";
    cin >> n1;
    cout << "Enter string 1: ";
    s1.getstring(n1);
    cout << "Enter size of string 2: ";
    cin >> n2;
    cout << "Enter string 2: ";
    s2.getstring(n2);
    String s3 = s1 + s2;   // important
    cout << "Concatenated string: ";
    s3.display();
    return 0;
}