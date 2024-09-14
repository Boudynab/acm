#include <bits/stdc++.h>
using namespace std;
#define abdo ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
struct segmenttree {
    vector<int> tree;
    int sizee = 1;
    int base = 0;
    // Merge function to combine two segment values
    int merge(int a, int b) {
        return a + b;
    }
    // Build the segment tree, initializing it with the correct size
    void build(int n) {
        while (sizee < n) {
            sizee <<= 1;
        }
        tree = vector<int>(2 * sizee, base); // Initialize with base value
    }
    void update(int idx, int value, int x, int lx, int rx) {
        if (lx == rx) { 
            tree[x] = value;
            return;
        }
        int mid = (lx + rx) / 2;
        if (idx <= mid) {
            update(idx, value,2*x,lx,mid);
        } else {
            update(idx, value,2*x+1,mid+1,rx); 
        }
        tree[x]=merge(tree[2*x],tree[2*x+1]); // Recalculate parent node
    }
    void update(int idx, int value) {
        update(idx, value, 1, 0, sizee - 1); // Call with root node
    }
    int query(int l, int r, int x, int lx, int rx) {
        if (lx > r || rx < l) { // Completely out of range
            return base;
        }
        if (lx >= l && rx <= r) { // Fully inside range
            return tree[x];
        }
        int mid = (lx + rx) / 2;
        int left = query(l,r,2*x,lx,mid); // Query left child
        int right = query(l,r,2*x+1,mid+1,rx); // Query right child
        return merge(left, right); // Combine results
    }
    int query(int l, int r) {
        return query(l,r,1,0,sizee-1); // Call with root node
    }
   void printTree(){
        for(int i = 1; i < 2*sizee; i++){
            cout << tree[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    abdo;
    int n, q;
    cin >> n >> q;
    segmenttree segtree;
    segtree.build(n); 
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        segtree.update(i, x); 
    }
     segtree.printTree();  
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int idx, val;
            cin >> idx >> val;
            segtree.update(idx, val);
        } else {
            int l, r;
            cin >> l >> r;
            r--;  
            cout << segtree.query(l, r) << endl;
        }
    }
}
