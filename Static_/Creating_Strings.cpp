#include <bits/stdc++.h>
using namespace std;

void getpreumentions(string &s,int l,int r,set<string> &results){
    if(l==r) results.insert(s);
    else{
        for(int i=l;i<=r;i++){
            swap(s[l],s[i]);
            getpreumentions(s,l+1,r,results);
            swap(s[l], s[i]);
        }
    }
}
 int main(){
    string s;
    cin >> s;
    set<string> results;
    getpreumentions(s,0,s.size()-1,results);
    cout<<results.size()<<endl;
    for(auto &str: results) cout<<str<<endl;
    return 0;
 }