#include <bits/stdc++.h>
using namespace std;
int dp[105][105];
/*int rec(const vector<int>& numbers, int n, int prev) {
    if (n == 0) {
        return 0;
    }
    if (dp[n][prev+1]!=-1) {
        return dp[n][prev+1];
    }
    int c1 = rec(numbers,n-1,prev);
    int c2 = 0;
    if (prev==-1||numbers[n-1]>numbers[prev]) {
        c2 = rec(numbers,n-1,n-1)+1;
    }
    return dp[n][prev+1] =max(c1, c2);
}
*/
int rec(int n,vector<int>const& numbers) {
    vector<int> d(n, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (numbers[j] < numbers[i])
                d[i] = max(d[i], d[j] + 1);
        }
    }
    int ans = d[0];
    for (int i = 1; i < n; i++) {
        ans = max(ans, d[i]);
    }
    return ans;
}
int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << rec(n,numbers)<< endl;
}
