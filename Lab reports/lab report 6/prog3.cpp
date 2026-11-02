#include<iostream>
using namespace std;
class Course{
protected:
    char cname[50];
public:
    void getdata(){
        cout<<"Enter course name: ";
        cin>>cname;
    }
    void showdata(){
        cout<<"Course Name = "<<cname<<endl;
    }
};
class Mathematics : public Course{
public:
    void showdata(){
        cout<<"Mathematics Course"<<endl;
        Course::showdata();
    }
};
class Science : public Course{
public:
    void showdata(){
        cout<<"Science Course"<<endl;
        Course::showdata();
    }
};
class Engineering : public Course{
public:
    void showdata(){
        cout<<"Engineering Course"<<endl;
        Course::showdata();
    }
};
class Physics : public Science{
public:
    void showdata(){
        cout<<"Physics Course"<<endl;
        Science::showdata();
    }
};
class Chemistry : public Science{
public:
    void showdata(){
        cout<<"Chemistry Course"<<endl;
        Science::showdata();
    }
};
int main(){
    Mathematics m;
    Engineering e;
    Physics p;
    Chemistry c;
    m.getdata();
    m.showdata();
    e.getdata();
    e.showdata();
    p.getdata();
    p.showdata();
    c.getdata();
    c.showdata();
    return 0;
}