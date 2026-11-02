//udf to udf (source) (m to km)
#include<iostream>
using namespace std;
class kilometers;
class meter{
	int m;
	public:
		meter(){
			m=0;
		}
		void getdata(){
			cin>>m;
		}
	operator kilometers();
};
class kilometers{
	int km;
	public:
		kilometers(){
			km=0;
		}
		kilometers (float k){
			km=k;
		}
		void display(){
			cout<<km;
		}
};
meter::operator kilometers(){
	return kilometers(m/1000);
}
int main(){
	kilometers k;
	meter m;
	m.getdata();
	k=m;
	k.display();
	return 0;
}