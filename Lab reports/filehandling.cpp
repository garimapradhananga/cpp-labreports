/*wap with a class to represent an employee having data members to represent name, employee id, age and salary. 
add records of 10 employees in a file and display them in a console. also search a specific record of an employee 
using employee id as a key from the user input*/
#include <iostream>
#include<fstream>
using namespace std;
class employee{
	char name[50];
	int empid;
	int age;
	int salary;
	public:
		void getdata(){
			cout<<"enter name, employee id, age and salary: "<<endl;
			cin>>name>>empid>>age>>salary;
		}
		void showdata(){
			cout<<"Employee Information: \n";
			cout<<name<<empid<<age<<salary;
		}
		int search (int e){
			if (e==empid){
				return 1;
			}else{
				return 0;
			}
		}
void showrec();
void getrec();
};
void employee::showrec(){
	employee e;
	int flag=0, r;
	fstream file;
	file.open("employee.txt",ios::binary|ios::out|ios::in);
	cout<<"enter record to search: "<<endl;
	cin>>r;
	do{
		if (e.search(r)){
			e.showdata();
			flag=1;
			break;
		}
	}while (file.read((char*)&e, sizeof(e)));
	if (flag==0){
		cout<<"not found"<<endl;
	}
	file.close();
}
void employee::getrec(){
	employee e;
	char ch;
	fstream file;
	file.open("employee.txt", ios::binary|ios::in|ios::out|ios::app);
	do{
		e.getdata();
		file.write((char *)&e, sizeof(e));
		cout<<"do u want to enter more records? (y/n) "<<endl;
		cin>>ch;
	}while (ch=='y'||ch=='Y');
	file.close();
}
int main(){
	employee e;
	while (1){
		int n;
		cout<<"enter ur choice: "<<endl;
		cout<<"1: search, 2: input, 3:exit"<<endl;
		cin>>n;
		switch(n){
			case 1:
				e.showrec();
				break;
			case 2:
				e.getrec();
				break;
			case 3:
				exit(1);
				break;
			default:
				cout<<"enter choices 1,2 or 3"<<endl;
				break;
		}
	}
	return 0;
}