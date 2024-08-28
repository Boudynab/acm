#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define F first
#define S second
#define pii pair<int, int>
#define vii vector<pii>
#define inf LLONG_MAX
int vis[100005], dis[100005];
vii adj[100005];
void solve() {  // djikter
    int n, m; 
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        vis[i] = 0;
        dis[i] = inf;
    }
    for (int i = 0; i < m; i++) {
        int u, v, w; 
        cin >> u >> v >> w;
        adj[u].pb({v, w});
    }
    priority_queue<pii, vii, greater<pii>> q;
    dis[1] = 0;
    q.push({0, 1});
    while (!q.empty()) {
        int u = q.top().S; 
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto &edge : adj[u]) {
            int v = edge.F, w = edge.S;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.push({dis[v], v});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (dis[i] == inf)
            cout << -1 << " "; 
        else
            cout << dis[i] << " ";
    }
    cout << '\n';
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
