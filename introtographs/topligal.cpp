#include <bits/stdc++.h>
using namespace std;
vector<int>ans;
void Topologicl(int n,int m){
    priority_queue<int, vector<int>, greater<int>>pq;
    vector<vector<int>>graph(n+1);
    vector<int>degree(n+1,0);
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        degree[v]++;
    }
    for(int i=1;i<=n;i++){
        if(degree[i]==0){
            pq.push(i);
        }
    }
    while(!pq.empty()){
        int u=pq.top();
        pq.pop();
        ans.push_back(u);
        for(auto &v : graph[u]){
           degree[v]--;
           if(degree[v]==0){
                pq.push(v);

           }
    }          
}
  if (ans.size() == n) {
        for (int i = 0; i < n; i++) {
            if (i > 0) cout << " ";
            cout << ans[i];
        }
        cout << endl;
    } else {
        cout << "Sandro fails." << endl;
    }
}
int main(){
    int n,m;
    cin >> n >> m;
    Topologicl(n,m);
    return 0;
}