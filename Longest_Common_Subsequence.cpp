//longest common sequence
#include<iostream>
using namespace std;

int lcs (string s,string s1,int m,int n) {
	int a[m+1][n+1];
	for (int i=0;i<=m;i++) {
		for (int j=0;j<=n;j++) {
			if (i == 0 || j == 0) {
				a[i][j] = 0;
			}
			else if (s[i-1] == s1[j-1]) {
				a[i][j] = 1 + a[i-1][j-1];
			}
			else {
				a[i][j] = max(a[i][j-1],a[i-1][j]);
			}		
		}
	}
	return a[m][n];
}

int main () {
	string s,s1;
	cin>>s>>s1;
	cout<<lcs(s,s1,s.size(),s1.size());
}
