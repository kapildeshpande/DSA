//counting sort
#include <iostream>
using namespace std;

void counting_sort (int a[],int n,int m) {
	int count[m+1] = {0};
	int output[n] = {0};
	for (int i=0;i<n;i++) 
		count[a[i]]++;
	for (int i=1;i<=m;i++) {
		count[i] += count[i-1];
	}
	for (int i=n-1;i>=0;i--) {
		output[count[a[i]]-1] = a[i];
		count[a[i]]--;
	}
	for (int i=0;i<n;i++)
		a[i] = output[i];
}

int main () {
	int n;
	cin>>n;
	int a[n],m = -1000000;
	for (int i=0;i<n;i++) {
		cin>>a[i];
		m = max(m,a[i]);
	}
	counting_sort(a,n,m);
	for (int i=0;i<n;i++)
		cout<<a[i]<<" ";
}
