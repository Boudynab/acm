#include <bits/stdc++.h>
using namespace std;
#define abdo ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
const long long N = 200005;
struct node {
    long long sum, prefix_sum, suffix_sum, ans;
    node() : sum(0), prefix_sum(0), suffix_sum(0), ans(0) {}
    node(long long value) { 
        sum = prefix_sum = suffix_sum = ans = value;
    }
};
struct segmenttree {
    vector<node> tree; 
    long long sizee = 1;
    node merge(node a, node b) {
        node res;
        res.sum = a.sum + b.sum;
        res.prefix_sum = max(a.prefix_sum, a.sum + b.prefix_sum);
        res.suffix_sum = max(b.suffix_sum, b.sum + a.suffix_sum);
        res.ans = max({a.ans, b.ans, a.suffix_sum + b.prefix_sum});
        return res;
    }
    void build(long long n) {
        while (sizee < n) sizee <<= 1;  
        tree.assign(2 * sizee, node(0));
    }
    void update(long long idx, long long value, long long x, long long lx, long long rx) {
        if (lx == rx) {  // Leaf node
            tree[x] = node(value);  // Assign new value to the leaf
            return;
        }
        long long mid = (lx+rx)/2;
        if (idx <= mid) {
            update(idx,value,2*x,lx,mid); 
        } else {
            update(idx,value,2*x+1,mid+1,rx);
        }
        tree[x]=merge(tree[2*x],tree[2*x+1]);
    }
    void update(long long idx, long long value) {
        update(idx, value, 1, 0, sizee - 1);
    }
    node query(long long l, long long r, long long x, long long lx, long long rx) {
        if (lx > r || rx < l) {  // Completely out of range
            return node(0);  // Return the base case
        }
        if (lx >= l && rx <= r) {  // Fully inside range
            return tree[x];
        }
        long long mid = (lx + rx) / 2;
        node left = query(l, r, 2 * x, lx, mid);  
        node right = query(l, r, 2 * x + 1, mid + 1, rx);  
        return merge(left, right);  
    }
    node query(long long l, long long r) {
        return query(l, r, 1, 0, sizee - 1);  
    }
    void printTree() {
        for (long long i = 1; i < 2 * sizee; i++) {
            cout << tree[i].ans << " ";
        }
        cout << endl;
    }
};
int main() {
    abdo;
    long long n, q;
    cin >> n >> q;
    segmenttree segtree;
    segtree.build(n);
    for (long long i = 0; i < n; i++) {
        long long x;
        cin >> x;
        segtree.update(i, x);  
    }
    while (q--) {
        long long type=1;
        //cin >> type;
        if (type == 1) {  
            long long idx, val;
            cin >> idx >> val;
            idx--; 
            segtree.update(idx, val);
            long long ans=segtree.query(0,n-1).ans;
            if(ans>=0){
                cout << ans << endl;
            }
            else{
                cout << 0 << endl;
            }
        } 
    }
}
