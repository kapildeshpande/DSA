#include <bits/stdc++.h>
using namespace std;

void builtST(int node,int start,int end,int a[],int tree[]) {
    if (start == end) tree[node] = a[start];
    else {
        int mid = (start + end)/2;
        builtST(2*node,start,mid,a,tree);
        builtST(2*node+1,mid+1,end,a,tree);
        tree[node] = min(tree[2*node],tree[2*node + 1]);
    }
}

void update (int node,int start,int end,int pos,int val,int tree[],int a[]) {
    if (start == end) {
        tree[node] = val;
        a[pos] = val;
    }
    else {
        int mid = (start + end)/2;
        if (start <= pos && pos <= mid) {
            update(2*node,start,mid,pos,val,tree,a);
        }
        else {
            update(2*node+1,mid+1,end,pos,val,tree,a);
        }
        tree[node] = min(tree[2*node],tree[2*node+1]);
    }
}

int query (int node,int start,int end,int l,int r,int tree[]) {
    if (r < start || l > end) {
        return INT_MAX;
    }
    if (l <= start && r >= end) {
        return tree[node];
    }
    int mid = (start + end)/2;
    return min (query(2*node,start,mid,l,r,tree),query(2*node+1,mid+1,end,l,r,tree));
}

int main() {
    int n,q;
    cin>>n>>q;
    int a[100005],tree[1000005];
    for (int i=1;i<=n;i++) cin>>a[i];
    builtST(1,1,n,a,tree);
    while (q--) {
        char c;
        int l,r;
        cin>>c>>l>>r;
        if (c == 'q') {
            cout<<query(1,1,n,l,r,tree)<<"\n";
        }
        else {
            update(1,1,n,l,r,tree,a);
        }
    }
    
}
