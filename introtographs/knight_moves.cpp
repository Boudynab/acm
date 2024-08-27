#include <bits/stdc++.h>
using namespace std;
int dx[]={2,2,-2,-2,1,1,-1,-1};
int dy[]={1,-1,1,-1,2,-2,2,-2};
pair<int,int>covert(string x){
    int row=x[0]-'a';
    int col=x[1]-'1';
    return make_pair(row,col);
}
int bfs(pair<int,int> start,pair<int,int> end){
    if(start==end){
        return 0;
    }
    queue<pair<int,int>>q;
    int visted[8][8];
    memset(visted,-1,sizeof(visted));
    q.push(start);
    visted[start.first][start.second]=0;
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<8;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0&&nx<8&&ny>=0&&ny<8&&visted[nx][ny]==-1){
                visted[nx][ny]=visted[x][y]+1;
                if(nx==end.first&&ny==end.second){
                    return visted[nx][ny];
                }
                q.push({nx,ny});
            }
        }
    }
    return -1;
}
int main(){
    string start,end;
     while (cin >> start >> end) {
        auto start_pos = covert(start);
        auto end_pos = covert(end);
        int moves = bfs(start_pos, end_pos);
        cout<<"To get from "<<start<<" to "<<end<<" takes "<<moves<<" knight moves."<< endl;
    }
}

