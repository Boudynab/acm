#include <bits/stdc++.h>
#define abdo ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int MAXN=105;
int parent[MAXN];
int sizee[MAXN];
vector<int>languagess[MAXN];
void dsu(int n) {
    for (int i=1;i<=n;i++) {
        parent[i]=i;
        sizee[i]=1;
    }
}
int find (int s) {
    if (parent[s]==s) {
        return s;
    }
    else {
        return parent[s]= find(parent[s]);
    }
}
void join(int u,int v) {
    u=find(u);
    v=find(v);
    if (u==v) {
        return;
    }
    if (sizee[u]<sizee[v]) {
        swap(u, v);
    }
    parent[v]=parent[u];
    sizee[u]+=sizee[v];
}
int main() {
    abdo;
    int n,m;
    cin>>n>>m;
    dsu(n);
    bool flag =false;
    for (int i=1;i<=n;i++) {
        int k;
        cin>>k;
        for (int j=1;j<=k;j++) {
            flag=true;
            int x;
            cin>>x;
            languagess[x].push_back(i);
        }
    }
    for (int i=1;i<=m;i++) {
     for (auto j:languagess[i]) {
         for (auto k:languagess[i]) {
             join(j,k);
         }
     }
    }
    int count=0;
    for (int i=1;i<=n;i++) {
       if (find(i)==i) {
           count++;
       }
    }
    if (flag) {
    cout<<count-1;
    }
    else cout<<n;
    return 0;;
}