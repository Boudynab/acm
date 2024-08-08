#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K;
    cin >> N >> K;
    vector<int> candies(N);
    for (int i = 0; i < N; ++i) {
        cin >> candies[i];
    }
    unordered_map<int, int> color_count;
    int distinct_colors = 0;
    int maxDistinct = 0;
    for (int i = 0; i < K; ++i) {
        if (color_count[candies[i]] == 0) {
            distinct_colors++;
        }
        color_count[candies[i]]++;
    }
    maxDistinct = distinct_colors;
    // Slide the window from position 1 to N-K
    for (int i = K; i < N; ++i) {
        // Remove the element that is sliding out of the window
        int old_color = candies[i - K];
        if (color_count[old_color] == 1) {
            distinct_colors--;
        }
        color_count[old_color]--;
        // Add the new element that is sliding into the window
        int new_color = candies[i];
        if (color_count[new_color] == 0) {
            distinct_colors++;
        }
        color_count[new_color]++;
        maxDistinct = max(maxDistinct, distinct_colors);
    }
    cout << maxDistinct << '\n';
    return 0;
}
