//dijkstra algorithm
#include<bits/stdc++.h>
using namespace std;

const int c = 1000000000;
vector < pair <int,int> > adj[10001];
bool visited[10001];
int dist[10001];

void initialise (int n) {
	for (int i=0;i<=n;i++) {
		dist[i] = c;
		visited[i] = 0;
	}
}

void dijkstra () {
	dist[1] = 0;
	multiset < pair <int,int> > s;
	s.insert(make_pair(0,1));
	while (!s.empty()) {
		pair <int,int> p = *s.begin();
		s.erase(s.begin());
		int x = p.second;
		if (visited[x]) continue;
		visited[x] = 1;
		for (int i=0;i<adj[x].size();i++) {
			int y = adj[x][i].first;
			if (dist[x] + y < dist[adj[x][i].second]) {
				dist[adj[x][i].second] = dist[x] + y;
				s.insert(make_pair(dist[adj[x][i].second],adj[x][i].second));
			}
		}
	}
}

int main () {
	int n,m;
	cin>>n>>m;
	initialise(n);
	while (m--) {
		int a,b,c;
		cin>>a>>b>>c;
		adj[a].push_back(make_pair(c,b));
		adj[b].push_back(make_pair(c,a));
	}
	dijkstra();
	for (int i=2;i<=n;i++) {
		cout<<dist[i]<<" ";
	}
	cout<<"\n";
}
