#include <bits/stdc++.h>
using namespace std;
#define abdo ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int a = -1, b = -1;
void solve() {
    int n, m, start;
    cin >> n >> m >> start;
    vector<vector<int>> graph(n + 1);
    vector<int> par(n + 1, -1);
    vector<int> vis(n + 1, 0);
    int count_cycle = 1;
    bool found = false;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    function<void(int, int)> dfs = [&](int node, int parent) {
        par[node] = parent;
        vis[node] = count_cycle;
        for (int child : graph[node]) {
            if (vis[child]) {
                if (vis[child] != count_cycle) {
                    a = node;
                    b = child;
                    found = true;
                    return;
                }
                continue;
            }
            dfs(child, node);
            if (found) return;
        }
    };
    for (int child : graph[start]) {
        if (vis[child]) {
            a = par[child];
            b = child;
            found = true;
        }
        dfs(child, start);
        count_cycle++;
        if (found) {
            vector<int> v1, v2;
            v1.push_back(b);
            while (a != -1 && a != start) {
                v1.push_back(a);
                a = par[a];
            }
            v1.push_back(start);
            while (b != -1 && b != start) {
                v2.push_back(b);
                b = par[b];
            }
            v2.push_back(start);
            reverse(v1.begin(), v1.end());
            reverse(v2.begin(), v2.end());
            cout << "Possible\n";
            cout << v1.size() << endl;
            for (int &x : v1)
                cout << x << ' ';
            cout << endl << v2.size() << endl;
            for (int &x : v2)
                cout << x << ' ';
            return;
        }
    }
    cout << "Impossible";
}
int main() {
    abdo;
    solve();
    return 0;
}

