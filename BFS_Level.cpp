#include <bits/stdc++.h>
using namespace std;

vector < pair <int,int> > adj[101];
bool visited[101] = {0};
int dist[101] = {0};

void bfs(int s) {
	queue <int> q;
	visited [s] = 1;
	q.push(s);
	while(!q.empty()) {
		s = q.front();
		q.pop();
		for (int i=0;i<adj[s].size();i++){
			int k = adj[s][i].first;
			if(visited[k]==0) {
				q.push(k);
		 	    visited[k] = 1;
		 	    dist[k] = dist[s] + adj[s][i].second;
			}
		}
	}
}

int main () {
	int n,m;
	cin>>n>>m;
	while (m--) {
		int a,b,c;
		cin>>a>>b>>c;
		adj[a].push_back({b,c});
		adj[b].push_back({a,c});
	}
	bfs(0);
	for (int i=0;i<n;i++) cout<<dist[i]<<" ";
}
