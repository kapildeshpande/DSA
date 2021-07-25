#include<iostream>
using namespace std;
typedef long long ll;

ll modExpo(ll a,ll b,ll m) {
	if (b == 0)
		return 1;
	if (b == 1)
		return a%m;
	
	ll pow = modExpo(a,b/2,m);
	if (b % 2 == 1)
		return (a%m * pow%m * pow%m) % m;
	return (pow%m * pow%m) % m;
}

ll d, x, y;

void extendedEuclid(ll A, ll B) {
    if(B == 0) {
        d = A;
        x = 1;
        y = 0;
    }
    else {
        extendedEuclid(B, A%B);
        ll temp = x;
        x = y;
        y = temp - (A/B)*y;
    }
}

ll modInverse(ll A, ll M) {
    extendedEuclid(A,M);
    return (x%M+M)%M;    //x may be negative
}

int main () {
	ll a,b,c,m;
	cin>>a>>b>>c>>m;
	ll inv_c = modInverse(c,m);
	ll pow = modExpo(a,b,m);
	pow = (pow*inv_c)%m;
	cout<<pow;
}
