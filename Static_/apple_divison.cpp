#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll solve(int idx,const vector<ll>&arr,ll sum1,ll sum2) {
    if (idx == arr.size()) {
        return abs(sum1 - sum2);
    }
    ll choose = solve(idx + 1, arr, sum1 + arr[idx], sum2);
    ll notChoose = solve(idx + 1, arr, sum1, sum2 + arr[idx]);
    return min(choose, notChoose);
}
int main() {
    int N;
    cin >> N; 
    vector<ll> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    ll ans=solve(0,arr,0,0);
    cout<<ans<<endl;
    return 0;
}