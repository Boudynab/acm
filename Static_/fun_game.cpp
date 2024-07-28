#include <iostream>
#include <vector>
using namespace std;
void solve() {
    int testCases;
    cin >> testCases;
    while (testCases--) {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;  
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + (s[i] == '1' ? 1 : 0);
        }  
        bool flag = true;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] != t[i]) {
                if (prefix[i + 1] % 2 != 0) {
                    flag = false;
                    break;
                }
                for (int j = 0; j <= i; ++j) {
                    s[j] = (s[j] == '0' ? '1' : '0');
                }
            }
        } 
        cout << (flag ? "Yes" : "No") << "\n";
    }
}
int main() {
    solve();
    return 0;
}
