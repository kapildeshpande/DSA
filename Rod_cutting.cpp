//dp rod cutting
#include <iostream>
#include<algorithm>
using namespace std;
//formula
//c(i) = max(v(k) + c(i-k)) where k=1 to i

int rod_cutting (int len,int price[]) {
	int dp [len+1],maxi = 0;
	dp[0] = 0;
	for (int i=1;i<len+1;i++) {
		int m = 0;
		for (int j=1;j<=i;j++) {
			m = max(m,price[j] + dp[i-j]);
		}
		dp[i] = m;
		maxi = max(maxi,dp[i]);
	}
	return maxi;
}

int main () {
	int len;
	cin>>len;
	int price[len+1];
	for (int i=1;i<len+1;i++) cin>>price[i];
	cout<<rod_cutting(len,price)<<"\n";
}
