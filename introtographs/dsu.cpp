#include <bits/stdc++.h>
#define abdo ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using namespace std;

// Global variables for DSU
vector<int> parent, rank, max_element, min_element, set_size;

// Function to find the root of the set containing u with path compression
int find(int u) {
    if (parent[u] != u) {
        parent[u] = find(parent[u]); // Path compression
    }
    return parent[u];
}

// Function to unite the sets containing u and v
void dsu(int u, int v) {
    int leader_u = find(u);
    int leader_v = find(v);
    
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

// Function to get the minimum element, maximum element, and size of the set containing u
tuple<int, int, int> get(int u) {
    int leader_u = find(u);
    return make_tuple(min_element[leader_u] + 1, max_element[leader_u] + 1, set_size[leader_u]);
}

int main() {
    abdo
    int n, q;
    cin >> n >> q;
    
    // Initialize DSU directly in main
    parent.resize(n);
    rank.resize(n, 0);
    min_element.resize(n);
    max_element.resize(n);
    set_size.resize(n, 1);
    
    for (int i = 0; i < n; ++i) {
        parent[i] = i;         // Each element is its own parent initially
        min_element[i] = i;    // The minimum element in its own set is itself
        max_element[i] = i;    // The maximum element in its own set is itself
    }
    
    for (int i = 0; i < q; i++) {
        string s;
        cin >> s;
        if (s == "union") {
            int u, v;
            cin >> u >> v;
            dsu(u - 1, v - 1);
        } else if (s == "get") {
            int u;
            cin >> u;
            auto [min_elem, max_elem, set_size] = get(u - 1);
            cout << min_elem << " " << max_elem << " " << set_size << endl;
        }
    }

    return 0;
}
