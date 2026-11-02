#include<iostream>
#include<fstream>
using namespace std;

class student {
    char name[50];
    int rn;

public:
    int marks;
    void getdata() {
        cout << "Enter name, roll number and marks: " << endl;
        cin >> name >> rn >> marks;
    }

    void showdata() {
        cout << "Name = " << name
             << "  Roll number = " << rn
             << "  Marks = " << marks << endl;
    }
};

int main() {
    int n, i, j;

    cout << "Enter the number of students: ";
    cin >> n;

    fstream file;
    file.open("student.txt", ios::out | ios::in | ios::app);

    if (!file) {
        cout << "Error opening file";
        return 1;
    }

    student s[10];
    student st[10];
    student temp;

    // Input and store records
    for (i = 0; i < n; i++) {
        s[i].getdata();
        file.write((char*)&s[i], sizeof(s[i]));
    }

    // Read records from file
    file.seekg(0);

    i = 0;
    while (file.read((char*)&st[i], sizeof(st[i]))) {
        i++;
    }

    // Sort in ascending order
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (st[i].marks > st[j].marks) {
                temp = st[i];
                st[i] = st[j];
                st[j] = temp;
            }
        }
    }

    cout << "\nIn ascending order:\n";

    for (i = 0; i < n; i++) {
        st[i].showdata();
    }

    file.close();

    return 0;
}