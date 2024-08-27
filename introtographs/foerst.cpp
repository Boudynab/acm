#include <bits/stdc++.h>
using namespace std;
int n,m,k;
vector<vector<bool>>visited;
queue<pair<int,int>>q;
pair<int,int>result;
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
void bfs(){
    while(!q.empty()){
        int x,y,nx,ny;
        x=q.front().first;
        y=q.front().second;
        q.pop();
        visited[x][y]=true;
        result.first=x;
        result.second=y;
        for(int i=0;i<4;i++){
            nx=x+dx[i];
            ny=y+dy[i];
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&!visited[nx][ny]){
                visited[nx][ny]=true;
                q.push(make_pair(nx,ny));  
       }
    }
}
}
int main(){
    cin >> n >> m;
    cin >> k;
    visited.resize(n,vector<bool>(m,false));
    while(k--){
        int x,y;
        cin >> x >> y;
        x--;
        y--;
        q.push(make_pair(x,y));
        visited[x][y]=true;
    }
    bfs();
cout<<result.first+1<<" "<< result.second+1 <<endl;
}



