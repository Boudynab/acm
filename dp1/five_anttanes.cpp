#include <bits/stdc++.h>
using namespace std;
int main(){
    int a, b, c, d, e, k;
    cin >> a >> b >> c >> d >> e >> k;
    vector<int> antennas = {a, b, c, d, e};
    for(int i = 0; i < 5; i++){
        for(int j = i + 1; j < 5; j++){
            if(antennas[j] - antennas[i] > k){
                cout << ":(";
                return 0; 
            }
        }
    }
    cout << "Yay!";
    return 0;
}
