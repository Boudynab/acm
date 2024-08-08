#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
// Function to find the largest power of 2 less than or equal to n
long long largestPowerOfTwoLeq(long long n) {
    if (n < 1) return 0;
    long long power = 1;
    while (power <= n) {
        power <<= 1;
    }
    return power >> 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    vector<long long> results(t);
    for (int i = 0; i < t; ++i) {
        long long n;
        cin >> n;
        results[i] = largestPowerOfTwoLeq(n);
    }
    for (const auto& result : results) {
        cout << result << '\n';
    }
    return 0;
}
