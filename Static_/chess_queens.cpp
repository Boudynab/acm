#include <iostream>
#include <vector>
using namespace std;
const int SIZE = 8;
vector<string> board(SIZE);
vector<bool> cols(SIZE, false);
vector<bool> diag1(2 * SIZE - 1, false); // Diagonal attacks (/ direction)
vector<bool> diag2(2 * SIZE - 1, false); // Diagonal attacks (\ direction)
int count = 0; 
void placeQueens(int row) {
    if (row == SIZE) {
        count++;
        return;
    }
    for (int col = 0; col < SIZE; col++) {
        if (board[row][col] == '.' && !cols[col] && !diag1[row + col] && !diag2[row - col + SIZE - 1]) {
            cols[col] = diag1[row + col] = diag2[row - col + SIZE - 1] = true;
            placeQueens(row + 1);
            cols[col] = diag1[row + col] = diag2[row - col + SIZE - 1] = false; // backtrack مش فاهم اوي
        }
    }
}
int main() {
    for (int i = 0; i < SIZE; i++) {
        cin >> board[i];
    }
    placeQueens(0);
    cout << count << endl;
    return 0;
}
