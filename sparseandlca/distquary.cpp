#include <bits/stdc++.h>
#define abdo ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int N = 100005;  // Increased to handle up to 100,000 nodes
const int M = 25;      // 25 is sufficient for n <= 2 * 10^5
vector<int> adj[N];    // Adjacency list for the tree
int parent[N][M];      // Binary lifting table
int depth[N];          // Depth of each node
// DFS to calculate depth and initialize parent array for each node
void dfs(int node, int par, int d) {
    parent[node][0] = par;
    depth[node] = d;
    for (int child : adj[node]) {
        if (child != par) {
            dfs(child, node, d + 1);
        }
    }
}
// Function to prepare the binary lifting table
void binarylifting(int n) {
    memset(parent, -1, sizeof(parent));  
    dfs(1, -1, 0);  // Start DFS from node 1 (assuming 1-indexed tree)
    
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 1; i <= n; i++) {  // 1-indexed node
            if (parent[i][j - 1] != -1) {
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
            }
        }
    }
}
// Function to find the lowest common ancestor (LCA) of nodes u and v
int lca(int u, int v) {
    if (depth[u] < depth[v]) {
        swap(u, v);
    } 
    // Bring u and v to the same depth
    int diff = depth[u] - depth[v];
    for (int j = 0; j < M; j++) {
        if ((diff >> j) & 1) {
            u = parent[u][j];
        }
    }
    // If u and v are the same, return u
    if (u == v) {
        return u;
    }

    // Lift u and v until their parents match
    for (int i = M - 1; i >= 0; i--) {
        if (parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    
    return parent[u][0];  // Parent of u (or v) is the LCA
}

int main() {
    abdo;  // Fast IO
    
    int n, q;
    cin >> n >> q;

    // Reading the tree edges
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Prepare for binary lifting and depth calculation
    binarylifting(n);

    // Process each query
    while (q--) {
        int u, v;
        cin >> u >> v;
        int lca_node = lca(u, v);  // Find the lowest common ancestor of u and v
        // Calculate the distance
        int distance = depth[u] + depth[v] - 2 * depth[lca_node];
        cout << distance << "\n";
    }
}
