#include <bits/stdc++.h>
#define abdo ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int N=2e5+5;
int n;
int sizee[N];
int parent[N]; 
vector<int>cats[N]; 
 void dsu(int u){
        parent[u]=u;
        sizee[u]=1;
        cats[u].push_back(u);
 }
int get_leader(int u) {
    if(u==parent[u]){
        return u;
    }
  return parent[u]=get_leader(parent[u]);
}
void union_sets(int u,int v){
    u=get_leader(u);
    v=get_leader(v);
    if(u!=v){
        if(sizee[u]<sizee[v]){
            swap(u,v);
        }
        parent[v]=u;
        sizee[u]+=sizee[v];
        for(auto &i :cats[v]){
            cats[u].push_back(i);
        }
    }
}
int main(){
    abdo;
    cin >>n;
    for(int i=1;i<=n;i++){
        dsu(i);
    }
    for(int i=1;i<n;i++){
        int u,v;
        cin >> u >> v;
        union_sets(u,v);
    }
    int last_leader=get_leader(n);
    for(auto &i:cats[last_leader]){
        cout << i << " ";
    }
    cout << endl;
}