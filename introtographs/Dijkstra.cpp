#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define vii vector<pii>
#define inf LLONG_MAX
vector<vii> graph;
vector<int> dist;
vector<int> parent;
int n, m;
void dijkstra(int src) {
    dist[src] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, src});
    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if (d > dist[u]) {
            continue;
        }
        for (auto &edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
                parent[v] = u;
            }
        }
    }
}
void printPath(int dest) {
    if (parent[dest] == -1) {
        cout << dest;
        return;
    }
    printPath(parent[dest]);
    cout << " " << dest;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    graph.resize(n + 1);
    dist.assign(n + 1, inf);
    parent.assign(n + 1, -1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    dijkstra(1);
    if (dist[n] == inf) {
        cout << -1 << endl;
    } else {
        printPath(n);
        cout << endl;
    }
}
