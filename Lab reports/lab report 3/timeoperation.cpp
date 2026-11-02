#include<iostream>
using namespace std;

class time
{
    int hr, min, sec;

public:

    time()
    {
        hr = 0;
        min = 0;
        sec = 0;
    }

    time(int h, int m, int s)
    {
        hr = h;
        min = m;
        sec = s;
    }

    void add(time t1, time t2)
    {
        hr = t1.hr + t2.hr;
        min = t1.min + t2.min;
        sec = t1.sec + t2.sec;

        if (sec >= 60)
        {
            min = min + sec / 60;
            sec = sec % 60;
        }

        if (min >= 60)
        {
            hr = hr + min / 60;
            min = min % 60;
        }
    }

    void subtract(time t1, time t2)
{
    // If t1 is smaller, swap them
    if (t1.hr < t2.hr ||
       (t1.hr == t2.hr && t1.min < t2.min) ||
       (t1.hr == t2.hr && t1.min == t2.min && t1.sec < t2.sec))
    {
        time temp = t1;
        t1 = t2;
        t2 = temp;
    }

    hr = t1.hr - t2.hr;
    min = t1.min - t2.min;
    sec = t1.sec - t2.sec;

    if (sec < 0)
    {
        min--;
        sec += 60;
    }

    if (min < 0)
    {
        hr--;
        min += 60;
    }
}

    void display()
    {
        cout << hr << " hr "
             << min << " min "
             << sec << " sec" << endl;
    }
};

int main()
{
    time t1(4,3,2);
    time t2(6,7,8);

    time sum, diff;

    sum.add(t1,t2);
    cout << "Addition: ";
    sum.display();

    diff.subtract(t1,t2);
    cout << "Subtraction: ";
    diff.display();

    return 0;
}