// KMP pattern matching algorithm
#include<iostream>
using namespace std;

string s,p;

void preprocess (int size,int pre[]) {
	int len = 0;
	pre[0] = 0;
	int i=1;
	while(i<size) {
		if(s[i]==p[len]) {
			len++;
			pre[i] = len;
			i++;
		}
		else {
			if (len!=0) {
				len = pre[len-1];
			}
			else {
				pre[i] = 0;
				i++;
			}
		}
	}
}

void kmpsearch (int pre[]) {
	int m = s.size();
	int n = p.size();
	int i=0,j=0;
	while(i<m) {
		if(p[j]==s[i]) {
			j++;
			i++;
		}
		if (j==n) {
			cout<<"Pattern found at "<<i-j<<"\n";
			j = pre[j-1];
		}
		else if (i<m && p[j]!=s[i]) {
			
			if (j!=0) j = pre[j-1]; 
			else i++;
		}
	}
}

int main () {
	cout<<"Enter string\n";
	cin>>s;
	cout<<"Enter pattern\n";
	cin>>p;
	int pl = p.size();
	int pre[pl];
	preprocess(pl,pre);
	
	for(int i=0;i<pl;i++) cout<<pre[i]<<" ";
	cout<<"\n";
	
	kmpsearch(pre);
}
