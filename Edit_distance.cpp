//edit distance
#include<iostream>
using namespace std;

int edit_distance (string s,string s1,int m,int n) {
	int a[m+1][n+1];
	for (int i=0;i<=m;i++) {
		for (int j=0;j<=n;j++) {
			if (i==0) a[i][j] = j;
			else if (j==0) a[i][j] = i;
			else if (s[i-1] == s1[j-1]) {
				a[i][j] = a[i-1][j-1];
			}
			else {
				a[i][j] = 1 + min(a[i-1][j-1],min(a[i-1][j],a[i][j-1]));
			}
		}
	}
	return a[m][n];
}

int main () {
	string s,s1;
	cin>>s>>s1;
	cout<<edit_distance(s,s1,s.size(),s1.size())<<"\n";
}
