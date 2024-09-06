#include <bits/stdc++.h>
#define abdo ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using namespace std;
void dfs(int node, int bit, int& count, vector<vector<pair<int, int>>>& adj, vector<bool>& visited, int canExclude) {
    visited[node] = true;
    count++;
    for (auto& i : adj[node]) {
        int adjNode = i.first;
        int adjWeight = i.second;
        if (!visited[adjNode]) {
            if (!(adjWeight & (1 << bit)) && !(adjWeight & canExclude)) {
                dfs(adjNode, bit, count, adj, visited, canExclude);
            }
        }
    }
}
int main() {
    abdo;
    int t;
    cin >> t;
    while(t--){
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    int cantExclude = 0, canExclude = 0;
    vector<bool> visited(n, false);
    for (int i = 30; i >= 0; i--) {
        int count = 0;
        fill(visited.begin(),visited.end(),false);  
        dfs(0, i, count, adj, visited, canExclude); 
        if (count != n) {
            cantExclude += (1 << i);
        } else {
            canExclude += (1 << i);
        }
    }
    cout << cantExclude << endl;
    }
}
 