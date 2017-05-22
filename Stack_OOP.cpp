#include<iostream>
using namespace std;

class stack {
	int m_a[10];
	int m_top;
	public:
		void reset() {
		m_top = -1;}
		void push(int data) {
			if(m_top==9) cout<<"Overflow condition \n";
			else {
				m_a[++m_top]=data;
			}
		}
		void pop() {
			if(m_top<=-1) cout<<"Empty stack \n";
			m_top--;
		}
		void print () {
			for(int i=0;i<=m_top;i++)
			cout<<m_a[i]<<" ";
		}
};

int main () {
	int c,ch1;
	stack s;
	s.reset();
	do{
	cout<<"\nPress 1 to insert in stack and 2 to delete from stack \n";
	cin>>c;
	if(c==1) {
	   cout<<"Enter integer to insert \n";
	   cin>>ch1;
	   s.push(ch1);
	   s.print();}
	else if (c==2) {
	s.pop();
	s.print();}
    } while(c==1||c==2);
}
