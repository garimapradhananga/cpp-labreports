#include <iostream>
using namespace std;
class Time {
private:
    int hr,min,sec;
public:
    void input() {
        cout << "Enter hour, minute and second: ";
        cin >> hr>>min>>sec;
    }
    void add(Time t1, Time t2) {
        hr = t1.hr + t2.hr;
        min = t1.min + t2.min;
        sec = t1.sec + t2.sec;
        if(sec >= 60) {
            sec -= 60;
            min++;
        }
        if(min >= 60) {
            min -= 60;
            hr++;
        }
    }

    void subtract(Time t1, Time t2) {
        hr = t1.hr - t2.hr;
        min = t1.min - t2.min;
        sec = t1.sec - t2.sec;

        if(sec < 0) {
            sec += 60;
            min--;
        }

        if(min < 0) {
            min += 60;
            hr--;
        }
    }
    void display() {
        cout << hr << " hr " << min << " min " << sec << " sec" << endl;
    }
};
int main() {
    Time t1, t2, sum, diff;
    cout << "Enter First Time:\n";
    t1.input();
    cout << "Enter Second Time:\n";
    t2.input();
    sum.add(t1, t2);
    diff.subtract(t1, t2);
    cout << "\nAdded Time: ";
    sum.display();
    cout << "Subtracted Time: ";
    diff.display();
    return 0;
}