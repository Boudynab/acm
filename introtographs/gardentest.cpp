#include <bits/stdc++.h>
using namespace std;
#define abdo ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
vector<int> tree[300001]; 
vector<int> bfs(int start, int n) {
    queue<int> q;
    vector<int> dist(n + 1, -1);
    dist[start] = 0;
    q.push(start);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto &child : tree[node]) {
            if (dist[child] == -1) {
                dist[child] = dist[node] + 1;
                q.push(child);
            }
        }
    }
    return dist;
}
int32_t main() {
    abdo;
    int t;
    cin >> t;
    while (t--) {
        int n, k, c;
        cin >> n >> k >> c;
        for (int i = 0; i <= n; i++) {
            tree[i].clear();
        }
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        auto end1 = bfs(1, n); //array of dist to end1 
        int s = max_element(end1.begin(),end1.end())-end1.begin(); //end 1 of diamter
        auto end2 = bfs(s, n);  //array of dist to end2
        int diamtier = max_element(end2.begin(),end2.end())-end2.begin();//end 2 of diamter
        int max_profit = 0;
        for (int i = 1; i <= n; i++) {
            max_profit = max(max_profit, k * end2[i] - c * end1[i]);
        }
        cout << max_profit << "\n";
    }
    return 0;
}
