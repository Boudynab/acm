#include <bits/stdc++.h>
#define abdo ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int N = 2*(100005); 
const int M = 25;      
vector<int> adj[N];    
int parent[N][M];      
int depth[N];        
void dfs(int node, int par, int d) {
    parent[node][0] = par;
    depth[node] = d;
    for (int child : adj[node]) {
        if (child != par) {
            dfs(child, node, d + 1);
        }
    }
}
void binarylifting(int n) {
    memset(parent, -1, sizeof(parent));  
    dfs(1, -1, 0);   //(assuming 1-indexed tree)
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 1; i <= n; i++) { 
            if (parent[i][j - 1] != -1) {
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
            }
        }
    }
}
int lca(int u, int v) {
    if (depth[u] < depth[v]) {
        swap(u, v);
    } 
    int diff = depth[u] - depth[v];
    for (int j = 0; j < M; j++) {
        if ((diff >> j) & 1) {
            u = parent[u][j];
        }
    }
    if (u == v) {
        return u;
    }
    for (int i = M - 1; i >= 0; i--) {
        if (parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}
int main() {
    abdo;  
    int n, q;
    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    binarylifting(n);
    while (q--) {
        int u, v;
        cin >> u >> v;
        int lca_node = lca(u, v); 
        int distance = depth[u] + depth[v] - 2 * depth[lca_node];
        cout << distance << "\n";
    }
}
