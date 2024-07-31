#include <bits/stdc++.h>
using namespace std;
long long dp[105][100005];
long long rec(vector<int>&wight, vector<int>&values,int w,int W){
    if(w==0||W==0){
        return 0;
    }
    if(dp[w][W]!=-1){
        return dp[w][W];
    }
    long long c1=rec(wight,values,w-1,W);
    long long c2=0;
    if(W>=wight[w-1]){
     c2=rec(wight,values,w-1,W-wight[w-1])+values[w-1];
    }
    return dp[w][W]=max(c1,c2);
}
int main(){
    int  N,W;
    cin >>N>>W;
    vector<int>wight(N);
    vector<int>values(N);
    for(int i=0;i<N;i++){
        cin>>wight[i]>>values[i];
    }
    memset(dp,-1,sizeof(dp)); // هام
    cout << rec(wight,values,N,W) << endl; 
}
