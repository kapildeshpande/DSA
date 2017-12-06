//shell sort
#include <iostream>
using namespace std;

void shell_sort (int a[],int n) {
	for (int i = n/2;i>=1;i/=2) {
		for (int j=i;j<n;j++) {
			int temp = a[j],k = j;
			while (k >= i && a[k] < a[k-i]) {
				a[k] = a[k-i];
				k -= i;
			}
			a[k] = temp;
		}
	}
}

int main () {
	int n;
	cin>>n;
	int a[n];
	for (int i=0;i<n;i++)
		cin>>a[i];
	shell_sort(a,n);
	for (int i=0;i<n;i++)
		cout<<a[i]<<" ";
}
