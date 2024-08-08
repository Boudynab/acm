#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        k -= 1;  // Convert to zero-indexed
        int max_wins = 0;

        // Check wins if no swap is made
        int wins = 0;
        for (int i = k; i < n - 1; ++i) {
            if (a[k] > a[i + 1]) {
                wins++;
            } else {
                break;
            }
        }
        max_wins = wins;

        // Check wins for each possible earlier swap position
        for (int i = 0; i < k; ++i) {
            if (a[i] < a[k]) {  // Only consider a swap if your cow can win the first match
                int temp_wins = 0;
                for (int j = i; j < n - 1; ++j) {
                    if (a[k] > a[j + 1]) {
                        temp_wins++;
                    } else {
                        break;
                    }
                }
                max_wins = max(max_wins, temp_wins);
            }
        }

        cout << max_wins << endl;
    }

    return 0;
}
