#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k;
vector<string>maze;
vector<vector<bool>>visited;
vector<pair<int,int>>path;
void dfs(int x,int y){
    visited[x][y]=true;
    path.push_back({x,y});
    int dx[]={-1,1,0,0};
    int dy[]={0,0,-1,1};
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=0 && nx<n && ny>=0 && ny<m &&!visited[nx][ny] && maze[nx][ny]!='#'){
            dfs(nx,ny);
        }
    }
}
int main(){
    cin >> n >> m >> k;
    maze.resize(n);
    visited.resize(n,vector<bool>(m,false));
    for(int i=0;i<n;i++){
        cin >> maze[i];
    }
    bool found = false;
    for(int i=0;i<n&&!found;i++){
        for(int j=0;j<m&&!found;j++){
            if(maze[i][j]=='.'){
                dfs(i,j);
                found = true;
            }
        }
    }
    int size=path.size();
    for(int i=0;i<k;i++){
        int x=path[size-i-1].first;
        int y=path[size-i-1].second;
        maze[x][y]='X';
    }
    for(int i=0;i<n;i++){
            cout << maze[i]<< endl;
        }
    }
