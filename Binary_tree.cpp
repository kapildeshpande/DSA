//binary search tree
#include<bits/stdc++.h>
using namespace std;

struct node {
	int info;
	node *left;
	node *right;
};

node* getnode (int data) {
	node *newnode = new node();
	newnode->info = data;
	newnode->left = newnode->right = NULL;
	return newnode;
}

/*int ldep(node* root) {
	if (root == NULL) return 0;
	return ldep(root->left) + 0;
}

int rdep(node* root) {
	if (root == NULL) return 0;
	return rdep(root->right) + 0;
}

int height (node* root) {
	if (root == NULL)  {
		return 0;
	}
	int ld = ldep(root->left);
	int rd = rdep(root->right);
	return ld + rd + 2;
}*/
int height (node* root) {
	if (root == NULL)  {
		return -1;
	}
	return max( height(root->left),height(root->right) ) + 1;
}
int Height (node* root) {
	if (root == NULL)  {
		return -1;
	}
	return min( height(root->left),height(root->right) ) + 1;
}
int main () {
	int n,k;
	cin>>n>>k;
	n--;
	node *root = NULL;
	node *curr = NULL;
	root = getnode(k);
	node *rf = root;
	while (n--) {
		string s;
		int a;
		cin>>s>>a;
		curr = getnode(a);
		for (int i=0;i<s.size()-1;i++) {
			if (s[i]=='L') root = root->left;
			else if (s[i]=='R') root = root->right;
		}
		if (s[s.size()-1]=='L') root->left = curr;
		else if (s[s.size()-1]=='R') root->right = curr;
		root = rf;
	}
	cout<<height(root) + Height(root) + 1<<"\n";
}
