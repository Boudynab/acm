#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> prices(n);
    for(int i = 0; i < n; i++){
        cin >> prices[i];
    }
    sort(prices.begin(), prices.end());
    int q;
    cin >> q;
    vector<int>ans;
    while(q--){
        int m;
        cin >> m;
        int cnt = upper_bound(prices.begin(), prices.end(), m) - prices.begin();
        ans.push_back(cnt);
    }
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }
    return 0;
}
