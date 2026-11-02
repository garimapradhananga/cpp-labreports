#include<iostream>
using namespace std;
const int MAX=20;
template<class t>
class stack{
	int top;
	t arr[MAX];
	public:
		stack (){
			top=-1;
		}
		void push(t x){
			if (top==MAX-1){
				cout<<"stack overflow"<<endl;
			}else{
				arr[++top]=x;
			}
		}
		t pop(){
			if (top==-1){
				cout<<"stack underflow"<<endl;
				return -1;
			}return arr[top--];
		}
		int size(){
			return top+1;
		}
};
int main(){
	stack<int>s;
	s.push(15);
	s.push(17);
	s.push(18);
	cout<<"size="<<s.size();
	cout<<"popped element: "<<s.pop();
	cout<<"2nd popped elememt: "<<s.pop();
}