#include<bits/stdc++.h>
using namespace std;

int a[1001],size[1001];

void initialise (int n) {
	for (int i=0;i<n;i++) {
		a[i] = i;
		size[i] = 1;
	}
}

int root (int i) {
	while (a[i] != i) {
		i = a[i];
	}
	return i;
}

void unioon (int k,int b) {
	int root_a = root(k);
	int root_b = root(b);
	if (size[root_a] < size[root_b]) {
		a[ root_a ] = a[ root_b ];
		size[root_b] += size[root_a];
	}
	else {
		a[root_b] = a[root_a];
		size[root_a] += size[root_b];
	}
}

void find (int n) {
	int arr[n] = {0};
	for (int i=0;i<n;i++) {
		arr[root(a[i])]++;
	}
	sort(arr,arr+n);
	for (int i=0;i<n;i++) {
		if (arr[i] != 0) cout<<arr[i]<<" ";
	}
	cout<<"\n";
}

int main () {
	int n,m;
	cin>>n>>m;
	initialise(n);
	while (m--) {
		int x,b;
		cin>>x>>b;
		unioon(x-1,b-1);
		find(n);
	}
}
