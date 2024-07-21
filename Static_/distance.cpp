#include <bits/stdc++.h>
using namespace std;

int main(){
    int q,d;
    cin>>q>>d;
    int count = 0;
    long long d_squared=(long long)d*d;
    while(q--){
        int x,y;
        cin>>x>>y;
        long long distance_squared=(long long)x*x+(long long)y*y;
        if(distance_squared<=d_squared){
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}