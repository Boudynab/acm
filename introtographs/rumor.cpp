#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<int>> graph;
vector<bool> visited;
vector<int> cost;
void dfs(int nodes,vector<int>&comp){
    stack<int>s;
    s.push(nodes);
    visited[nodes]=true;
    while(!s.empty()){
        int u=s.top();
        s.pop();
        comp.push_back(u);
        for(auto v:graph[u]){
            if(!visited[v]){
                visited[v]=true;
                s.push(v);
            }
        }
    }
}
int main(){
int n, m;
    cin >> n >> m;
    graph.resize(n+1);
    visited.resize(n+1,false);
    cost.resize(n+1);
    for (int i=1;i<=n;i++) {
        cin >> cost[i];
    }
    for (int i=0;i<m;i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    ll totelcost=0;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            vector<int> comp;
            dfs(i,comp);
           ll minCost =LLONG_MAX;
            for (int node :comp) {
                minCost = min(minCost,(ll)cost[node]);
            }
            totelcost += minCost;
        }
    }
    cout << totelcost << endl;
}

