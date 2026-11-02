#include<iostream>
#include<vector>
using namespace std;
void display(vector<int>&v){
	int i;
	for (i=0;i<v.size();i++){
		cout<<v[i]<<endl;
	}
}
int main(){
	vector<int>v;
	int i,x;
	for (i=0;i<4;i++){
		cin>>x;
		v.push_back(x);
	}
	cout<<v.size();
	display(v);
	return 0;
}