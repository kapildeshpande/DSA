#include<bits/stdc++.h>
using namespace std;

int main () {
	int n;
	cin>>n;
	priority_queue<int> p;
	for(int i=0;i<n;i++) {
		int x;
		cin>>x;
		p.push(x);
	}
	int t;
	cin>>t;
	while (t--) {
		int a;
		cin>>a;
		if(a==1) {
			int b;
			cin>>b;
			p.push(b);
		}
		else if (a==2) {
			cout<<p.top()<<"\n";
		}
	}
}
