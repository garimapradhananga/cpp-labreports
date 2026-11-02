#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

class book {
    char name[50];
    char author[50];

public:
    void input() {
        cout << "Enter name and author: " << endl;
        cin >> name >> author;
    }

    void show() {
        cout << "Name: " << left << setw(20) << name << endl;
        cout << "Author: " << setw(20) << author << endl;
    }
};

int main() {

    fstream file;

    file.open("book.txt", ios::in | ios::out | ios::app);

    if (!file) {
        cout << "Error opening file";
        return 1;
    }

    book b[5];
    book bo[5];

    int i;

    // Store 5 books
    for (i = 0; i < 5; i++) {
        b[i].input();
        file.write((char*)&b[i], sizeof(b[i]));
    }

    // Read from beginning
    file.seekg(0);

    i = 0;

    while (i < 5 && file.read((char*)&bo[i], sizeof(bo[i]))) {
        i++;
    }

    // Display
    for (i = 0; i < 5; i++) {
        bo[i].show();
    }

    file.close();

    return 0;
}