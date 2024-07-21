#include <bits/stdc++.h>
#define ll long long int
using namespace std;

unsigned int flippingbits(unsigned int n){
    unsigned int mask = 0xFFFFFFFF;
    return (~n)& mask;
}
int main() {
    int q;
    cin >> q;
    vector<unsigned int>results;
    while(q--){
        unsigned int n;
        cin >> n;
        results.push_back(flippingbits(n));
    }
    for(auto result: results){
        cout << result << "\n";
    }
    return 0;
}