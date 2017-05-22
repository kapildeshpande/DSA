#include<iostream>
using namespace std;
int a[50], temp,n;
void build_heap ();
void heapify (int i, int m);

void heapsort () {      
    build_heap();
	int m=n;
	while (m>=2)
	{
		temp=a[1];
		a[1]=a[m];
		a[m]=temp;
		cout<<a[1]<<" "<<a[m]<<"\n";
		m=m-1;
		heapify (1,m);
	}   
}

void build_heap () {  
   
    for ( int i=n/2; i>=1; i--) {
	    cout<<i<<"\n";
        heapify (i,n);
    }
    
}

void heapify (int i, int m) {
	
	int l=2*i;
	int r=(2*i)+1;
	int max=i;
    if (l<=m && a[l]>a[max] ) max=l;
	if (r<=m && a[r]>a[max] ) max=r;
	if (max!=i){	
	    temp=a[i];
		a[i]=a[max];
		a[max]=temp;
		cout<<a[i]<<" "<<a[max]<<"\n";
		heapify (max,m);
	}

}

int main() {	
	cout<<"Enter the number of elements you want in array: ";
	cin>>n;
	cout<<"Enter the elements:\n";
	for ( int i=1; i<=n; i++ ) cin>>a[i];
	heapsort();
      cout<<"After sorting(Heap sort):- "; 
	for (int i=1; i<=n; i++)	
	cout<<a[i] <<" ";
       return 0;
}
