#include<iostream>
using namespace std;

struct node{
	int info;
	node *next;
};

node *newnode,*temp,*top=NULL,*bottom=NULL; 

void getnode() {
	newnode = new node;
	cin>>newnode->info;
	newnode->next=NULL;
}

void print () {
	temp = bottom;
	while(temp!=NULL) {
		cout<<temp->info<<" ";
		temp = temp->next;
	}
}

void pop() {
    if(top==NULL) cout<<"NO elememt to pop\n";
    else if(top == bottom) {//only 1 element in stack
    	top=NULL;
    	bottom=NULL;
    	cout<<"Stack is empty now \n";
	}
	else {
		temp = bottom;
		while(temp->next!=top) {
			temp=temp->next;}
			temp->next=NULL;
			top = temp;
		}
	print ();
}

void insert() {
	getnode();
	if(top==NULL) {
		top=newnode;
		bottom=newnode;
	}
	else {
		top->next=newnode;
		top = newnode;
	}
	print();
}

int main () {
	int data,k;
	char a;
	cout<<"Enter 1 to insert and 2 to delete \n";
    do {
    	cout<<"Enter your choice ";
    	cin>>k;
    	if(k==1)
		insert();
		else if (k==2) pop();
		else cout<<"Invalid choice ";
		cout<<"Do you want to continue y/n";
		cin>>a;		
	}while(a=='y');
	print();
}
