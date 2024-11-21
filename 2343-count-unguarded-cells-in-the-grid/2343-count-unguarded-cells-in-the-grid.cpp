class Solution {
public:
    void DOWN(vector<vector<char>>&matrix,int i,int j){
        i++;
        while(i<matrix.size()){
            if(matrix[i][j]=='W' || matrix[i][j]=='G' )
                break;
            matrix[i][j] = '1';
            i++;
        }
    }
    void UP(vector<vector<char>>&matrix,int i,int j){
        i--;
        while(i>=0){
            if(matrix[i][j]=='W' || matrix[i][j]=='G')
                break;
            matrix[i][j] = '1';
            i--;
        }
    }
    void LEFT(vector<vector<char>>&matrix,int i,int j){
        j--;
        while(j>=0){
            if(matrix[i][j]=='W' || matrix[i][j]=='G')
                break;
            matrix[i][j] = '1';
            j--;
        }
    }
    void RIGHT(vector<vector<char>>&matrix,int i,int j){
        j++;
        while(j<matrix[0].size()){
            if(matrix[i][j]=='W' || matrix[i][j]=='G')
                break;
            matrix[i][j] = '1';
            j++;
        }
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<char>>matrix(m,vector<char>(n,'0'));
        for(int i=0;i<guards.size();i++){
            int x = guards[i][0];
            int y = guards[i][1];
            matrix[x][y] = 'G';
        }
        for(int i=0;i<walls.size();i++){
            int x = walls[i][0];
            int y = walls[i][1];
            matrix[x][y] = 'W';
        }

        for(auto g: guards){
            int i = g[0],j = g[1];
                    UP(matrix,i,j);
                    DOWN(matrix,i,j);
                    LEFT(matrix,i,j);
                    RIGHT(matrix,i,j);
            
        }
        int count =0;
        for(auto row: matrix){
            for(auto ele: row){
                if(ele=='0')
                    count++;
            }
        }
        return count;
    }
};