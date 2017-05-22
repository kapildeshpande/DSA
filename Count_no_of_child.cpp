//count no. of childrens of tree
#include<bits/stdc++.h>
using namespace std;

vector <int> adj[101];
int child[101] = {0};
bool visited[101] = {0};

int dfs(int s) {
    visited[s] = true;
    for(int i=0;i<adj[s].size();++i)    {
        if(visited[adj[s][i]] == false) {
            child[s]++;
            child [s] += dfs(adj[s][i]);
		}
    }
    return child[s];
}

int main () {
	int n,m;
	cin>>n>>m;
	while (m--) {
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1);
	cout<<"\n";
	for (int i=1;i<=n;i++) cout<<child[i]<<" ";
}
