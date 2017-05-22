//longest increasing subsequence
#include<iostream>
using namespace std;

int main () {
	int n,m=0;
	cin>>n;
	int a[n],lis[n];
	for (int i=0;i<n;i++) {
		cin>>a[i];
		lis[i] = 1;
	}
	for (int i=1;i<n;i++) {
		for (int j=0;j<i;j++) {
			if (a[j] < a[i]) {
				lis[i] = max(lis[i],lis[j]+1);
				m = max(m,lis[i]);
			}
		}
	}
	//for (int i=0;i<n;i++) cout<<lis[i]<<" ";
	cout<<m<<"\n";
}
