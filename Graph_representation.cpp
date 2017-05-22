#include <iostream>
using namespace std;

int main() {
	int n,m,q;
	cin>>n>>m;
	bool a[n][n];
    for(int i=0;i<n;i++) {
    	for(int j=0;j<n;j++) a[i][j] = false;
    }
    while (m--) {
    	int b,c;
    	cin>>b>>c;
    	a[b][c] = true;
    	a[c][b] = true;
    }
    cin>>q;
    while(q--) {
    	int d,e;
    	cin>>d>>e;
    	if(a[d][e] == true) cout<<"YES\n";
    	else cout<<"NO\n";
    }
}

