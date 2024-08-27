#include <bits/stdc++.h>
using namespace std;
bool bfs(int n,int m,vector<vector<int>>&graph){
    if(m!=n-1){
        return false;
    }
    vector<bool>visted(n+1,false);
    queue<int>q;
    q.push(1);
    visted[1]=true;
    int count=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        count++;
        for(auto &v:graph[u]){
            if(!visted[v]){
                visted[v]=true;
                q.push(v);
            }
            else if(v==n){
                return true; //check if we arrived last node and all visted
            }
        }
    }
    return count==n;   // Check if we visited all nodes
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>graph(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cout<<(bfs(n,m,graph)?"YES":"NO")<<endl;
}