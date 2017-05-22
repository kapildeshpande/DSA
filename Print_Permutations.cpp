#include <bits/stdc++.h>
using namespace std;

void permutation (string s,int j) {
	if (j == s.size()) {
		cout<<s<<"\n\n";
		return;
	}
	for (int i=j;i<s.size();i++) {
		swap (s[i],s[j]);
		permutation (s,j+1);
		swap (s[i],s[j]);
	}
}

int main () {
	string s;
	cin>>s;
	permutation(s,0);
}
