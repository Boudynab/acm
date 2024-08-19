#include <bits/stdc++.h>
typedef long long ll;
#define size 100005
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
using namespace std;
vector<ll> graph[size];
bool visited[size];
void dfs(ll l){
    visited[l]=true;
    for(auto u:graph[l]){
        if(!visited[u]){
            dfs(u);
        }
    }
}
int main(){
    ll n;
    cin >> n;
    for(ll i=0;i<n;i++){
       ll x;
       cin >> x;
       x--;
       graph[x].push_back(i);
       graph[i].push_back(x);
    }
    ll ans=0;
    for(ll i=0;i<n;i++){
        if(!visited[i]){
            dfs(i);
            ans++;
        }
}
    cout << ans << endl;
}