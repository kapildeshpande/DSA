//Implementation of memory efficient trie ds
#include <bits/stdc++.h>
using namespace std;

struct node {
	map <char,node*> mp;
	bool isLeaf;
};

node* getnode () {
	node *newnode = new node;
	newnode->isLeaf = 0;
	return newnode;
}

void insert (node *curr,string s) {
	for (int i=0;i<s.size();i++) {
		if (curr->mp.count(s[i]) == 0)  {
			curr->mp[s[i]] = getnode();
		}
		curr = curr->mp[s[i]];
	}
	curr->isLeaf = 1;
}

bool search (node* curr,string s) {
	for (int i=0;i<s.size();i++) {
		if (curr->mp.count(s[i]) == 0)
			return 0;
		curr = curr->mp[s[i]];
	}
	return curr->isLeaf;
}

int main () {
	node* head = getnode();
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