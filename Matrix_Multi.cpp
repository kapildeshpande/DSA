#include<iostream>
using namespace std;

int main () {
	int row,column,row1,column1;
	
	cout<<"Enter no. row and coloumn of 1st matrix ";
	
	cin>>row>>column;
	int a[row][column];
	
	cout<<"Enter matrix\n";
	
	for(int i=0;i<row;i++) {
		for(int j=0;j<column;j++)
		cin>>a[i][j];
	}
	
	cout<<"Enter no. row and coloumn of 2nd matrix ";
	
	cin>>row1>>column1;
	int b[row1][column1];
	
	cout<<"Enter matrix\n";
	
	for(int i=0;i<row1;i++) {
		for(int j=0;j<column1;j++)
		cin>>b[i][j];
	}
	
	int sum=0,c[row][column1];
	
	for(int i=0;i<row;i++) {
		sum=0;
		for(int j=0;j<column1;j++) {
			for(int k=0,l=0;k<column,l<row1;k++,l++) {
				sum+=a[i][k] * b[l][j];
			}
			c[i][j]=sum;
			sum=0;
		}
	}
	
	cout<<"After multiplication\n";
	
	for(int i=0;i<row;i++) {
		for(int j=0;j<column1;j++)
		cout<<c[i][j]<<" ";
		cout<<"\n";
	}
}
