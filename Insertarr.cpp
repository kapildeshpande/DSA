//insert element in array
#include<iostream>
using namespace std;

int main () {
	int a[50],num,i,pos;
	for(i = 0; i<=9; i++) cin>>a[i];
	cin>>pos>>num;
	for(i =num; i<=10;i++)
	a[i] = a[i+1];
	a[pos] = num;
	for(i =0; i<=10;i++)
	cout<<a[i]<<" ";
}

