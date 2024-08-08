#include <bits/stdc++.h>
using namespace std;
int minCostToReachEnd(int n, int k, vector<int>& heights) {
    vector<int> dp(n + 1, INT_MAX);
    dp[1] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int jump = 1; jump <= k; ++jump) {
            if (i + jump <= n) {
                dp[i + jump] = min(dp[i + jump], dp[i] + abs(heights[i] - heights[i + jump]));
            }
        }
    }
    return dp[n];
}
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> heights(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> heights[i];
    }
    cout << minCostToReachEnd(n, k, heights) << endl;
}
