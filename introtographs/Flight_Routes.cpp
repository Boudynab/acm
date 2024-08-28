#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
const int INF = LLONG_MAX;
struct Edge{
    int to,weight;
};
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<Edge>>graph(n+1);
    for(int i=0; i<m;++i){
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<vector<int>>dist(n+1);
    pq.push({0, 1});
    while(!pq.empty()){
        int cost=pq.top().first;
        int city=pq.top().second;
        pq.pop();
        if(dist[city].size() >= k){
            continue;
         }
         dist[city].push_back(cost);
         if(dist[city].size()>=k&&city==n){
            break;
         }
         for(auto &e : graph[city]){
            int nextcity=e.to;
            int nextcost=cost+e.weight;
            if(dist[nextcity].size()<k){
                pq.push({nextcost, nextcity});
            }
         }
    }
    for (int i = 0; i < k; i++) {
        cout << dist[n][i] << " ";
    }
}

