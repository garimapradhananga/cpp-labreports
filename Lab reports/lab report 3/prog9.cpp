#include <iostream>
#include <cstring>
using namespace std;
class Book {
private:
    char *title;
    char *author;
    float price;
    char *publisher;
public:
    Book() {
        char temp[100];

        cout << "Enter Title: ";
        cin >> temp;
        title = new char[strlen(temp) + 1];
        strcpy(title, temp);
        cout << "Enter Author: ";
        cin >> temp;
        author = new char[strlen(temp) + 1];
        strcpy(author, temp);
        cout << "Enter Price: ";
        cin >> price;
        cout << "Enter Publisher: ";
        cin >> temp;
        publisher = new char[strlen(temp) + 1];
        strcpy(publisher, temp);
    }

    void display() {
        cout << "\nBook Details:\n";
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price: " << price << endl;
        cout << "Publisher: " << publisher << endl;
    }

    ~Book() {
        delete[] title;
        delete[] author;
        delete[] publisher;
        cout << "\nDestructor called (memory freed)." << endl;
    }
};
int main() {
    Book b;
    b.display();

    return 0;
}