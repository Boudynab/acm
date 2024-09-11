#include <bits/stdc++.h>
#define abdo ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int N = 2 * (100005);
const int M = 25;
vector<int> adj[N];
int parent[N][M], depth[N];
vector<int> cityPeople[N]; // Stores sorted people in each city
// DFS for computing parent and depth arrays
void dfs(int node, int par) {
    parent[node][0] = par;
    for (int i = 1; i < M; i++) {
        if (parent[node][i - 1] != -1) {
            parent[node][i] = parent[parent[node][i - 1]][i - 1];
        }
    }
    for (auto child : adj[node]) {
        if (child == par) continue;
        depth[child] = depth[node] + 1;
        dfs(child, node);
    }
}
// LCA (Lowest Common Ancestor) using Binary Lifting
int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    for (int i = M - 1; i >= 0; i--) {
        if (diff & (1 << i)) u = parent[u][i];
    }
    if (u == v) return u;
    for (int i = M - 1; i >= 0; i--) {
        if (parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}
// Merging two vectors of people and keeping the first "limit" smallest elements
vector<int> mergePeople(const vector<int>& p1, const vector<int>& p2, int limit) {
    vector<int> result;
    int i = 0, j = 0;
    while (result.size() < limit && (i < p1.size() || j < p2.size())) {
        if (i < p1.size() && (j >= p2.size() || p1[i] < p2[j])) {
            result.push_back(p1[i++]);
        } else {
            result.push_back(p2[j++]);
        }
    }
    return result;
}
// Getting people on the path from u to v, including the LCA people
vector<int> getPeopleOnPath(int u, int v, int a) {
    vector<int> upath, vpath, lcaPeople = cityPeople[lca(u, v)];
    // Collecting people from u to the LCA
    while (u != lca(u, v)) {
        upath = mergePeople(upath, cityPeople[u], a);
        u = parent[u][0];
    }
    // Collecting people from v to the LCA
    while (v != lca(u, v)) {
        vpath = mergePeople(vpath, cityPeople[v], a);
        v = parent[v][0];
    }
    // Merge people from upath, vpath, and LCA
    vector<int> pathPeople = mergePeople(upath, vpath, a);
    pathPeople = mergePeople(pathPeople, lcaPeople, a);
    
    return pathPeople;
}
int main() {
    abdo;
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // Read where each person lives
    for (int i = 1; i <= m; ++i) {
        int city;
        cin >> city;
        cityPeople[city].push_back(i);
    }
    // Sort people in each city by ID
    for (int i = 1; i <= n; ++i) {
        sort(cityPeople[i].begin(), cityPeople[i].end());
    }
    memset(parent, -1, sizeof(parent));
    dfs(1, -1);
    while (q--) {
        int u, v, a;
        cin >> u >> v >> a;
        vector<int> pathPeople = getPeopleOnPath(u, v, a);
        cout << pathPeople.size() << " ";
        for (auto pep : pathPeople) {
            cout << pep << " ";
        }
        cout << "\n";
    }
    return 0;
}
