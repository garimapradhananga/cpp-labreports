/*wap to make billing system of a department store, retrieve data to/from files. use manipulators*/
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
class item{
    private:
        char name[20];
        int quantity;
        float price;
    public:
        void getdata(){
            cout << "Enter item name, quantity and price: ";
            cin >> name >> quantity >> price;
        }
        float gettotal(){
            return quantity * price;
        }
        void writetofile(ofstream &out){
            out << name << " " << quantity << " " << price << endl;
        }
        void readfromfile(ifstream &in){
            in >> name >> quantity >> price;
        }
        void display(){
            cout << left << setw(20) << name << setw(10) << quantity << setw(10) << price << setw(10) << gettotal() << endl;
        }
};
int main(){
    int n;
    float total=0;
    cout << "Enter number of items: ";
    cin >> n;
    item items[n];
    ofstream out("items.txt", ios::out);
    if (!out){
        cout<<"Error opening file!" << endl;
        return 1;
    }
    for (int i = 0; i < n; i++){
        cout << "Enter details of item " << i + 1 << ":" << endl;
        items[i].getdata();
        items[i].writetofile(out);
    }
    out.close();
    ifstream in("items.txt", ios::in);
    if (!in){
        cout<<"Error opening file!" << endl;
        return 1;
    }
    item bill[n];
    for (int i = 0; i < n; i++){
        bill[i].readfromfile(in);
    }
    in.close();
    cout<<"\n";
    cout<<"\tBILLING SYSTEM"<<endl;
    cout << left << setw(20) << "Item Name" << setw(10) << "Quantity" << setw(10) << "Price" << setw(10) << "Total" << endl;
    cout<<"--------------------------------"<<endl;
    for (int i = 0; i < n; i++){
        bill[i].display();
        total = total + bill[i].gettotal();
    }
    cout<<"--------------------------------"<<endl;
    cout << left << setw(20) << "Total" << setw(10) << "" << setw(10) << "" << setw(10) << total << endl;
    return 0;
}