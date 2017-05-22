//binary search program
#include<iostream>
using namespace std;

//Sample input
//position 0  1  2  3  4  5  6  7   8   9
//input    12 13 24 35 43 61 79 91 110 112
//First requirement is array must be sorted

int m,a[50],x;

int bs(int f,int l) {	
    if (f > l) return -1;
    else{
    m = (l+f)/2;
    if(x == a[m]){
    cout<<m;	
	return 0;
    }
    if(x<a[m]) return bs(f,m-1);
    if(x>a[m]) return bs(m+1,l);
  }
}

int main () {
	int f,l,size;
	cin>>size;
for(int i = 0; i<size;i++) cin>>a[i];
  f =0;
  l = size -1;
  cin>>x;
  bs(f,l);
  	
}
