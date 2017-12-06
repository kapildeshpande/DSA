//radix sort
#include <iostream>
using namespace std;

void counting_sort (int a[],int n,int k) {
	int count[10] = {0},output[n];
	for (int i=0;i<n;i++) 
		count[(a[i]/k)%10]++;
	for (int i=1;i<=10;i++)
		count[i] += count[i-1];
	for (int i=n-1;i>=0;i--) {
		output[ count[ (a[i]/k)%10 ]- 1 ] = a[i]; 
		count[ (a[i]/k)%10 ]--;
	}
	for (int i=0;i<n;i++)
		a[i] = output[i];
}

void radix_sort (int a[],int n) {
	int m = INT_MIN;
	for (int i=0;i<n;i++)
		m = max(m,a[i]);
	for (int i=1;m/i > 0;i *= 10)
		counting_sort(a,n,i);
}

int main () {
	int n;
	cin>>n;
	int a[n];
	for (int i=0;i<n;i++) {
		cin>>a[i];
	}
	radix_sort(a,n);
	for (int i=0;i<n;i++)
		cout<<a[i]<<" ";
}
