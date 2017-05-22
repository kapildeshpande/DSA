//insert at beginning
#include<iostream>
using namespace std;

struct node {
	int data;
	node* next;
};
node* head;
void insert (int data) {
	node* nextnode = new node;
	nextnode->data = data;
	nextnode->next = head;
	head=nextnode;
}
void print () {
	node* temp = head;
	while(temp!=NULL) {
		cout<<temp->data<<" ";
		temp = temp->next;
	}
}
int main () {
	head = NULL;
	cout<<"Enter size of linked list";
	int n,data;
	cin>>n;
	cout<<"Enter data in linked list";
	for(int i=1;i<=n;i++) {
		cin>>data;
		insert(data);		
	}
	print();
}
