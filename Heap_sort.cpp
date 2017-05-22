#include<iostream>
using namespace std;

int a[1000],n;

void heapify (int i,int n) {
	int left = 2*i;
	int right = 2*i + 1;
	int largest = i;
	if (left <= n && a[left] > a[i]) largest = left;
	if (right <= n && a[right] > a[largest]) largest = right;
	if (largest !=i) {
		swap (a[i],a[largest]);
		heapify(largest,n);
	}
}

void builtheap () {
	for (int i=n/2;i>=1;i--) {
		heapify(i,n);
	}
}

void heapsort () {
	builtheap();
	int m = n;
	while (m >= 2) {
		swap (a[1],a[m]);
		m--;
		heapify(1,m);
	}
}

int main () {
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	heapsort();
	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
}
