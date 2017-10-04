/*
	Given a dictionary of words and an input string,find the longest
	 prefix of the string which is also a word in dictionary.
*/
#include <bits/stdc++.h>
using namespace std;

struct node {
	node *child[26];
	bool isLeaf;
};

node* getnode () {
	node *Nnode = new node;
	for (int i=0;i<26;i++)
		Nnode->child[i] = NULL;
	Nnode->isLeaf = 0;
	return Nnode;
}

void insert (node *head,string s) {
	for (int i=0;i<s.size();i++) {
		if (head->child[s[i] - 'a'] == NULL) {
			head->child[s[i] - 'a'] = getnode();
		}
		head = head->child[s[i] - 'a'];
	}
	head->isLeaf = 1;
}

string prefix (node *head,string s) {
	int len = 0,m = 0;
	for (int i=0;i<s.size();i++) {
		if (head->child[s[i] - 'a'] == NULL) 
			break;
		len++;
		head = head->child[s[i] - 'a'];
		if (head->isLeaf == 1)
			m = len;
	}
	return s.substr(0,m);
}

int main () {
	node *head = getnode();
	int n,m;
	cout<<"Enter number of words in dictrionary\n";
	cin>>n;
	for (int i=0;i<n;i++) {
		string s;
		cin>>s;
		insert(head,s);
	}
	cout<<"Enter number of string to be search\n";
	cin>>m;
	while (m--) {
		string s;
		cin>>s;
		cout<<prefix(head,s)<<"\n";
	}
}