class Solution {
public:
    bool isSafe(int row, int col, char digit, vector<vector<char>>& board) {
        for (int k = 0; k < 9; k++) {
            if (board[row][k] == digit) {
                return false;
            }
        }
        for (int k = 0; k < 9; k++) {
            if (board[k][col] == digit) {
                return false;
            }
        }
        for (int k = 0; k < 9; k++) {
            if (board[3 * (row / 3) + k / 3][3 * (col / 3) + k % 3] == digit) {
                return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board) {
        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[0].size(); col++) {
                if (board[row][col] == '.') {

                    for (char digit = '1'; digit <= '9'; digit++) {
                        if (isSafe(row, col, digit, board)) {
                            board[row][col] = digit;
                            bool furtherCheck = solve(board);
                            if (furtherCheck) {
                                return true;
                            } else {
                                board[row][col] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) { solve(board); }
};
