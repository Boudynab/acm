#include <bits/stdc++.h>
using namespace std;
#define abdo ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
vector<int> tree[3001];
bool visited[3001];
pair<int, int> bfs(int start, int n) {
    queue<int> q;
    vector<int> dist(n + 1, -1);
    dist[start] = 0;
    q.push(start);
    int farthest = start;
    int max_distance = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto &child : tree[node]) {
            if (dist[child] == -1) {
                dist[child] = dist[node] + 1;
                q.push(child);
                if (dist[child] > max_distance) {
                    farthest = child;
                    max_distance = dist[child];
                }
            }
        }
    }
    return {farthest, max_distance};
}
int32_t main() {
    abdo;
    int t;
    cin >> t;
    while (t--) {
        int n, k, c;
        cin >> n >> k >> c;
        for (int i = 1; i <= n; i++) {
            tree[i].clear();
        }
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        pair<int, int> p1 = bfs(1, n);
        pair<int, int> p2 = bfs(p1.first, n);
        int diameter = p2.second;    
        cout << diameter << "\n";
    }
    return 0;
}
