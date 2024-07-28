#include <bits/stdc++.h>
#define ll long long int
using namespace std;
vector<ll> a, b;
ll price(ll k, ll n) {
    for (ll i = 0; i < n; i++) {
        b[i] = a[i] + (i + 1) * k;
    }
    sort(b.begin(), b.end());
    ll p = 0;
    for (ll i = 0; i < k; i++) {
        p += b[i];
    }
    return p;
}
int main() {
    ll n, m;
    cin >> n >> m;
    a.resize(n);
    b.resize(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll high = n, low = 0, ans = 0, cost = 0;
    while (high >= low) {
        ll mid = (low + high) / 2;
        ll k = price(mid, n);
        if (k == m) {
            cout << mid << " " << k << endl;
            return 0;
        }
        if (k > m) {
            high = mid - 1;
        } else {
            low = mid + 1;
            ans = mid;
            cost = k;
        }
    }
    cout << ans << " " << cost << endl;
    return 0;
}
