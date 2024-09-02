#include <bits/stdc++.h>
#define abdo ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int find(int u, vector<int>& parent) {
    if (parent[u] != u) {
        parent[u] = find(parent[u], parent);
    }
    return parent[u];
}
void dsu(int u,int v,vector<int>&parent,vector<int>&rank,vector<int>&min_element,vector<int>&max_element,vector<int>&set_size) {
    int leader_u = find(u, parent);
    int leader_v = find(v, parent);
    if (leader_u != leader_v) {
        if (rank[leader_u] > rank[leader_v]) {
            parent[leader_v] = leader_u;
            min_element[leader_u] = min(min_element[leader_u], min_element[leader_v]);
            max_element[leader_u] = max(max_element[leader_u], max_element[leader_v]);
            set_size[leader_u] += set_size[leader_v];
        } else {
            parent[leader_u] = leader_v;
            min_element[leader_v] = min(min_element[leader_u], min_element[leader_v]);
            max_element[leader_v] = max(max_element[leader_u], max_element[leader_v]);
            set_size[leader_v] += set_size[leader_u];
            if (rank[leader_u] == rank[leader_v]) {
                rank[leader_v]++;
            }
        }
    }
}
tuple<int, int, int> get(int u, vector<int>& parent, vector<int>& min_element, vector<int>& max_element, vector<int>& set_size) {
    int leader_u = find(u, parent);
    return make_tuple(min_element[leader_u]+1,max_element[leader_u]+1,set_size[leader_u]);
}
int main() {
    abdo
    int n, q;
    cin >> n >> q;
    vector<int>parent(n),rank(n,0),min_element(n),max_element(n),set_size(n,1);
    for (int i = 0; i < n; ++i) {
        parent[i] = i;         
        min_element[i] = i;    
        max_element[i] = i;  
    }
    for (int i=0;i<q;i++) {
        string s;
        cin >> s;
        if (s=="union") {
            int u, v;
            cin >> u >> v;
            dsu(u-1,v-1,parent,rank,min_element,max_element,set_size);
        } else if (s=="get") {
            int u;
            cin >> u;
        auto result = get(u - 1,parent,min_element,max_element,set_size);
        int min_elem = std::get<0>(result);
        int max_elem = std::get<1>(result);
        int set_size = std::get<2>(result);
            cout <<min_elem <<" "<<max_elem<<" "<< set_size<<endl;
        }
    }
}
