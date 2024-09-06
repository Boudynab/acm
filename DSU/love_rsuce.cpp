#include <bits/stdc++.h>
#define abdo ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int N=300;
int sizee[N];
int parent[N];
bool found[N];
vector<int>employee[N];
void make_set(int v) {
    parent[v] = v;
    sizee[v] = 1;
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
    }
}
int main() {
        abdo;
        int n;
        string s,k;
        cin>>n>>s>>k;
        vector<pair<int,int>>result;
        for(int i='a';i<='z';i++){
           make_set(i);
         }
        for(int i=0;i<n;i++){
            int a=s[i];
            int b=k[i];
            if(get(a)!=get(b)){
                join(a,b);
                result.push_back({a,b});
            }
        }
        cout<<result.size()<<endl;
        for(auto i:result){
            cout<<(char)i.first<<" "<<(char)i.second<<endl;
        }
   }