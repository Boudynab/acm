#include <bits/stdc++.h>
using namespace std;
#define abdo ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
bool visited[(ll)200];
vector <ll> graph[(ll)200] ;
vector <ll> color((ll)200,2);
bool flag =true;
ll c[2]={0,0};
void dfs(ll node){
    visited[node]=1;
    for(auto &e : graph[node]){
        if(!visited[e]){
            color[e]=1-color[node];
            c[color[e]]++;
            dfs(e);
        }
        else if(color[e]==color[node]){
            flag=false;
        }
    }
}
int main() {
    abdo;
    int t;
    cin>>t;
    while(t--){
        int v,e;
        cin >>v>>e;
        for(int i=0;i<v;i++){
            graph[i].clear();
            visited[i]=false;
            color[i]=2;
        }
        flag=true;
        for(int i=0;i<e;i++){
            int x,y;
            cin>>x>>y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        int quardcount=0;
        for(int i=0;i<v;i++){
            if(!visited[i]){
                c[0]=1;
                c[1]=0;
                color[i]=0;
                dfs(i);
                quardcount+=min(c[0],c[1]);
                if(c[0]+c[1]==1){
                    quardcount++;
                }
            }
        }
        if(flag){
            cout<<quardcount<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
}
