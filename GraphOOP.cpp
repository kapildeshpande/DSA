//bfs algorithm
#include<bits/stdc++.h>
using namespace std;

class graph {
	int v;
	vector <int> adj[100001];
	public:
		graph(int vertex) {
			v = vertex;
		}
		void addedge (int v,int w);
		void display_list ();
		void BFS (int s);
		void DFS (int s);
};

void graph::addedge (int v,int w) {
	adj[v].push_back(w);
}

void graph::display_list () {
	for(int i=1;i<=v;i++) {
		int j=0;
		cout<<i<<" -> ";
		while(j<adj[i].size()) 
		cout<<adj[i][j++]<<" ";
		cout<<"\n";
	}
}

void graph::BFS(int s) {
	bool visited[v] = {0};
	queue <int> q;
	visited [s] = 1;
	q.push(s);
	while(!q.empty()) {
		s = q.front();
		cout<<s<<" ";
		q.pop();
		int j=0;
		while(j<adj[s].size()) {
			int k = adj[s][j++];
			if(visited[k]==0) {
				q.push(k);
		 	    visited[k] = 1;
			}
		}
	}
}

void graph::DFS(int s) {
	bool visited[v] = {0};
	stack <int> st;
	visited [s] = 1;
	st.push(s);
	while(!st.empty()) {
		s = st.top();
		cout<<s<<" ";
		st.pop();
		int j=0;
		while(j<adj[s].size()) {
			int k = adj[s][j++];
			if(visited[k]==0) {
				st.push(k);
		 	    visited[k] = 1;
			}
		}
	}
}


int main () {
	int vertices;
	cout<<"Enter no. of vertices \n";
	cin>>vertices;
	graph g(vertices);
	for(int i=1;i<=vertices;i++) {
		int j;
		cout<<"Enter all edges conected to vertex "<<i<<"\n";		
		cout<<"Press -1 to quit\n";
		while(1) {
			cin>>j;
			if(j==-1) break;
		    g.addedge(i,j);
		}
	}
	g.display_list();
	cout<<"Breadth first traversal \n";
	//g.BFS(1);
	for (int i=1;i<=vertices;i++) {
		g.BFS(i);
		cout<<"\n";
	}
	cout<<"\nDepth first traversal \n";
	g.DFS(1);
}
