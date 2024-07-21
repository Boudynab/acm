#include <bits/stdc++.h>
using namespace std;
int mindiff(const vector<int>&weights,int index,int group1,int group2,int n){
    if(index==n){
        return abs(group1-group2);
    }
    int diff1 = mindiff(weights,index+1,group1+weights[index],group2,n);
    int diff2 = mindiff(weights,index+1,group1,group2+weights[index],n);
    return min(diff1,diff2);
}
int main() {
    int n;
    cin >> n;
    vector<int> weights(n);
    int sum=0;
    for(int i=0;i<n;i++){
        cin >> weights[i];
        sum+=weights[i];
    }
    cout<<mindiff(weights,0,0,0,n)<<endl;
    return 0;
}

