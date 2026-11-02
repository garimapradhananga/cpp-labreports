#include<iostream>
using namespace std;
template <class t, int size>
class array{
	t a[size];
	public :
		int i;
		array(t value[size]){
			for (i=0;i<size;i++){
				a[i]=value[i];
			}
		}
		void show(){
			for (i=0;i<size;i++){
				cout<<a[i]<<endl;
			}
		}
};
int main(){
	int value[5]={0,1,2,3,4};
	array<int,5>a1(value);
	a1.show();
	return 0;
}