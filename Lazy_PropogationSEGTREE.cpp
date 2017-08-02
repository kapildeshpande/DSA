//lazy propogation segment tree sum rannge query
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll lazy [1000001];
ll tree[1000001];

void update (ll node,ll start,ll end,ll l,ll r,ll value) {
	if (lazy[node] != 0) {
		tree[node] += (end - start + 1) * lazy[node];
		if (start != end) {
			lazy[2*node] += lazy[node];
			lazy[2*node+1] += lazy[node];
		}
		lazy[node] = 0;
	}
	if (start > end || start > r || end < l) 
		return;
	if (start >= l && end <= r) {
		tree[node] += (end - start + 1)*value;
		if (start != end) {
			lazy[2*node] += value;
			lazy[2*node+1] += value;
		}
		return;
	}
	ll mid = (start + end)/2;
	update(2*node,start,mid,l,r,value);
	update(2*node+1,mid+1,end,l,r,value);
	tree[node] = tree[2*node] + tree[2*node+1];
}

ll query (ll node,ll start,ll end,ll l,ll r) {
	if (start > end || start > r || end < l)
		return 0;
	if (lazy[node] != 0) {
		tree[node] += (end - start + 1) * lazy[node];
		if (start != end) {
			lazy[2*node] += lazy[node];
			lazy[2*node+1] += lazy[node];
		}
		lazy[node] = 0;
	}
	if (start >= l && end <= r)
		return tree[node];
	ll mid = (start + end)/2;
	long long q1 = query(2*node,start,mid,l,r);
	long long q2 = query(2*node+1,mid+1,end,l,r);
	return (q1+q2);
}

int main () {
	ll t;
	cin>>t;
	while (t--) {
		for (ll i=0;i<=1000001;i++) {
			tree[i] = 0;
			lazy[i] = 0;
		}
		ll n,q;
		cin>>n>>q;
		while (q--) {
			long long a,b,c,d;
			cin>>a;
			if (a == 0) {
				cin>>b>>c>>d;
				update(1,1,n,b,c,d);
				// for (int i=1;i<=11;i++) 
					// cout<<tree[i]<<" ";
				// cout<<"\n";
			}
			else if (a == 1) {
				cin>>b>>c;
				cout<<query(1,1,n,b,c)<<"\n";
			}
		}
	}
}