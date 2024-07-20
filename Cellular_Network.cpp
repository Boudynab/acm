#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
	cin >> n >> m;
	int cities[n];
	set<int> towers;
	int tower;
	for (int i = 0; i < n; i++) { 
        cin >> cities[i]; 
    }
	for (int i = 0; i < m; i++) {
		cin >> tower;
		towers.insert(tower);
	}
    int r=0;
    for(int i=0;i<n;i++){
        int dist=2e9+1;
        auto closetower_right=towers.lower_bound(cities[i]);
        if(closetower_right!=towers.end()){
            dist=*closetower_right-cities[i];
        }
        if(closetower_right!=towers.begin()){
            closetower_right--;
            dist=min(dist,cities[i]-*closetower_right);
        }
        r=max(r,dist);
    }
    cout << r << endl;
}
