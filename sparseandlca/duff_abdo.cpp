#include <bits/stdc++.h>
using namespace std;
#define abdo ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 5;
const int M = 20;
int parent[N][M];
vector<int> treee[N];
int depth[N];
vector<int> mp[N][M];
int lg[N]; //imp stores logrthic in constant time
vector<int> mergesorted(vector<int> p1, vector<int> p2, int limit) {
    vector<int> result;
    int n1 = p1.size(), n2 = p2.size();
    int i = 0, j = 0;
    while (i < n1 && j < n2 && result.size() < limit) {
        if (p1[i] < p2[j]) {
            result.push_back(p1[i]);
            i++;
        } else {
            result.push_back(p2[j]);
            j++;
        }
    }
    while (i < n1 && result.size() < limit) {
        result.push_back(p1[i]);
        i++;
    }
    while (j < n2 && result.size() < limit) {
        result.push_back(p2[j]);
        j++;
    }
    return result;
}
void dfs(int node,int p) {
    depth[node]=depth[p]+1;
    parent[node][0]=p;
    for (int j=1;j<=lg[depth[node]];j++) {
        int pa= parent[node][j-1];
        parent[node][j]=parent[pa][j-1];
        mp[node][j]=mergesorted(mp[node][j-1],mp[pa][j-1],10);
    }
    for (auto i:treee[node]) {
        if (i!=p)
            dfs(i,node);
    }
}
int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    for (int j = 0; j < M; j++) {
        if (diff & (1 << j)) {
            u = parent[u][j];
        }
    }
    if (u == v) return u;
    for (int j = M - 1; j >= 0; j--) {
        if (parent[u][j] != parent[v][j]) {
            u = parent[u][j];
            v = parent[v][j];
        }
    }
    return parent[u][0];
}
vector<int> mergedpeople(int u, int v, int limit, bool flag) {
    vector<int> result;
    if (depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    if (flag) diff++;
    for (int j = M - 1; j >= 0; j--) {
        if ((1 << j) <= diff) {
            diff -= (1 << j);
            result = mergesorted(result, mp[u][j], limit);
            u = parent[u][j];
        }
    }
    return result;
}
vector<int> finalmerge(int u, int v, int limit) {
    vector<int> result;
    int l = lca(u, v);
    result = mergesorted(mergedpeople(u, l, limit, true), mergedpeople(v, l, limit, false), limit);
    return result;
}
void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        treee[u].push_back(v);
        treee[v].push_back(u);
    }
    for (int i = 1; i <= m; i++) {
        int city;
        cin >> city;
        city--;
        if (mp[city][0].size() < 10) {
            mp[city][0].push_back(i);
        }
    }
    for (int i = 0; i < n; i++) {
        sort(mp[i][0].begin(), mp[i][0].end());
    }
    depth[0] = 0;
    dfs(0, 0);
    while (q--) {
        int u, v, limit;
        cin >> u >> v >> limit;
        u--; v--;
        vector<int> result = finalmerge(u, v, limit);
        if(result.size()<=limit){
        cout << result.size() << " ";
        for (int x : result) {
            cout << x << " ";
        }
    }
    else{
        cout << limit << " ";
        int counter=0;
        for (int i: result) {
            if(counter==limit){
                break;
            }
            else{
                counter++;
                cout << i << " ";
            }
        }
    }
        cout << endl;
    }
}
int main() {
    abdo;
    int t;
    t=1;
    lg[1]=0;
    for (int i=2;i<=1e5;i++) {
        lg[i]=lg[i/2]+1;
    }
    for (int i=0;i<t;i++) {
        solve();;
    }
    return 0;
}
