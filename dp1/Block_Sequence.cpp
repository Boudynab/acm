#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int minDeletionsToMakeBeautiful(const vector<int>& sequence) {
    int n = sequence.size();
    unordered_map<int, int> count;
    int deletions = 0;
    int i = 0;
    
    while (i < n) {
        if (i >= n) {
            deletions += 1;
            i++;
            continue;
        }
        int blockLength = sequence[i];
        if (i + blockLength > n) {
            deletions += (n - i);
            break;
        }
        bool isValid = true;
        for (int j = 1; j < blockLength; j++) {
            if (sequence[i + j] != sequence[i + 1 + j]) {
                isValid = false;
                break;
            }
        }
        if (isValid) {
            i += blockLength;
        } else {
            deletions += 1;
            i++;
        }
    }
    
    return deletions;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> sequence(n);
        for (int i = 0; i < n; i++) {
            cin >> sequence[i];
        }
        cout << minDeletionsToMakeBeautiful(sequence) << "\n";
    }
    
    return 0;
}
