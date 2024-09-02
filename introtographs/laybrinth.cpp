#include <bits/stdc++.h>
#define abdo ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define rep(n) for(int i=1;i<=n;i++)
#define all(v) v.begin(),v.end()
using namespace std;
const int N=2e5+5;
vector<int>graph[N];
int parent[N];
int path[N];
bool vis[N];
int n,m,s,a,b;
int count_cycle=0;
int p1=-1,p2=-1;
void dfs(int i) {
    vis[i]=1;
    path[i]=count_cycle;
    for(auto &child:graph[i]) {
        if(!vis[child]) {
            parent[child]=i;
            dfs(child);
            if(i==s){
                count_cycle++;
            }   
        }
        else if((path[i]!=path[child]||i==s)&&child!=s) {
            p1=i;
            p2=child;
            return;
        }
    }
}
int main() {
        abdo;
        cin>>n>>m>>s;
        rep(m) {
            cin>>a>>b;
            graph[a].push_back(b);
        }
        dfs(s);
        if(p1==-1||p2==-1) {
            cout<<"Impossible\n";
            return 0;
        }
        cout<<"Possible\n";
        vector<int>res1,res2;
        res1.push_back(p2);
        while(p1!=s) {
            res1.push_back(p1);
            p1=parent[p1];
        }
        res1.push_back(s);
        while(p2!=s) {
            res2.push_back(p2);
            p2=parent[p2];
        }
        res2.push_back(s);
        reverse(res1.begin(),res1.end());
        reverse(res2.begin(),res2.end());
        cout<<res1.size()<<endl;
        for(auto it:res1)
            cout<<it<<" ";
        cout<<endl;
        cout<<res2.size()<<endl;
        for(auto it:res2)
            cout<<it<<" ";
        cout<<endl;
}
 