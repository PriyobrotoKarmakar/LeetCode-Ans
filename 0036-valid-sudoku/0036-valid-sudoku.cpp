class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rowCheck[9], colCheck[9], boxCheck[9];
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c == '.')
                    continue;
                int idx = ((i / 3) * 3) + (j / 3);
                if (rowCheck[i].count(c))
                    return false;
                if (colCheck[j].count(c))
                    return false;
                if (boxCheck[idx].count(c))
                    return false;

                rowCheck[i].insert(c);
                colCheck[j].insert(c);
                boxCheck[idx].insert(c);
            }
        }

        return true;
    }
};