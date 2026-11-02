#include<iostream>
using namespace std;
class edistance;
class mdistance{
    int meter,cm;
    public:
    void input(){
    cout<<"Enter meter and cm: ";
    cin>>meter>>cm;
}
void display(){
    cout<<meter<<" meter "<<cm<<" cm"<<endl;
}
friend mdistance add(mdistance,edistance);
};
class edistance{
int feet,inch;
public:
void input(){
cout<<"Enter feet and inch: ";
cin>>feet>>inch;
}
void display(){
    cout<<feet<<" feet "<<inch<<" inch"<<endl;
    }
friend mdistance add(mdistance,edistance);
};
mdistance add(mdistance m,edistance e){
    mdistance temp;
    int totalCm = m.meter*100 + m.cm;
    int totalInch = e.feet*12 + e.inch;
    totalCm += totalInch*2.54; // convert inch to cm
    temp.meter = totalCm/100;
    temp.cm = totalCm%100;
    return temp;
}
int main(){
    mdistance m;
    edistance e;
    m.input();
    e.input();
    mdistance result = add(m,e);
    cout<<"Md: ";m.display();
    cout<<"Ed: ";e.display();
    cout<<"Sum (in meter-cm): ";
    result.display();
return 0;
}