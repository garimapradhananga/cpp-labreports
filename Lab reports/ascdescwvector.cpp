#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	vector<int> v={6,3,4,2,1};
	 sort(v.begin(),v.end());
	for (int x:v){
		cout<<x<<" "<<endl;
	}
	sort(v.rbegin(),v.rend());
	for (int x:v){
		cout<<x<<" "<<endl;
	}
	return 0;
}