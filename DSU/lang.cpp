#include <bits/stdc++.h>
#define abdo ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int MAXN=105;
int parent[MAXN];
int sizee[MAXN];
bool flag = false;
vector<int>languagess[MAXN];
void dsu(int u){
    parent[u]=u;
    sizee[u]=1;
}
int get_leader(int u){
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
    }
}
int main(){
    abdo;
    int n,m;
    cin >>n>>m;
    for(int i=1;i<=n;i++){
        dsu(i);
    }
    for(int i=1;i<=n;i++){
        flag=true;
        int k;
        cin >> k;
        for(int j=1;j<=k;j++){
            int l;
            cin >> l;
            languagess[i].push_back(l);
        }
    }
    for(int i=1;i<=m;i++){
        for(auto &x:languagess[i])
          for(auto &y:languagess[i]){
            union_sets(x,y);
          }
    }
    int count=0;
    for(int i=1;i<=n;i++){
        if(get_leader(i)==i){
            count++;
        }
    }
    if(flag){
    cout << count-1 <<endl;
    }
    else{
        cout << n << endl;
    }
} 
