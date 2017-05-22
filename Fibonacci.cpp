#include<iostream>
using namespace std;

int fibo[1000] = {0};

int fib (int n) {
	if (n<=1) return n;
	if (fibo[n] == 0) 
	fibo[n] = fib(n-1) + fib(n-2);
	return fibo[n];
}

int main () {
	int n;
	cin>>n;
	fibo[0] = 0;
	fibo[1] = 1;
	cout<<fib(n)<<"\n";
}
