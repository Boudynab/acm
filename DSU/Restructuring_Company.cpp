#include <bits/stdc++.h>
#define abdo ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int maxn = 200005;
int s[maxn], p[maxn];
int nxt[maxn];
int n, q;
int get(int a)
{
	if (p[a] != a) p[a] = get(p[a]);
	return p[a];
}
void unite(int a, int b)
{
	a = get(a);
	b = get(b);
	if (a == b) return;
	if (s[a] < s[b]) swap(a, b);
	p[b] = a;
	if (s[a] == s[b]) s[a]++;
}
int next(int a)
{
	if (get(nxt[a]) == get(a)) nxt[a] = next(nxt[a]);
	return nxt[a];
}
int main () {
    abdo
	cin >> n >> q;
	for (int i = 0; i < n; i++){
		p[i]=i;
		s[i]=0;
		nxt[i]=i+1;
	}
	p[n] = n;
	for (int i = 0; i < q; i++){
		int t, x, y;
		cin >> t >> x >> y;
		x--, y--;
		if (t == 1){
			unite(x, y);
		} else if(t == 2){
		int cur = x;
		while (cur <= y){
			unite(cur, x);
			cur = next(cur);
			}
        } 
            else{
			if (get(x) == get(y)){
                cout << "YES" << endl;
            } 
			else{
                cout << "NO" << endl;
            } 
		}
	}
}