#include <bits/stdc++.h>
#define abdo ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
using namespace std;
const int N=2e5+5;
const int M=25; 
ll sparse[N][M];       
void buildSparseTable(int n, int array[N]) {
    for (int i = 0; i < n; i++) {
        sparse[i][0]=array[i];  // Initialize the base case
    }
    for (int j=1;(1<<j)<=n;j++) {  // j starts from 1 (since 2^0 is already initialized)
        for (int i=0;(i+(1<<j))<=n;i++){  // Ensure we don't go out of bounds
            sparse[i][j]=sparse[i][j-1]^sparse[i+(1<<(j-1))][j-1];// XOR of two intervals
        }
    }
}
ll query(ll l, ll r) {
    ll res = 0;
    for (int j=M-1;j>=0;j--) {
        if ((1<<j)<=(r-l+1)) {  // Check if we can take a block of size 2^j
            res^=sparse[l][j];  // XOR the result
            l+=(1 << j);  // Move l forward by 2^j
        }
    }
    return res;
}
int main() {
    abdo;
    int n, q;
    cin >> n >> q;  
    int array[N];
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    buildSparseTable(n, array); 
    while (q--) {
        ll l, r;
        cin >> l >> r;
        l--; 
        r--;  
        cout << query(l, r) << endl;
    } 
    return 0;
}
