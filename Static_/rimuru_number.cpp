#include <bits/stdc++.h>
using namespace std;

int countnumber(long long n){
    queue<string>q;
    q.push("2");
    q.push("3");
    int count=0;
    while(!q.empty()){
        string current =q.front();
        q.pop();
        long long number=stoll(current);
        if(number<=n){
        count++;
        q.push(current + "2");
        q.push(current + "3");

        }
    }
    return count;
}
int main() {
    long long n;
    cin >>n;
    cout<<countnumber(n)<<endl;
    return 0;
}