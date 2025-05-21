class Solution {
public:
    void zero(vector<vector<int>>& matrix,int row,int col){
        for(int c=0;c<matrix[0].size();c++){
            matrix[row][c]=0;
        }
        for(int r=0;r<matrix.size();r++){
            matrix[r][col]=0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> v;
        v = matrix;
        for(int row = 0;row<matrix.size();row++){
            for(int col =0;col<matrix[0].size();col++){
                if(v[row][col]==0){
                    zero(matrix,row,col);
                }
            }
        }
    }
};