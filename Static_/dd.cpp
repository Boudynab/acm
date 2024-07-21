#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,s;
    cin >> n >> s;
    vector<int> a(n);
    for(int i=0; i<n; i++){
         cin >> a[i];
    }
    sort(a.begin(), a.end());
    int k=0;
    int t=0;
    int left=0;
    int right=2e9;
    for(int i=1;i<=n;i++){
    while(left<right){
        int mid=left+(right-left)/2;
        if((a[i]+i*k)<=s){
            left=mid+1;
            t=(a[i]+i*k);
        }
        else{
            right=mid;
        }
    } 
    } 
    cout<<k<<" "<<t<<endl;
    return 0;
}