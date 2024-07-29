#include <iostream>
#include <vector>

using namespace std;

// Function to check if the 9x9 subgrid starting at (top_left_i, top_left_j) is a valid TaK Code
bool is_tak_code(const vector<string>& grid, int top_left_i, int top_left_j) {
    // Check top-left 3x3 region
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (grid[top_left_i + i][top_left_j + j] != '#') {
                return false;
            }
        }
    }

    // Check bottom-right 3x3 region
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (grid[top_left_i + 6 + i][top_left_j + 6 + j] != '#') {
                return false;
            }
        }
    }

    // Check adjacent cells to top-left 3x3 region
    for (int i = -1; i <= 3; ++i) {
        for (int j = -1; j <= 3; ++j) {
            if (i == -1 || i == 3 || j == -1 || j == 3) {
                if (grid[top_left_i + i][top_left_j + j] != '.') {
                    return false;
                }
            }
        }
    }

    // Check adjacent cells to bottom-right 3x3 region
    for (int i = 6; i <= 9; ++i) {
        for (int j = 6; j <= 9; ++j) {
            if (i == 6 || i == 9 || j == 6 || j == 9) {
                if (grid[top_left_i + i][top_left_j + j] != '.') {
                    return false;
                }
            }
        }
    }

    return true;
}

// Function to find all valid TaK Codes in the grid
vector<pair<int, int>> find_tak_codes(int N, int M, const vector<string>& grid) {
    vector<pair<int, int>> results;
    for (int i = 0; i <= N - 9; ++i) {
        for (int j = 0; j <= M - 9; ++j) {
            if (is_tak_code(grid, i, j)) {
                results.emplace_back(i + 1, j + 1); // Convert to 1-based index
            }
        }
    }
    return results;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> grid(N);
    for (int i = 0; i < N; ++i) {
        cin >> grid[i];
    }

    vector<pair<int, int>> results = find_tak_codes(N, M, grid);
    for (const auto& result : results) {
        cout << result.first << " " << result.second << endl;
    }

    return 0;
}
