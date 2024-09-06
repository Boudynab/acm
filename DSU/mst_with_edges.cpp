#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXN = 200005;
const int LOG = 20;  // For binary lifting, log2(MAXN) is around 18, so we take 20 to be safe
struct Edge {
    int u, v, w, index;
    bool inMST;
};
 
int parent[MAXN], rnk[MAXN];
vector<pair<int, int>> adj[MAXN];  // adjacency list to store MST
Edge edges[MAXN];
int up[MAXN][LOG];     // Binary lifting table for LCA
int maxEdge[MAXN][LOG];  // Maximum edge weight on the path to the ancestor
int depth[MAXN];
int n, m;
 
// DSU functions
void initDSU(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rnk[i] = 0;
    }
}
 
int find(int u) {
    if (u != parent[u])
        parent[u] = find(parent[u]);
    return parent[u];
}
 
bool unionSet(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);
    if (rootU == rootV) return false;
    if (rnk[rootU] > rnk[rootV]) parent[rootV] = rootU;
    else if (rnk[rootU] < rnk[rootV]) parent[rootU] = rootV;
    else {
        parent[rootV] = rootU;
        rnk[rootU]++;
    }
    return true;
}
 
// Kruskal's algorithm for MST
long long kruskal() {
    sort(edges, edges + m, [](Edge &a, Edge &b) {
        return a.w < b.w;
    });
    
    initDSU(n);
    long long mstWeight = 0;
    for (int i = 0; i < m; i++) {
        if (unionSet(edges[i].u, edges[i].v)) {
            mstWeight += edges[i].w;
            edges[i].inMST = true;
            adj[edges[i].u].emplace_back(edges[i].v, edges[i].w);
            adj[edges[i].v].emplace_back(edges[i].u, edges[i].w);
        }
    }
    return mstWeight;
}
 
// DFS to prepare binary lifting table
void dfs(int node, int par, int w, int d) {
    up[node][0] = par;
    maxEdge[node][0] = w;
    depth[node] = d;
    
    for (int i = 1; i < LOG; i++) {
        if (up[node][i - 1] != -1) {
            up[node][i] = up[up[node][i - 1]][i - 1];
            maxEdge[node][i] = max(maxEdge[node][i - 1], maxEdge[up[node][i - 1]][i - 1]);
        }
    }
    
    for (auto &[v, weight] : adj[node]) {
        if (v != par) {
            dfs(v, node, weight, d + 1);
        }
    }
}
 
// LCA and maximum edge weight query
int queryLCA(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    
    int maxW = 0;
    int diff = depth[u] - depth[v];
    
    for (int i = LOG - 1; i >= 0; i--) {
        if ((diff >> i) & 1) {
            maxW = max(maxW, maxEdge[u][i]);
            u = up[u][i];
        }
    }
    
    if (u == v) return maxW;
    
    for (int i = LOG - 1; i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
            maxW = max({maxW, maxEdge[u][i], maxEdge[v][i]});
            u = up[u][i];
            v = up[v][i];
        }
    }
    
    maxW = max({maxW, maxEdge[u][0], maxEdge[v][0]});
    return maxW;
}
 
int main() {
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        edges[i].u--; edges[i].v--;  // Zero-indexing for convenience
        edges[i].index = i;
        edges[i].inMST = false;
    }
    
    // Step 1: Kruskal to find the MST
    long long mstWeight = kruskal();
    
    // Step 2: Prepare for LCA
    memset(up, -1, sizeof(up));
    dfs(0, -1, 0, 0);  // Assuming node 0 is the root
    
    // Step 3: Process each edge
    vector<long long> result(m);
    
    for (int i = 0; i < m; i++) {
        if (edges[i].inMST) {
            result[edges[i].index] = mstWeight;
        } else {
            int u = edges[i].u, v = edges[i].v, w = edges[i].w;
            int maxW = queryLCA(u, v);
            result[edges[i].index] = mstWeight - maxW + w;
        }
    }
    
    // Step 4: Output results
    for (int i = 0; i < m; i++) {
        cout << result[i] << endl;
    }
    
    return 0;
}