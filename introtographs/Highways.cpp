#include <bits/stdc++.h>
using namespace std;
#define inf LLONG_MAX
#define neg_inf LLONG_MIN
#define int long long
void dijkstra(int n,int start,vector<vector<pair<int,int>>>&graph,vector<int>&distance){
     priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>>pq;
     distance[start]=0;
     pq.push({0,start});
     while(!pq.empty()){
        int d=pq.top().first;
        int u=pq.top().second;
        pq.pop();
        if (d > distance[u]){
            continue;
        }
        for(auto&edge:graph[u]){
            int v=edge.first;
            int weight=edge.second;
            if(distance[v]>distance[u]+weight){
                distance[v]=distance[u]+weight;
                pq.push({distance[v],v});
        }
     }
}
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m, start, end;
        cin >> n >> m >> start >> end;
        start--;
        end--;    
        vector<vector<pair<int, int>>>graph(n);
        for(int i=0;i<m;i++){
            int u, v, w;
            cin >> u >> v >> w;
            u--;
            v--;
            graph[u].push_back({v,w});
            graph[v].push_back({u,w});
        }
        vector<int> dist(n, inf);
        dijkstra(n, start, graph, dist);
        if (dist[end] == inf) {
            cout << "NONE" << '\n';
        } else {
            cout << dist[end] << '\n';
        }
    }
}

