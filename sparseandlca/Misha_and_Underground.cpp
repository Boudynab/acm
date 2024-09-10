#include <bits/stdc++.h>
#define abdo ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int N = 200005;
const int M = 20;
vector<int> adj[N];    
int parent[N][M];      
int depth[N];  
void dfs(int node, int par, int dep) {
    parent[node][0] = par;
    depth[node] = dep;
    for (auto &child : adj[node]) {
        if (child != par) {
            dfs(child, node, dep + 1);
        }
    }
}
void binaryLiftingTable(int n) {
    memset(parent, -1, sizeof(parent));
    dfs(1, -1, 0);  // Assuming node 1 is the root
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
        if (diff & (1 << j)) {
            u = parent[u][j];
        }
    }
    if (u == v) {
        return u;
    }
    for (int j = M - 1; j >= 0; j--) {
        if (parent[u][j] != parent[v][j]) {
            u = parent[u][j];
            v = parent[v][j];
        }
    }
    return parent[u][0];
}
int distance(int u, int v) {
    int lca_node = lca(u, v);
    return depth[u] + depth[v] - 2 * depth[lca_node];
}
int main() {
    abdo;
    int n, q;
    cin >> n >> q; 
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        adj[p].push_back(i);
        adj[i].push_back(p);
    } 
    binaryLiftingTable(n);
    while (q--) {
       int arr[3];
    cin >> arr[0]>> arr[1] >>arr[2];
    int maxi=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                if(i==j||j==k||i==k){
                    continue;
                }
                int s=arr[i],t=arr[j],f=arr[k];
                int misha=depth[s]+depth[f]-(s*depth[(lca(s,f))]);
                int grisha=depth[t]+depth[f]-(s*depth[(lca(t,f))]);
                int diff=depth[s]+depth[t]-(s*depth[(lca(s,t))]);
                maxi=max(((misha+grisha-diff)/2)+1,maxi);
            }
        }
    }
    cout<<maxi<<endl;
}
}
