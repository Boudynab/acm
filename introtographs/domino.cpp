#include <bits/stdc++.h>
using namespace std;
bool bfs(int n, vector<pair<int, int>>& dominos) {
    vector<vector<int>> graph(n + 1);
    vector<int> color(n + 1, -1);
    for (auto &child : dominos) {
        graph[child.first].push_back(child.second);
        graph[child.second].push_back(child.first);
    }
    for (int i = 1; i <= n; i++) {  // check if graph not connected
        if (color[i] == -1) {
            queue<int> q;
            q.push(i);
            color[i] = 0;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                if (graph[u].size() > 2) {
                    return false; 
                } 
                for (auto &v : graph[u]) {
                    if (color[v] == -1) {  
                        color[v] = 1-color[u];  
                        q.push(v);
                    } else if (color[v] == color[u]) { 
                        return false;
                    }
                }
            }
        }
    }
    return true; 
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> dominos(n);
        for (int i = 0; i < n; i++) {
            cin >> dominos[i].first >> dominos[i].second;
        }
        cout << (bfs(n, dominos) ? "YES" : "NO") << endl;
    }
}
