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

node* insert (node *root,int data) {
	if (root==NULL) {
		root = getnode(data);
	}
	else if (root->info >= data) {
		root->left = insert(root->left,data);
	}
	else {
		root->right = insert(root->right,data);
	}
	return root;
}

bool search (node *root,int data) {
	if (root == NULL) {
		return false;
	}
	else if (root->info == data) {
		return true;
	}
	else if (root->info >= data) {
		return search (root->left,data);
	}
	else {
		return search (root->right,data);
	} 
}

int find_min (node *root) {
	if (root->left == NULL) {
		return root->info;
	}
	else {
		find_min(root->left);
	}
}

int find_max (node *root) {
	if (root->right == NULL) {
		return root->info;
	}
	else {
		find_max (root->right);
	}
}

int height (node* root) {
	if (root == NULL)  {
		return -1;
	}
	return max( height(root->left),height(root->right) ) + 1;
}

void bfs(node* root) {
	if (root == NULL) {
		return;
	}
	queue <node*> q;
	q.push(root);
	while (!q.empty()) {
		node *current = q.front();
		cout<<current->info<<" ";
		q.pop();
		if (current->left != NULL) {
			q.push(current->left);
		}
		if (current->right != NULL) {
			q.push(current->right);
		}
	}
}

int main () {
	int n,n1,a,k;
	cin>>n;
	n1 = n;
	node *root = NULL;
	while (n--) {
		cin>>a;
		root = insert(root,a);
	}
	//while (n1--) {
	//	cin>>k;
	//	cout<<search(root,k)<<"\n";
	//}
	cout<<find_min(root)<<"\n";
	cout<<find_max(root)<<"\n";
	cout<<height(root)<<"\n";
	bfs(root);
}
