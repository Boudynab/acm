#include <bits/stdc++.h>
using namespace std;
#define inf LLONG_MAX
#define neg_inf LLONG_MIN
#define int long long
struct Edge {
    int u, v, w;
};
void bellmanFord(int n, vector<Edge>& edges, vector<vector<int>>& dist) {
    for (int src = 0; src < n; src++) {
        dist[src][src] = 0;
        for (int i = 0; i < n - 1; i++) {
            for (const auto& edge : edges) {
                if (dist[src][edge.u] != inf && dist[src][edge.v] > dist[src][edge.u] + edge.w) {
                    dist[src][edge.v] = dist[src][edge.u] + edge.w;
                }
            }
        }
        // Check for negative weight cycles
        for (const auto& edge : edges) {
            if (dist[src][edge.u] != inf && dist[src][edge.v] > dist[src][edge.u] + edge.w) {
                dist[src][edge.v] = neg_inf;
            }
        }
        // Propagate -Infinity for nodes reachable from a cycle
        for (int i = 0; i < n - 1; i++) {
            for (const auto& edge : edges) {
                if (dist[src][edge.u] == neg_inf) {
                    dist[src][edge.v] = neg_inf;
                }
            }
        }
    }
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (true) {
        int n, m, q;
        cin >> n >> m >> q;
        if (n == 0 && m == 0 && q == 0) break;
        vector<Edge> edges(m);
        for (int i = 0; i < m; i++) {
            cin >> edges[i].u >> edges[i].v >> edges[i].w;
        }  
        vector<vector<int>> dist(n, vector<int>(n, inf));
        bellmanFord(n, edges, dist);
        while (q--) {
            int u, v;
            cin >> u >> v;
            if (dist[u][v] == inf) {
                cout << "Impossible\n";
            } else if (dist[u][v] == neg_inf) {
                cout << "-Infinity\n";
            } else {
                cout << dist[u][v] << '\n';
            }
        }
        cout << '\n';
    }
}
