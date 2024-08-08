#include <bits/stdc++.h>
using namespace std;
int rec(int n, vector<int>& heights) {
    vector<int> dp(n + 1, INT_MAX);
    dp[1] = 0; 
    for (int i = 1; i <= n; ++i) {
        if (i + 1 <= n) {
            dp[i + 1] = min(dp[i + 1], dp[i] + abs(heights[i] - heights[i + 1]));
        }
        if (i + 2 <= n) {
            dp[i + 2] = min(dp[i + 2], dp[i] + abs(heights[i] - heights[i + 2]));
        }
    }
    return dp[n];
}
int main() {
    int n;
    cin >> n;
    vector<int> heights(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> heights[i];
    }
    cout << rec(n, heights) << endl;
}
