//dynamic constructor helps in initializing and storing the memory for the variable dynamically
#include<iostream>
using namespace std;
class number{
	int *p;
	public:
		number(int n){
			p=new int;
			*p=n;
		}
		void show(){
			cout<<*p;
		}
};
int main(){
	number num(10);
	num.show();
	return 0;
}