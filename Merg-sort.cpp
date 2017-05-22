#include<iostream>
using namespace std;

void mergesort(int [],int,int);
void merge(int[],int,int,int);

void merge (int a[],int l,int m,int r) {
	int i,j,k;
	int n1=m-l+1;
	int n2=r-m;
	int L[n1],R[n2];
	for(i=0;i<n1;i++) L[i]=a[l+i];
	for(j=0;j<n2;j++) R[j]=a[m+1+j];
	i=0;
	j=0;
	k=0;
	while(i<n1&&j<n2) {
		if(L[i]<=R[j]) {
			a[k]=L[i];
			i++;
		}
		else {
			a[k]=R[j];
			j++;
		}
		k++;
	}
	while(i<n1) {
		a[k]=L[i];
		i++;
		k++;
	}
	while(j<n2) {
		a[k]=R[j];
		j++;
		k++;
	}	
}

void mergesort (int a[],int first,int last) {
	if(first<last) {
	int mid = (first+last)/2;
	mergesort(a, first, mid);
	mergesort(a,mid+1,last);
	merge(a,first,mid,last);
	}
}

void print(int a[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout<<a[i]<<" ";
    cout<<"\n";
}

int main () {
	int n;
	cin>>n;
	int p=n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	mergesort(a,0,n-1);
	cout<<"Sorted array is \n";
	print(a,p);
	return 0;
}
