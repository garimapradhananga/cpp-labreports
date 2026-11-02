#include<iostream>
#include<cstring>
using namespace std;
class concatenation{
private:
char str[50];
public:
    void input(){
        cin >> str;
    }
    void display(){
        cout << str;
    }
    concatenation operator +(concatenation c){
        concatenation temp;
        strcpy(temp.str, str);
        strcat(temp.str, " ");
        strcat(temp.str, c.str);
        return temp;
    }
};
int main(){
    concatenation c1, c2, c3;
    cout << "Enter first string: ";
    c1.input();
    cout << "Enter second string: ";
    c2.input();
    c3 = c1 + c2;
    cout << "Concatenated String: ";
    c3.display();
    return 0;
}