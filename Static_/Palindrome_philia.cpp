#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.length();
    int count = 0;
    for(int i=0;i<n;i++){
        if(s[i]!=s[n-i-1]){
            count++;
        }
    }
    cout << count/2 << endl;
    return 0;
}
