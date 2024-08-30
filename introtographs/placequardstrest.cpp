#include <bits/stdc++.h>
#define ll long long
#define Moeen ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
bool visited [(ll)200];
vector <ll> v[(ll)200] ;
vector <ll> color((ll)200,2);
bool flag =true;
ll c[2]= {0,0};
void dfs(ll i)
{
    visited[i]=1;
    for (auto x:v[i])
    {
        if (!visited[x])
        {
            color[x]=!color[i];
            c[color[x]]++;
            dfs(x);
        }
        else if (color[x]==color[i])
        {
            flag =false;
        }
    }

}

int main()
{
    Moeen
    ll t;
    cin>>t;
    while (t--)
    {
        ll u,e;
        cin>>u>>e;
        for(ll i=0; i<u; i++)
        {
            v[i].clear();
            visited[i]=false;
            color[i]=2;
        }
        flag=true;
        for (ll i=0; i<e; i++)
        {
            ll x,y;
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        ll cnt=0;
        for (ll i=0; i<u; i++)
        {
            if (!visited[i])
            {
                c[0]=1;
                c[1]=0;
                color[i]=0;
                dfs(i);
                cnt+=min(c[0],c[1]);
                if (c[0]+c[1]==1)
                    cnt++;
            }
        }
        if (flag)
        {
            cout<<cnt<<"\n";
        }
        else
        {
            cout<<"-1\n";
        }

    }
    return 0;
}