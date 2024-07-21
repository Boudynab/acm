#include <bits/stdc++.h>
using namespace std;
void generateSubsets(int n, int current, vector<int>& subset) {
    if (current > n) {
        if (!subset.empty()) {
            for (int i = 0; i < subset.size(); ++i) {
                cout << subset[i];
            }
            cout << endl;
        }
        return;
    }
    subset.push_back(current);
    generateSubsets(n, current + 1, subset);
    subset.pop_back();
    generateSubsets(n, current + 1, subset);
}
int main() {
    int n;
    cin >> n;
    vector<int> subset;
    generateSubsets(n, 1, subset);
    return 0;
}
