class Solution {
public:
    unordered_map<int,bool>rowCheck;
    unordered_map<int,bool>upperDiagonalCheck;
    unordered_map<int,bool>lowerDiagonalCheck;
    void storeAns(vector<vector<string>>&ans,vector<vector<char>>&board,int n){
        vector<string> singleSolution;
        for(int row =0;row<n;row++){
            string singleRow = "";
            for(int col = 0;col<n;col++){
                singleRow+=board[row][col];
            }
            singleSolution.push_back(singleRow);
        }
        ans.push_back(singleSolution);
    }
    bool isSafe(int& row, int& col){
        //row check
        if(rowCheck[row])return false;
        //upper diagonal check
        if(upperDiagonalCheck[row+col])return false;
        //lower diagonal check
        if(lowerDiagonalCheck[row-col])return false;

        return true;
    }
    void solve(int col,vector<vector<string>>&ans,vector<vector<char>>&board,int n){
            if(col>=n){
                storeAns(ans,board,n);
                return;
            }
            for(int row= 0;row<n;row++){
                if(isSafe(row,col)){
                    board[row][col] = 'Q';
                    rowCheck[row] = true;
                    upperDiagonalCheck[row+col] = true;
                    lowerDiagonalCheck[row-col] = true;
                    solve(col+1,ans,board,n);
                    board[row][col] = '.';
                    rowCheck[row] = false;
                    upperDiagonalCheck[row+col] = false;
                    lowerDiagonalCheck[row-col] = false;
                }
            }

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<char>>board(n,vector<char>(n,'.'));
        int col = 0;
        solve(col,ans,board,n);
        return ans;
    }
};