#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,t;
    cin >>n>>t;
    vector<int>arr(n);
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    int x=1;
    while(x<t){
        x+=arr[x];
    }
    if(x==t){
        cout << "YES"<< endl;
    }
    else{
        cout << "NO"<< endl;
    }
    
}