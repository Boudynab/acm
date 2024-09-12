#include <bits/stdc++.h>
#define abdo ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int N =2e5+10,M=20;
vector<int> adj[N];
int parent[N][M];
vector<int>depth(N,0);
vector<int>answer(N,0);
map<pair<int,int>,int>mp;
void dfs(int node,int par){
    parent[node][0]=par;
    depth[node]=depth[par]+1;
    for(int i=1;i<M;i++){
        parent[node][i]=parent[parent[node][i-1]][i-1];
    }
    for(auto &child :adj[node]){
        if(child!=par){
            dfs(child,node);
        }
    }
}
int LCA(int u, int v){
  if (depth[u] < depth[v])
    swap(u, v);
  int diff = depth[u] - depth[v];
  for (int i = M - 1; i >= 0; i--){
    if ((diff >> i) & 1){
      u = parent[u][i];
    }
  }
  if (u == v)
    return u;
  for (int i = M - 1; i >= 0; i--){
    if (parent[u][i] != parent[v][i]){
      u = parent[u][i];
      v = parent[v][i];
    }
  }
  return parent[u][0];
}
void find_ans(int node,int par){
    for(auto &child : adj[node]){
        if(child==par){
            continue;
        }
        find_ans(child,node);
        answer[node]+=answer[child];
        mp[{child,node}]=answer[child];  
    }
}
int main(){
    abdo;
    int n;
    cin>>n;
    vector<pair<int,int>>edges;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        edges.push_back({u,v});
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    int k;
    cin>>k;
    while(k--){
        int a,b;
        cin>>a>>b;
        int l=LCA(a,b);
        answer[a]++;
        answer[b]++;
        answer[l]-=2;
    }
    find_ans(1,0);
    for(auto &x:edges){
        if(mp[x]){
            cout<<mp[x]<<endl;
        }
        else{
            cout<<mp[{x.second, x.first}]<<endl;
        }
    }
}

