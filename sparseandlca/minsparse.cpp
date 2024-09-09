#include <bits/stdc++.h>
#define abdo ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
using namespace std;
const int N = 2e5 + 5;
const int M = 25; 
int sparse[N][M];  
int array[N];
void buildSparseTable(int n,int array[N]) {
    for (int i = 0; i < n; i++) {
        sparse[i][0] = array[i]; 
    }
    for (int j = 1; (1 << j) <= n; j++) { 
        for (int i = 0; (i + (1 << j)) <= n; i++) {
            sparse[i][j]=min(sparse[i][j - 1],sparse[i + (1 << (j - 1))][j - 1]);
        }
    }
}
ll query(int l, int r) {
    ll res = LLONG_MAX;   
    for(int j = M - 1; j >= 0; j--) {
        if((1 << j) <= (r - l + 1)) {
        res=std::min(res,static_cast<ll>(sparse[l][j]));
            l += (1 << j);
        }
    }
    return res;
}
int main() {
    abdo;
    int n;
    cin >> n;  
    int array[N];
    for (int i = 0; i < n; i++) {
        cin >> array[i];  
    }
    int q;
    cin >> q; 
    buildSparseTable(n,array); 
    while (q--) {
        int l, r;
        cin >> l >> r;
        l; 
        r;  
        cout << query(l, r) << endl;
    }
}
