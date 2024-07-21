#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    int l, r;
    cin >> l >> r;
    ll max_xor = 0;
    for (int i = l; i <= r; ++i) {
        for (int j = l; j <= r; ++j) {
            max_xor = max(max_xor, (ll)(i ^ j));
        }
    }
    cout << max_xor << endl;
    return 0;
}
