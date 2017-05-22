//longest inc subseq nlogn
#include<bits/stdc++.h>
using namespace std;

int main () {
	int n,size=1;
	cin>>n;
	int a[n],lis[n] = {0};
	for (int i=0;i<n;i++) cin>>a[i];
    lis[0] = a[0];
	for (int i=1;i<n;i++) {
		if (a[i] < lis[0]) {
			lis[0] = a[i];
		}
		else if (a[i] > lis[size-1]) {
			lis[size++] = a[i];
		}
		else {
			int k = lower_bound(lis,lis+size,a[i]) - lis;
			lis[k] = a[i];
		}
	}
	cout<<size<<"\n";
}
