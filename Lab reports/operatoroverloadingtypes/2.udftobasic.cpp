//udf to basic (m to km)
#include<iostream>
using namespace std;
class meters{
	int m;
	public:
		meters(){
			m=0;
		}
		void getdata(){
			cin>>m;
		}
		operator float(){
			return m/1000;
		}
};
int main(){
	float km;
	meters m;
	m.getdata();
	km=m;
	cout<<km;
	return 0;
}