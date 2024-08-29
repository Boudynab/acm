#include <bits/stdc++.h>
using namespace std;
const int N =3000*100+5;
long long n,m,x,sum,dist[N];
bool mark[N];
vector<int> ans,edge;
vector<pair<int, int>>adj[N];
priority_queue<pair<pair<long long, long long>, pair<long long, long long>>, vector<pair<pair<long long, long long>, pair<long long, long long>>>, greater<pair<pair<long long, long long>, pair<long long, long long>>>> q;
void min_spanning_tree() {
    fill(dist,dist+n,LLONG_MAX);
    dist[x] = 0;
    q.push({{0, x},{-1,-1}});
    while (!q.empty()) {
        int d = q.top().first.first, u = q.top().first.second;
        int wei = q.top().second.first, ind = q.top().second.second;
        q.pop();
        if (!mark[u]) {
            mark[u] = true;
            if (ind != -1)
                ans.push_back(ind);
            int sz = adj[u].size();
            for (auto [v, i]: adj[u])
                if (dist[u] + edge[i] <= dist[v]) {
                    dist[v] = dist[u] + edge[i];
                    q.push({{dist[v], v}, {edge[i], i}});
                }
        }
    }
    int sz = ans.size();
    for (int i = 0; i < sz; i++)
        sum += edge[ans[i]];
}
int main() {
    ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        edge.push_back(w);
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }
    cin >> x;
    x--;
    min_spanning_tree();
     cout << sum << endl;
    int sz = ans.size();
    for (int i = 0; i < sz; i++)
    cout << ans[i] + 1 << " ";
}