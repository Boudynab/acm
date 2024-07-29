#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void generateBitPatterns(int n, int k, vector<string>& patterns) {
    string bitPattern = string(k, '1') + string(n - k, '0');
    do {
        patterns.push_back(bitPattern);
    } while (prev_permutation(bitPattern.begin(), bitPattern.end()));
}

int main() {
    int T;
    cin >> T;   
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<string> patterns;
        generateBitPatterns(n, k, patterns);
        cout << "The bit patterns are" << endl;
        for (const string& pattern : patterns) {
            cout << pattern << endl;
        }
        if (T > 0) cout << endl;
    }
    return 0;
}
