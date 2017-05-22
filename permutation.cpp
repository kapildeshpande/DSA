#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permute(string s,int a,int b){
	if(a==b) cout<<s<<"\n";
	else {
		for(int i=a;i<=b;i++) {
			swap(s[a],s[i]);
			permute(s,a+1,b);
			swap(s[a],s[i]);
		}
	}
}

int main () {
	string s;
	cin>>s;
	int a = s.size();
	permute(s,0,a-1);
} 
