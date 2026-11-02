#include <iostream>
#include <string>
using namespace std;
class Book {
public:
    string title;
    string author;
    float  price;
    string publisher;

    void display() {
        cout << "Title: " << title<< endl;
        cout << "Author: "<< author<< endl;
        cout << "Price: $" << price<< endl;
        cout << "Publisher: "<< publisher<< endl;
        cout << endl;
    }
};
int main() {
    Book* b1 = new Book;
    b1->title="Concepts of Physics";
    b1->author="H.C. Verma";
    b1->price=14.50;
    b1->publisher="Bharati Bhawan";
    b1->display();
    delete b1;
    Book* b2=new Book;
    b2->title="Organic Chemistry";
    b2->author="O.P. Tandon";
    b2->price=11.99;
    b2->publisher="G.R. Bathla Publications";
    b2->display();
    delete b2;
    return 0;
}