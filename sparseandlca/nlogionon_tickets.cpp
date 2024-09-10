#include <bits/stdc++.h>
using namespace std;
#define abdo ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
const int N = 200005;
const int M = 20;
vector<pair<int, int>>adj[N];//{neighbor,ticket_cost}
int parent[N][M],max_ticket[N][M],depth[N];
void dfs(int node, int par, int d, int ticket_cost) {
    parent[node][0] = par;
    depth[node] = d;
    max_ticket[node][0] = ticket_cost;
    for (auto &edge : adj[node]) {
        int child = edge.first, cost = edge.second;
        if (child != par) {
            dfs(child, node,d+1,cost);
        }
    }
}
void binaryLiftingTable(int n) {
    for (int j = 1; j < M; j++) {
        for (int i = 1; i <= n; i++) {
            if (parent[i][j-1] != -1) {
                parent[i][j] = parent[parent[i][j-1]][j-1];
                max_ticket[i][j] = max(max_ticket[i][j-1], max_ticket[parent[i][j-1]][j-1]);
            }
        }
    }
}
int maxTicketOnPath(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    int max_ticket_value = 0;
    int diff = depth[u] - depth[v];
    for (int j = 0; j < M; j++) {
        if (diff & (1 << j)) {
            max_ticket_value = max(max_ticket_value, max_ticket[u][j]);
            u = parent[u][j];
        }
    }
    if (u == v) {
        return max_ticket_value;
        }
    for (int j = M - 1; j >= 0; j--) {
        if (parent[u][j] != parent[v][j]) {
            max_ticket_value = max({max_ticket_value, max_ticket[u][j], max_ticket[v][j]});
            u = parent[u][j];
            v = parent[v][j];
        }
    } 
    // Finally, the LCA is one step above u and v, so consider their parents
    return max({max_ticket_value, max_ticket[u][0], max_ticket[v][0]});
}
int main() {
    abdo;
    int n;
    while (cin >> n && n != 0) {
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
        }
        for (int i = 1; i < n; i++) {
            int a, b, t;
            cin >> a >> b >> t;
            adj[a].emplace_back(b, t);
            adj[b].emplace_back(a, t);
        }  
        memset(parent, -1, sizeof(parent));
        dfs(1, -1, 0, 0);  // Assuming node 1 is the root
        binaryLiftingTable(n);
        int q;
        cin >> q;
        while (q--) {
            int a, b;
            cin >> a >> b;
            cout << maxTicketOnPath(a, b) << endl;
        }
        cout << '\n';
    }
    return 0;
}