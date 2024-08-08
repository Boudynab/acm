#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int max_increasing_subarray_length(int n,const vector<int>&a) {
    if (n == 2) {
        return a[0]<a[1]?2:1;
    }
    vector<int>left(n, 1);
    vector<int>right(n, 1);
    for (int i = 1; i < n; ++i) {
        if (a[i]>a[i-1]) {
            left[i]=left[i-1]+1;
        }
    }
    for (int i = n - 2; i >= 0; --i) {
        if (a[i] < a[i + 1]) {
            right[i]=right[i+1]+1;
        }
    }
    int max_length =*max_element(left.begin(),left.end());
    for (int i = 1; i < n - 1; ++i) {
        if (a[i - 1] < a[i + 1]) {
            max_length = max(max_length,left[i-1]+right[i+1]);
        }
    }
    return max_length;
}
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cout << max_increasing_subarray_length(n, a) << endl;
    return 0;
}
