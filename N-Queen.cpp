//N-queen problem using backtracking
#include<bits/stdc++.h>
using namespace std;

bool queen [11][11] = {0};

bool is_attacked (int i,int j,int n) {
	
	for (int k=0;k<n;k++) {
		if (queen[i][k] || queen[k][j]) return true;
		for (int l=0;l<n;l++) {
			if (queen[k][l]==1 && k+l == i+j || queen[k][l]==1 && k-l == i-j) {
				return true;
			}
		}
	}
	
	return false; 
}

bool N_queen (int x,int n) {
	
	if (x==0) return 1;
	
	for (int i=0;i<n;i++) {	
		for (int j=0;j<n;j++) {
			if (is_attacked(i,j,n)) continue;
			queen[i][j] = 1;
			if (N_queen(x-1,n)) return 1;
			queen[i][j] = 0;
		}
	}
	
	return 0;
	
}

int main () {
	
	int n;
	cin>>n;
	if (N_queen(n,n)) {
		for (int i=0;i<n;i++) {
			for (int j=0;j<n;j++) {
				cout<<queen[i][j]<<" ";
			}
			cout<<"\n";
		}
	}
	else cout<<"Not possible\n";
	
}
