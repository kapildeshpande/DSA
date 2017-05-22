//knight-tour-problem
#include<iostream>
using namespace std;

int n=8,visit[8][8];

int solve (int i,int j,int count) {
	if (count == 64) return 1;
	
	if (i+1<n&&i+1>=0 && j+2<n&&j+2>=0 &&!visit[i+1][j+2]) {
		visit[i+1][j+2] = count;
		if (solve(i+1,j+2,count+1)==0) {
			visit[i+1][j+2] = 0;
		}
		else return 1;
	}
	if (i+1<n&&i+1>=0 && j-2<n&&j-2>=0 &&!visit[i+1][j-2]) {
		visit[i+1][j-2] = count;
		if(solve(i+1,j-2,count+1)==0) {
			visit[i+1][j-2] = 0;
		}
		else return 1;
	}
	if (i-1<n&&i-1>=0 && j+2<n&&j+2>=0 &&!visit[i-1][j+2]) {
		visit[i-1][j+2] = count;
		if (solve(i-1,j+2,count+1)==0) {
			visit[i-1][j+2] = 0;
		}
		else return 1;
	}
	if (i-1<n&&i-1>=0 && j-2<n&&j-2>=0 &&!visit[i-1][j-2]) {
		visit[i-1][j-2] = count;
		if (solve(i-1,j-2,count+1)==0) {
			visit[i-1][j-2] = 0;
		}
		else return 1;
	}
	if (i+2<n&&i+2>=0 && j+1<n&&j+1>=0 &&!visit[i+2][j+1]) {
		visit[i+2][j+1] = count;
		if (solve(i+2,j+1,count+1)==0) {
			visit[i+2][j+1] = 0;
		}
		else return 1;
	}
	if (i+2<n&&i+2>=0 && j-1<n&&j-1>=0 &&!visit[i+2][j-1]) {
		visit[i+2][j-1] = count;
		if (solve(i+2,j-1,count+1)==0) {
			visit[i+2][j-1] = 0;
		}
		else return 1;
	}
	if (i-2<n&&i-2>=0 && j+1<n&&j+1>=0 &&!visit[i-2][j+1]) {
		visit[i-2][j+1] = count;
		if (solve(i-2,j+1,count+1)==0) {
			visit[i-2][j+1] = 0;
		}
		else return 1;
	}
	if (i-2<n&&i-2>=0 && j-1<n&&j-1>=0 &&!visit[i-2][j-1]) {
		visit[i-2][j-1] = count;
		if (solve(i-2,j-1,count+1)==0) {
			visit[i-2][j-1] = 0;
		}
		else return 1;
	}
	return 0;
}

int main () {
	int count = 1;
	for (int i=0;i<8;i++) {
		for (int j=0;j<8;j++) {
			visit[i][j] = 0;
		}
	}
	solve (0,0,1);
	for (int i=0;i<8;i++) {
		for (int j=0;j<8;j++) {
			cout<<visit[i][j]<<" ";
		}
		cout<<"\n";
	}
}
