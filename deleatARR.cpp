//delete an element from array 
#include<iostream>
using namespace std;

int main () {
	int i,pos,n;
	cin>>n;
	int a[n];
	for(i = 0; i<n; i++) cin>>a[i];
	cin>>pos;
	for(i = pos;i<n-1;i++)
	a[i] = a[i+1];
	for(i =0; i<n-1;i++)
	cout<<a[i]<<" ";
}

