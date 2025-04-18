class Solution {
public:
    unordered_map<int, bool> rowCheck;
    unordered_map<int, bool> upperDiagonalCheck;
    unordered_map<int, bool> lowerDiagonalCheck;
    bool isSafe(int& row, int& col) {
        // row check
        if (rowCheck[row])
            return false;
        // upper diagonal check
        if (upperDiagonalCheck[row + col])
            return false;
        // lower diagonal check
        if (lowerDiagonalCheck[row - col])
            return false;

        return true;
    }
    int numberOfQueens = 0;
    void solve(int col, int& ans, int n) {
        if (col >= n && numberOfQueens==n) {
            ans++;
            return;
        }
        for (int row = 0; row < n; row++) {
            if (isSafe(row, col)) {
                rowCheck[row] = true;
                upperDiagonalCheck[row + col] = true;
                lowerDiagonalCheck[row - col] = true;
                numberOfQueens++;
                solve(col + 1, ans, n);
                rowCheck[row] = false;
                upperDiagonalCheck[row + col] = false;
                lowerDiagonalCheck[row - col] = false;
                numberOfQueens--;
            }
        }
    }
    int totalNQueens(int n) {
        int ans= 0;
        solve(0,ans,n);
        return ans;
    }
};