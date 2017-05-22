#include<iostream>
#include<iomanip>
using namespace std;

int main () {
	int t;
	cin>>t;
	while(t!=0) {
    int n,i;
    cin >> n;
    long double r=1;
    for(i=n;i>0;i--) {
        r = r*i;       
    }
  
    cout<<fixed<<setprecision(0)<<r;
    return 0;
}

 	t--;
}
