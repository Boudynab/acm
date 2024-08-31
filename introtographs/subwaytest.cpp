#include <bits/stdc++.h>
using namespace std;
#define abdo ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
vector<ll> graph[3001];  
vector<ll> parent(3001); 
vector<ll> dist(3001,-1);
bool visited[3001];       
vector<ll> ringroad; 
bool cycledfs(ll node,ll par){
    visited[node]=true;
    parent[node] = par;
    for(auto &child : graph[node]){
        if(!visited[child]){
            if(cycledfs(child,node)){
                return true;
            }  
        }
        else if(child!=par){
            ll curr = node;
            ringroad.push_back(child);
            while(curr!=child){
                ringroad.push_back(curr);
                curr=parent[curr];
            }
            ringroad.push_back(child);
            return true;
        }
    }
    return false;
}
void bfs(){
    queue<ll>q;
    for(auto &i : ringroad){
        dist[i]=0;
        q.push(i);
    }
    while(!q.empty()){
        ll u=q.front();
        q.pop();
        for(auto &v :graph[u]){
            if(dist[v]==-1){
                dist[v]=dist[u]+1;
                q.push(v);
            }
        }
    }
}
int main(){
    abdo;
    ll n;
    cin>>n;
    for(int i=0;i<n;i++){
        graph[i].clear();
        visited[i]=false;
        dist[i]=-1;
    }
    for(ll i=0;i<n;i++){
        ll u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            if(cycledfs(i,-1)){
                break;
            }
        }
    }
    bfs();
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
}