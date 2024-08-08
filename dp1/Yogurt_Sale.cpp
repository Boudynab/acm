#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,a,b;
        cin >> n >> a >> b;
        int min_cost=(n/2)*b+(n%2)*a;
        int ans=min(min_cost,n*a);
        cout << ans << endl;
    }
}