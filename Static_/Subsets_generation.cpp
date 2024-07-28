#include <bits/stdc++.h>
using namespace std;
void generateSubsets(int n, int current, vector<int>& subset, vector<vector<int>>& all_subsets) {
    if (current > n) {
        if (!subset.empty()) {
            all_subsets.push_back(subset);
        }
        return;
    }
    subset.push_back(current);
    generateSubsets(n, current + 1, subset, all_subsets);
    subset.pop_back();
    generateSubsets(n, current + 1, subset, all_subsets);
}
bool compare(const vector<int>& a, const vector<int>&b) {
    if (a.size() != b.size()) {
            return a.size()<b.size();
        }
        return a < b;
}
int main() {
    int n;
    cin >> n;
    vector<int> subset;
    vector<vector<int>> all_subsets;
    generateSubsets(n, 1, subset, all_subsets);
    sort(all_subsets.begin(), all_subsets.end(),compare);
    for (const auto& s : all_subsets) {
        for (int num : s) {
            cout << num;
        }
        cout << endl;
    }
    return 0;
}
