/*#include<iostream>
using namespace std;
class sample{
    int x;
    public:
    void getdata(){
        cin>>x;
    }
    void display(){
        cout<<x;
    }
};
int main(){
    sample obj; //object creation
    obj.getdata(); //data initialization
    obj.display();
    return 0;
}
*/
//parameter initialization list
#include<iostream>
using namespace std;
class sample{
    int &x;
    public: 
    sample(int y):x(y){

    }
    void display(){
        cout<<x;
    }
    ~sample(){  //destructor:memory release not destroy
        cout<<"out of scope";
    }
};
int main(){
    sample obj(4); //object creation and data initialization 
   // obj.getdata(); //data initialization
    obj.display();
    return 0;
}

