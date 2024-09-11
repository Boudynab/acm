#include <bits/stdc++.h>
#define abdo ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int N =1e5+10,LOG = 20;
vector<int> adj[N];
int in[N], out[N], timer;
int BLift[N][LOG];
vector<int> cities[N];
vector<int> wtf[N][LOG];
void Merge(vector<int> &x, vector<int> &y){
    for (auto i : y)
        x.push_back(i);
    sort(x.begin(), x.end());
    while (x.size() > 10)
        x.pop_back();
}
void dfs(int node, int p){
    in[node] = timer++;
    BLift[node][0] = p;
    for (auto i : cities[node])
        wtf[node][0].push_back(i);
    for (int i = 1; i < LOG; i++){
        BLift[node][i] = BLift[BLift[node][i - 1]][i - 1];
        Merge(wtf[node][i], wtf[node][i - 1]);
        Merge(wtf[node][i], wtf[BLift[node][i - 1]][i - 1]);
    }
    for (auto to : adj[node]){
        if (to == p)
            continue;
        dfs(to, node);
    }
    out[node] = timer++;
}
bool isParent(int u, int v){
    return in[v] >= in[u] && out[v] <= out[u];
}
int LCA(int u, int v){
    if (isParent(u, v))
        return u;
    if (isParent(v, u))
        return v;
    for (int i = LOG - 1; i >= 0; i--)
    {
        if (!isParent(BLift[u][i], v))
        {
            u = BLift[u][i];
        }
    }
    return BLift[u][0];
}
vector<int> query(int u, int v)
{
    int lc = LCA(u, v);
    vector<int> ret;
    for (int i = LOG - 1; i >= 0; i--)
    {
        if (!isParent(BLift[u][i], lc))
        {
            Merge(ret, wtf[u][i]);
            u = BLift[u][i];
        }
        if (!isParent(BLift[v][i], lc))
        {
            Merge(ret, wtf[v][i]);
            v = BLift[v][i];
        }
    }
    if (u != lc)
        Merge(ret, wtf[u][0]);
    if (v != lc)
        Merge(ret, wtf[v][0]);
    Merge(ret, wtf[lc][0]);
    return ret;
}
 
void testCase() {
    int n, m, q;
    cin >> n >> m >> q;
 
    for (int i = 0, u, v; i < n - 1; i++)
    {
        cin >> u >> v;
 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= m; i++)
    {
        int u;
        cin >> u;
        if (cities[u].size() < 10)
            cities[u].push_back(i);
    }
    dfs(1, 1);
    while (q--)
    {
        int u, v, a;
        cin >> u >> v >> a;
        auto ans = query(u, v);
        cout << min(a, (int)ans.size()) << ' ';
        for (int i = 0; i < min(a, (int)ans.size()); i++)
            cout << ans[i] << ' ';
        cout << '\n';
    }
}
signed main() {
    abdo;
    int t = 1;
    while (t--)
        testCase();
}