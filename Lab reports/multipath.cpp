#include<iostream>
using namespace std;
class student{
	protected:
		int rn;
		char name[10];
	public:
		void getdata(){
			cout<<"Enter name and roll number: "<<endl;
			cin>>name>>rn;
		}
};
class internal: virtual public student{
	protected:
		int marks1, marks2, marks3;
	public:
		void getinternal(){
			cout<<"Enter marks in internal: "<<endl;
			cin>>marks1>>marks2>>marks3;
		}
		void showinternal(){
			cout<<"Marks in 1: "<<marks1<<" Marks in 2: "<<marks2<<" Marks in 3: "<<marks3<<endl;
		}
};
class external: virtual public student{
	protected:
		int marks4, marks5, marks6;
	public:
		void getexternal(){
			cout<<"Enter marks in external: "<<endl;
			cin>>marks4>>marks5>>marks6;
		}
		void showexternal(){
			cout<<"Marks in 4: "<<marks4<<" Marks in 5: "<<marks5<<" Marks in 6: "<<marks6<<endl;
		}
};
class result: public internal, public external{
	float total,per;
	public:
		void pertotal(){
			total=marks1+marks2+marks3+marks4+marks5+marks6;
			 per=(total/6)*100;
		}
		void show(){
			cout<<"Name: "<<name<<"Roll number: "<<rn<<endl;
			cout<<"Marks in Internal:"<<endl;
			showinternal();
			cout<<"Marks in External:"<<endl;
			showexternal();
			cout<<"Total Marks: "<<total<<endl;
			cout<<"Total Percentage: "<<per<<endl;
		}
};
int main(){
	result r;
	r.getdata();
	r.getinternal();
	r.getexternal();
	r.pertotal();
	r.show();
	return 0;
}