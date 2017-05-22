//kruskal algorithm
#include<bits/stdc++.h>
using namespace std;

vector < pair <int,pair<int,int> > > vi;
int a[1000001];

int root (int i) {
	while (i != a[i]) {
		a[i] = a[a[i]];
		i = a[i];
	}
	return i;
}

void unioon (int x,int y) {
	a[root(x)] = a[root(y)];
}

int kruskal (int m) {
	int cost=0,x,y;
	for (int i=0;i<m;i++) {
		x = vi[i].second.first;
		y = vi[i].second.second;
		if (root(x)!=root(y)) {
			cost += vi[i].first;
			unioon(x,y);
		}
	}
	return cost;
}

int main () {
	int n,m;
	cin>>n>>m;
	for (int i=0;i<=n;i++) a[i] = i;
	for (int i=0;i<m;i++) {
		int a,b,c;
		cin>>a>>b>>c;
		vi.push_back(make_pair(c,make_pair(a,b)));
	}
	sort(vi.begin(),vi.end());
	cout<<kruskal(m)<<"\n";
}
