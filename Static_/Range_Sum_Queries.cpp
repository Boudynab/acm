#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    int N, Q;
    cin >>N>>Q;
    vector<ll> x(N + 1, 0); 
    for (int i=1;i<=N;++i) {
        cin >> x[i];
        x[i]+=x[i-1];
    }
    while (Q--) {
        int a, b;
        cin >>a>>b;
        cout <<x[b]-x[a-1]<<'\n';
    }
    return 0;
}

