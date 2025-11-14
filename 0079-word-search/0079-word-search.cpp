class Solution {
public:
bool dfs(vector<vector<char>>& board, int i, int j, string& word, int index) {
        if (index == word.length())
            return true;
        
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[index])
            return false;
        
        char temp = board[i][j];
        board[i][j] = '#'; // mark the cell as visited
        
        bool found = dfs(board, i + 1, j, word, index + 1) ||
                     dfs(board, i - 1, j, word, index + 1) ||
                     dfs(board, i, j + 1, word, index + 1) ||
                     dfs(board, i, j - 1, word, index + 1);
        
        board[i][j] = temp; // restore the cell
        
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (dfs(board, i, j, word, 0))
                    return true;
            }
        }
        return false;
    }
};