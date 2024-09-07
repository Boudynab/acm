#include <bits/stdc++.h>
#define abdo ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int N=2e5+5;
int n;
int sizee[N];
int parent[N]; 
vector<int>cats[N]; 
void make_set(int v) {
    parent[v] = v;
    sizee[v] = 1;
    cats[v].push_back(v);
}
int get(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = get(parent[v]);
}
void join(int a, int b) {
    a = get(a);
    b = get(b);
    if (a != b) {
        if (sizee[a] < sizee[b])
            swap(a, b);
        parent[b] = a;
        sizee[a] += sizee[b];
        // Move all elements from set b to set a
        while (!cats[b].empty()) {
            cats[a].push_back(cats[b].back());
            cats[b].pop_back();
        }
    }
}
int main() {
    abdo;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        make_set(i);
    }
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        join(a, b);
    }
    // Find the leader of the last employee (n) and output the members of their set
    int leader =get(n);
    for (auto i : cats[leader]) {
        cout << i << ' ';
    }
    
}
