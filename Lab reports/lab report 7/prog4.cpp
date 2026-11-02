//sum and avg of array
#include<iostream>
using namespace std;
template <class T>
T sum (T arr[], int n){
    T s=0;
    for(int i=0;i<n;i++){
        s+=arr[i];
    }
    return s;
}
template <class T>
T average(T arr[], int n){
    T s=sum(arr,n);
    return s/n;
}
int main(){
    int a[5]={1,2,3,4,5};
    float b[5]={1.1,2.2,3.3,4.4,5.5};
    cout<<"Sum of integer array: "<<sum(a,5)<<endl;
    cout<<"Average of integer array: "<<average(a,5)<<endl;
    cout<<"Sum of float array: "<<sum(b,5)<<endl;
    cout<<"Average of float array: "<<average(b,5)<<endl;
    return 0;
}