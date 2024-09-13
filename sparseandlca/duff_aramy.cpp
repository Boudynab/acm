#include <bits/stdc++.h>
#define ll int
#define Moeen ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll MAX=1e5+7;
const ll lgM=17;
ll ancestor [MAX][lgM];
ll level[MAX];
vector<ll>g[MAX];
ll lg[MAX];
vector<ll>mp[MAX][lgM];
vector<ll> merge(vector<ll>s1,vector<ll>s2,ll a) {
    vector<ll>ans;
    ll n1=s1.size(),n2=s2.size();
    ll i=0,j=0;
    while(i<n1 && j<n2&&ans.size()<a) {
        if(s1[i]<s2[j]) {
            ans.push_back(s1[i++]);
        }
        else {
            ans.push_back(s2[j++]);
        }
    }
    while(i<n1&&ans.size()<a) {
        ans.push_back(s1[i++]);
    }
    while(j<n2&&ans.size()<a) {
        ans.push_back(s2[j++]);
    }
    return ans;
}
void dfs(ll node,ll p) {
    level[node]=level[p]+1;
    ancestor[node][0]=p;
    for (ll j=1;j<=lg[level[node]];j++) {
        ll pa= ancestor[node][j-1];
        ancestor[node][j]=ancestor[pa][j-1];
        mp[node][j]=merge(mp[node][j-1],mp[pa][j-1],10);
    }
    for (auto i:g[node]) {
        if (i!=p)
            dfs(i,node);
    }
}
ll findKthAncestor(ll u,ll k) {
    for (ll j=lgM-1;j>=0;j--) {
        if (k&(1<<j)) {
            u=ancestor[u][j];
        }
    }
    return u;
}
ll getLCA(ll u,ll v) {
    if (level[u]<level[v])
        swap(u,v);
    u=findKthAncestor(u,level[u]-level[v]);
    if(u==v)
        return u;
    for (ll j=lgM-1;j>=0;j--) {
        if (ancestor[u][j]==ancestor[v][j])
            continue;
        u=ancestor[u][j];
        v=ancestor[v][j];
    }
    return ancestor[u][0];
}
vector<ll> getmerged(ll x,ll y,bool a,ll b) {
    if (level[x]<level[y])
        swap(x,y);
 
    ll dis= level[x]-level[y];
    if (a)
        dis++;
    vector<ll>res;
    for (ll i = lgM-1; i >= 0; i--) {
        if ((1<<i)<=dis) {
            dis-= (1<<i);
            res=merge(res,mp[x][i],b);
            x=ancestor[x][i];
        }
    }
    return res;
}
vector<ll> query(ll x,ll y,ll a) {
    ll lca=getLCA(x,y);
    vector<ll> s;
    s=merge(getmerged(x,lca,true,a),getmerged(y,lca,false,a),a);
    return  s;
}
ll dis (ll u,ll v) {
    return level[u]+level[v]-2*level[getLCA(u,v)];
}
void solve() {
        ll n,m,q;
        cin>>n>>m>>q;
    for (ll i=0;i<n-1;i++) {
        ll u,v;
        cin>>u>>v;
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
 
    for (ll i=1;i<=m;i++) {
        ll node;
        cin>>node;
        node--;
        if (mp[node][0].size()<=10)
        mp[node][0].push_back(i);
    }
    ll root =0;
    level[root]=1;
    dfs(root,root);
    while (q--) {
        ll u,v,a;
        cin>>u>>v>>a;
        u--;v--;
        vector<ll>ans=query(u,v,a);
        if(ans.size()<a) {
            cout<<ans.size()<<" ";
            for (auto i:ans) {
                cout<<i<<" ";
            }
        }
        else {
            cout<<a<<" ";
            ll counter=0;
            for (auto i:ans) {
                if (counter==a) break;
                cout<<i<<" ";
                counter++;
            }
        }
        cout<<"\n";
      }
}
int main() {
    Moeen
    ll t;
    // cin>>t;
    t=1;
    lg[1]=0;
    for (ll i=2;i<=1e5;i++) {
        lg[i]=lg[i/2]+1;
    }
    for (ll i=0;i<t;i++) {
        solve();;
    }
    return 0;
}