#include <bits/stdc++.h>
using namespace std;
bool isValidTaKCode(int x, int y, const vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    //top-left
    for (int i=x;i<x+3;i++) {
        for (int j=y;j<y+3;j++) {
            if (i>=n||j>=m||grid[i][j]!='#'){
                return false;
        }
}
    }
    //bottom-right
    for (int i=x+6;i<x+9;i++) {
        for (int j=y+6;j<y+9;j++) {
            if (i>=n||j>=m||grid[i][j]!='#'){
                return false;
        }
}
    }
    //top-left
    for (int i=x-1;i<=x+3;i++) {
        for (int j=y-1; j<=y+3;j++) {
            if (i>=0&&i<n&&j>=0&&j<m) {
                if(!(i>=x&&i<x+3&&j>=y&&j<y+3)) {
                    if(grid[i][j]!='.'){
                        return false;
                }
                }
            }
        }
    }
    //bottom-right
    for (int i=x+5;i<=x+9;i++) {
        for (int j=y+5;j<=y+9;j++) {
            if (i>=0&&i<n&&j>=0&&j<m) {
                if (!(i>=x+6&&i<x+9&&j>=y+6&&j<y+9)) {
                    if (grid[i][j]!='.'){
                    return false;
                }
                }
            }
        }
    }
    return true;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
    vector<pair<int, int>> results;
    for (int i=10;i<n;i++) {
        for (int j =0;j<m;j++) {
            if (isValidTaKCode(i, j, grid)) {
                results.push_back({i + 1,j + 1});
            }
        }
    }
    for (const auto& result : results) {
        cout << result.first<<" "<<result.second<<endl;
    }
    return 0;
}
