#include <bits/stdc++.h>
using namespace std;
#define abdo ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
const long long N = 200005;
struct segmenttree {
    vector<long long> tree; 
    long long sizee = 1;
    long long base = LLONG_MAX; 
    long long merge(long long a, long long b) {
        return min(a, b);
    }
    void build(long long n) {
        while (sizee < n) {
            sizee <<= 1;  
        }
        tree.assign(2 * sizee, base); 
    }
    void update(long long idx, long long value, long long x, long long lx, long long rx) {
        if (lx == rx) { 
            tree[x] = value;
            return;
        }
        long long mid = (lx + rx) / 2;
        if (idx <= mid) {
            update(idx, value, 2 * x, lx, mid); 
        } else {
            update(idx, value, 2 * x + 1, mid + 1, rx);
        }
        tree[x] = merge(tree[2 * x], tree[2 * x + 1]); 
    }
    void update(long long idx, long long value) {
        update(idx, value, 1, 0, sizee - 1);
    }
    long long query(long long l, long long r, long long x, long long lx, long long rx) {
        if (lx > r || rx < l) {  // Completely out of range
            return base;
        }
        if (lx >= l && rx <= r) {  // Fully inside range
            return tree[x];
        }
        long long mid = (lx + rx) / 2;
        long long left = query(l, r, 2 * x, lx, mid); 
        long long right = query(l, r, 2 * x + 1, mid + 1, rx);  
        return merge(left, right);  
    }
    long long query(long long l, long long r) {
        return query(l, r, 1, 0, sizee - 1);  
    }
    void printTree() {
        for (long long i = 1; i < 2 * sizee; i++) {
            cout << tree[i] << " ";
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
    // segtree.printTree();
    while (q--) {
        long long type;
        cin >> type;
        if (type == 1) {  
            long long idx, val;
            cin >> idx >> val;
            idx--; 
            segtree.update(idx, val);
        } else if (type == 2) { 
            long long l, r;
            cin >> l >> r;
            l--, r--; 
            cout << segtree.query(l, r) << endl;
        }
    }
    return 0;
}
