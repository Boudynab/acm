#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
const int INF = LLONG_MAX;
struct Edge {
    int to, weight;
};
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<Edge>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w}); 
    }
    vector<vector<int>> dist(n + 1, vector<int>(2, INF));
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[1][0] = 0;
    pq.push({0,1*2+0});
    while (!pq.empty()) {
        int d = pq.top().first;
        int node = pq.top().second;
        int u = node / 2;
        int couponUsed = node % 2;
        pq.pop();
        if (d > dist[u][couponUsed]) continue;
        for (auto &e : graph[u]) {
            int v = e.to;
            int w = e.weight;
            // no coupen
            if (dist[v][couponUsed] > dist[u][couponUsed] + w) {
                dist[v][couponUsed] = dist[u][couponUsed] + w;
                pq.push({dist[v][couponUsed], v * 2 + couponUsed});
            }
            // coupen
            if (!couponUsed && dist[v][1] > dist[u][0] + w / 2) {
                dist[v][1] = dist[u][0] + w / 2;
                pq.push({dist[v][1], v * 2 + 1});
            }
        }
    }
    cout << min(dist[n][0], dist[n][1]) << endl;
}
