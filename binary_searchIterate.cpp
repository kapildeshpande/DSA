//iterative binary search
#include<iostream>
#include<algorithm>
using namespace std;

int binarysearch (int a[],int item,int f,int l) {
	int mid=-1;
	while (f<=l) {
		mid = (f+l)/2;
		if (a[mid]==item) return mid;
		if (item < a[mid]) {
			l = mid-1;
		}
		else {
			f = mid + 1;
		}
	}
	return -1;
}

int upperbound (int a[],int item,int f,int l) {
	int mid;
	while (f<=l) {
		mid = (f+l)/2;
		if (a[mid]==item) {
			if (a[mid]==a[mid+1]) {
				f = mid+1;
			}
			else return mid;
		}
		if (item < a[mid]) {
			l = mid-1;
		}
		else {
			f = mid + 1;
		}
	}
	return mid;
}

int lowerbound (int a[],int item,int f,int l) {
	int mid;
	while (f<=l) {
		mid = (f+l)/2;
		if (a[mid]==item) {
			if (a[mid]==a[mid-1]) {
				l = mid-1;
			}
			else return mid;
		}
		if (item < a[mid]) {
			l = mid-1;
		}
		else {
			f = mid + 1;
		}
	}
	return mid;
}

int main () {
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	int item;
	cin>>item;
	int c = binarysearch(a,item,0,n-1);
	int d = upperbound (a,item,0,n-1);
	int e = lowerbound(a,item,0,n-1);
	cout<<c<<" "<<d<<" "<<e<<"\n";
}
