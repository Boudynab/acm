#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define F first
#define S second
#define pii pair<int, int>
#define vii vector<pii>
const int INF = LLONG_MAX / 2;
#define inf LLONG_MAX/2;
int dist[505][505];
void solve(){  // flyod
    int n,m,q;
    cin >> n >> m >> q;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i==j){
                dist[i][j]=0;
            }
            else{
                dist[i][j]=INF;
            }
    }
}
    for(int i=0;i<m;i++){
        int u,v,w;
        cin >>u>>v>>w;
        dist[u][v]=min(dist[u][v],w);
        dist[v][u]=min(dist[v][u],w);
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    while(q--){
        int u,v;
        cin >> u >> v;
        if(dist[u][v]==INF){
            cout << -1 << "\n";
        }
        else{
            cout << dist[u][v] << "\n";
        }
    }
}
int32_t main() {
    solve();
    return 0;
}