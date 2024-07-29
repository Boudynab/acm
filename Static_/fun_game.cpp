#include <iostream>
#include <vector>
#include <string>
using namespace std;
void solve() {
    int testCases;
    cin >> testCases;
    while (testCases--) {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        int count_s1 = 0, count_s0 = 0, count_t1 = 0, count_t0 = 0;
        bool possible = true;
        for (int i=0;i<n;i++) {
            if (s[i] == '1') count_s1++;
            else count_s0++;
            if (t[i] == '1') count_t1++;
            else count_t0++;  
            if(s[i]!=t[i]&&(s[i]=='1')){
                if(count_s1>0){
                    possible=true;
                }
                else{
                    possible=false;
                    break;
                }
            }
           else if(s[i]!=t[i]&&(s[i]=='0')){
            if(count_s1>0){
                possible=true;
            }
            else{
                possible=false;
                break;
            }
           }
        }
        if (possible) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
int main() {
    solve();
    return 0;
}
