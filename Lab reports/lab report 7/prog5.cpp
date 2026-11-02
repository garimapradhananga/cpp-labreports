#include<iostream>
using namespace std;
template <class T>
class Array{
    T arr[100];
    int n;
    public:
    void input(){
        cout<<"enter the number of elements: ";
        cin>>n;
        cout<<"enter the elements: ";
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
    }
    void display(){
        cout<<"the elements are: ";
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    void maximum(){
        T max=arr[0];
        for(int i=1;i<n;i++){
            if(arr[i]>max){
                max=arr[i];
            }
        }
        cout<<"the maximum element is: "<<max<<endl;
    }
    void minimum(){
        T min=arr[0];
        for (int i=0;i<n;i++){
            if (arr[i]<min){
                min=arr[i];
            }
        }
        cout<<"the minimum element is: "<<min<<endl;
    }
};
int main(){
    Array <int> a;
    a.input();
    a.display();
    a.maximum();
    a.minimum();
    return 0;
}