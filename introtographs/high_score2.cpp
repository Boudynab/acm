#include <bits/stdc++.h>
using namespace std;
#define inf LLONG_MAX
#define neg_inf LLONG_MIN
#define int long long
struct Edge {
    int u, v, w;
};
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<Edge> edges;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u - 1, v - 1, w});
    }
    vector<int> distance(n, -inf);
    distance[0] = 0; //bellmanford
    for (int i = 0; i < n - 1; i++) {
        for (const auto& edge : edges) {
            if (distance[edge.u] != -inf && distance[edge.v] < distance[edge.u] + edge.w) {
                distance[edge.v] = distance[edge.u] + edge.w;
            }
        }
    }
    vector<bool> negcycles(n, false);
    for (int i = 0; i < n - 1; i++) {
        for (const auto& edge : edges) {
            if (distance[edge.u] != -inf && distance[edge.v] < distance[edge.u] + edge.w) {
                distance[edge.v] = distance[edge.u] + edge.w;
                negcycles[edge.v] = true;
            }
        }
    }
    vector<bool> reachable(n, false);
    // dfs negative cycle nodes
    function<void(int)> dfs = [&](int u) {
        reachable[u] = true;
        for (const auto& edge : edges) {
            if (edge.u == u && !reachable[edge.v]) {
                dfs(edge.v);
            }
        }
    };
    for (int i = 0; i < n; i++) {
        if (negcycles[i]) {
            dfs(i);
        }
    }
    // If inf cycle from negtive cycle 
    if (reachable[n - 1]) {
        cout << "-1\n";
    } else {
        cout << distance[n - 1] << '\n';
    }
}