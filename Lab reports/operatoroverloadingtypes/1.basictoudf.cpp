//basic to udf (m to km)
#include<iostream>
using namespace std;
class KM{
	int km;
	public:
		KM(){
			km=0;
		}
		KM (float m){
			km=m/1000;
		}
		void show(){
			cout<<km;
		}
};
int main(){
	KM k;
	float meter;
	cin>>meter;
	k=meter;
	k.show();
}