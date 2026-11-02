#include <iostream>
using namespace std;
class Date {
    int day, month, year;
public:
    Date(int d = 0, int m = 0, int y = 0) {
        day = d;
        month = m;
        year = y;
    }
    void getData() {
        cout << "Enter day, month and year: ";
        cin >> day >> month >> year;
    }
    Date operator+(Date d) {
        Date temp;
        temp.day = day + d.day;
        temp.month = month + d.month;
        temp.year = year + d.year;
        while (temp.day > 30) {
            temp.day -= 30;
            temp.month++;
        }
        while (temp.month > 12) {
            temp.month -= 12;
            temp.year++;
        }
        return temp;
    }
    void display() {
        cout << day << "/" << month << "/" << year << endl;
    }
};
int main() {
    Date d1, d2, d3;
    cout << "Enter first date:" << endl;
    d1.getData();
    cout << "Enter second date:" << endl;
    d2.getData();
    d3 = d1 + d2;
    cout << "\nSum of dates: ";
    d3.display();
    return 0;
}