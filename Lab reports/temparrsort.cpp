#include<iostream>
using namespace std;

template <class t, int size>
class array {
    t a[size];

public:

    void input() {
        cout << "Enter elements: ";
        for (int i = 0; i < size; i++) {
            cin >> a[i];
        }
    }

    void sort() {
        t temp;

        for (int i = 0; i < size - 1; i++) {
            for (int j = i + 1; j < size; j++) {

                if (a[i] > a[j]) {
                    temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }

            }
        }
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << a[i] << " ";
        }
    }
};

int main() {

    array<int, 5> arr;

    arr.input();
    arr.sort();

    cout << "Sorted array: ";
    arr.display();

    return 0;
}