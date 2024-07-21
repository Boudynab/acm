#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,h,x;
    cin>>n>>h>>x;
    vector<int>potions(n);
    for(int i=0; i<n; i++){
        cin>>potions[i];
    }
    int count = 0;
    for(int i=0;i<n;i++){
        if(potions[i]+h>=x) {
           count +=i+1;
           break;
        }
  }
  cout<<count<<endl;
    return 0;
}

