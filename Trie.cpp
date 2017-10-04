#include<bits/stdc++.h>
using namespace std;

struct node {
	node *child[26];
	bool isleaf;
};

node* newnode () {
	node *Nnode = new node;
	Nnode->isleaf = 0;
	for (int i=0;i<26;i++)
		Nnode->child[i] = NULL;
	return Nnode;
}

void insert (node*& head,string s) {
	node* curr = head;
	for (int i=0;i<s.size();i++) {
		if (curr->child[s[i] - 'a'] == NULL)
			curr->child[s[i] - 'a'] = newnode();
		curr = curr->child[s[i] - 'a'];
	}
	curr->isleaf = 1;
}

bool search (node*& head,string s) {
	node *curr = head;
	for (int i=0;i<s.size();i++) {
		curr = curr->child[s[i] - 'a'];
		if (curr == NULL) 
			return 0;
	}
	return curr->isleaf;
}

int main () {
	node* head = newnode();
	int n;
	cout<<"Enter number of words\n";
	cin>>n;
	cout<<"Now enter words\n";
	while (n--) {
		string s;
		cin>>s;
		insert(head,s);
	}
	cout<<"Enter string to search\n";
	string s;
	cin>>s;
	cout<<search(head,s)<<"\n";
}