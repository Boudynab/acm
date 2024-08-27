#include <bits/stdc++.h>
using namespace std;
long long bfs(long long n,long long m){
    if(n>=m){
        return n-m;
    }
    queue<pair<long long,long long>>q;
    q.push({n,0});
    unordered_map<long long,bool>visited;
    visited[n]=true;
    while(!q.empty()){
        int current=q.front().first;
        int op=q.front().second;
        q.pop();
        if(current==m){
            return op;
        }
        if(current<m&&!visited[current*2]){
            q.push({current*2,op+1});
            visited[current*2]=true;
        }
        if(current-1>0&&!visited[current-1]){
            q.push({current-1,op+1});
            visited[current-1]=true;
        }
    }
    return -1;
}
int main(){
    long long n,m;
    cin>>n>>m;
    cout<<bfs(n,m)<<endl;
}