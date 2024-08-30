#include <bits/stdc++.h>
using namespace std;
#define abdo ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
vector<ll> graph[3001];  
vector<ll> parent(3001); 
vector<ll> dist(3001, -1);
bool visited[3001];       
vector<ll> ringroad;  
bool cycledfs(ll node, ll par) {
    visited[node] = true;
    parent[node] = par;
    for (auto &child : graph[node]) {
        if (!visited[child]) {
            if (cycledfs(child, node)) {
                return true;
            }
        } else if (child != par) { 
            // Cycle detected
            ll cur = node;
            ringroad.push_back(child);
            while (cur != child) {
                ringroad.push_back(cur);
                cur = parent[cur];
            }
            ringroad.push_back(child); // Complete the cycle
            return true;
        }
    }
    return false;
}
void bfs() {
    queue<ll> q;  
    for (auto &node : ringroad) {
        dist[node] = 0;
        q.push(node);
    }
    while (!q.empty()) {
        ll node = q.front();
        q.pop();
        
        for (auto &child : graph[node]) {
            if (dist[child] == -1) { 
                dist[child] = dist[node] + 1;
                q.push(child);
            }
        }
    }
}
int main() {
    abdo;
    ll n;
    cin >> n;
    for (int i = 1; i <= n; i++) { 
        visited[i] = false;
        graph[i].clear();
        dist[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        ll u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (cycledfs(i, -1)) {
                break;
            }
        }
    }
    bfs();
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
    return 0;
}
