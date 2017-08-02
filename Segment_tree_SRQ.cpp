//sum range query segment tree
#include<bits/stdc++.h>
using namespace std;

int tree[1000001],a[100001];

void built_tree (int node,int start,int end) {
	if (start == end) {
		tree[node] = a[start];
	}
	else {
		int mid = (start + end)/2;
		built_tree (2*node,start,mid);
		built_tree (2*node+1,mid + 1,end);
		tree[node] = tree[2*node] + tree[2*node+1];
	}
}

void update (int node,int start,int end,int index,int val) {
	if (start == end) {
		tree[node] = val;
		a[index] = val;
	}
	else {
		int mid = (start + end)/2;
		if (start <= index && index <= mid) {
			//left
			update(2*node,start,mid,index,val);
		}
		else if (mid+1 <= index && index <= end) {
			//right
			update(2*node+1,mid+1,end,index,val);
		}
		tree[node] = tree[2*node] + tree[2*node+1];
	}
}

int query (int node,int start,int end,int l,int r) {
	if (start >= l && r >= end) {
		return tree[node];
	}
	if (end < l || r < start) {
		return 0;
	}
	else {
		int mid = (start + end)/2;
		int q1 = query(2*node,start,mid,l,r);
		int q2 = query(2*node+1,mid+1,end,l,r);
		return (q1+q2);
	}
}

int main () {
	int n;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	built_tree(1,1,n);
	int q;
	cin>>q;
	while (q--) {
		char c;
		int l,r;
		cin>>c>>l>>r;
		if (c == 'Q') cout<<query(1,1,n,l,r)<<"\n";
		else update(1,1,n,l,r);
	}
}