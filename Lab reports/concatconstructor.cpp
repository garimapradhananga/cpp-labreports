#include<iostream>
#include<cstring>
using namespace std;
class String
{
    char *s;
public:
    String(){
        s = new char[1];
        strcpy(s, "");
    }
    String(int size){
        s = new char[size];
    }
    void getString(){
        cin >> s;
    }
    void display(){
        cout << s;
    }
    String operator+(String obj) {
        String temp(strlen(s) + strlen(obj.s) + 1);
        strcpy(temp.s, s);
        strcat(temp.s, obj.s);
        return temp;
    }
};
int main(){
    String s1(20), s2(20), s3(40);
    cout << "Enter String 1: ";
    s1.getString();
    cout << "Enter String 2: ";
    s2.getString();
    s3 = s1 + s2;
    cout << "Concatenated String: ";
    s3.display();
    return 0;
}