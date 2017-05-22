#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main () {
	ll n,q,sum=0;
	cin>>n>>q;
	vector<pair<ll,ll> > vi;
	vector <ll> a;
	for (int i=0;i<n;i++) {
		ll b,c;
		cin>>b>>c;
		vi.push_back(make_pair(b,c));
		sum += abs(b-c) + 1;
		a.push_back(sum);
	}
	//for (int i=0;i<n;i++) cout<<a[i]<<" ";
	while(q--) {
		ll d;
		cin>>d;
		auto it = lower_bound(a.begin(),a.end(),d) - a.begin();
		//cout<<it1<<" "<<*it<<"\n";
		//cout<<a[it]<<"\n";
		cout<<vi[it].second - (a[it] - d)<<"\n";
	}
}
