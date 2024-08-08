#include <iostream>
#include <algorithm> // for min function
using namespace std;

int main() {
    long long n, a, b, c;
    cin >> n >> a >> b >> c;

    int remainder = n % 4;
    long long cost = 0;

    if (remainder == 0) {
        cost = 0;
    } else if (remainder == 1) {
        cost = min({3 * a, a + b, c});
    } else if (remainder == 2) {
        cost = min({2 * a, b, 2 * c});
    } else if (remainder == 3) {
        cost = min({a, b + c, 3 * c});
    }

    cout << cost << endl;

    return 0;
}
