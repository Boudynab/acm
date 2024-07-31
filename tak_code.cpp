#include <bits/stdc++.h>
using namespace std;

bool isValidTaKCode(int i,int j,const vector<vector<char>>&grid) {
    if (i+8>=grid.size()||j+8>=grid[0].size()) {
        return false;
    } //Top-left
    for (int x=0;x<3;x++) {
        for (int y=0;y<3;y++) {
            if (grid[i+x][j+y]!='#') {
                return false;
            }
        }
    }
    // Bottom-right
    for (int x=6;x<9;x++) {
        for (int y=6;y<9;y++) {
            if (grid[i+x][j+y]!='#') {
                return false;
            }
        }
    }
    vector<pair<int, int>>whiteCells = {
        {0, 3}, {1, 3}, {2, 3},{3, 0}, {3, 1}, {3, 2}, {3, 3},{5, 5}, {5, 6}, {5, 7}, {5, 8},{6, 5}, {7, 5}, {8, 5}
    };
    for (const auto& cell : whiteCells) {
        if (grid[i+cell.first][j+cell.second]!='.') {
            return false;
        }
    }
    return true;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cin >> grid[i][j];
        }
    }
    vector<pair<int, int>> results;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (isValidTaKCode(i,j,grid)) {
                results.push_back({i+1,j+1});
            }
        }
    }
    for (const auto& result : results) {
        cout<<result.first<< " " <<result.second<<endl;
    }
}
