/*
	Given a set of string find longest common prefix.
*/
#include <bits/stdc++.h>
using namespace std;

struct node {
	node *child[26];
	bool isLeaf;
};

node *getnode () {
	node *newnode = new node;
	for (int i=0;i<26;i++)
		newnode->child[i] = NULL;
	newnode->isLeaf = 0;
}

void insert (node *curr,string s) {
	for (int i=0;i<s.size();i++) {
		if (curr->child[s[i] - 'a'] == NULL) 
			curr->child[s[i] - 'a'] = getnode();
		curr = curr->child[s[i] - 'a'];
	}
	curr->isLeaf = 1;
}

bool count_child (node *curr) {
	int count = 0;
	for (int i=0;i<26;i++) {
		if (curr->child[i] != NULL)
			count++;
	}
	return (count == 1);
}

string longest_common_prefix (node *curr) {
	string s;
	while (curr->isLeaf == 0 && count_child(curr) == 1) {
		for (int i=0;i<26;i++) {
			if (curr->child[i] != NULL) {
				curr = curr->child[i];
				s += (char) ('a' + i);
				break;
			}
		}
	}
	return s;
}

int main () {
	node *head = getnode();
	int n;
	cout<<"Enter number of words in dictrionary\n";
	cin>>n;
	for (int i=0;i<n;i++) {
		string s;
		cin>>s;
		insert(head,s);
	}
	cout<<"longest common prefix "<<longest_common_prefix(head)<<"\n";
}