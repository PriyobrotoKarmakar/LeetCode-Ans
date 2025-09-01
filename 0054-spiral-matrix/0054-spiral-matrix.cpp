class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int id=0;
        int left = 0;
        int right = matrix[0].size()-1;
        int up = 0;
        int down = matrix.size()-1;
        int index =0;
        int row = matrix.size();
        int col = matrix[0].size();
        while(up<=down and left<=right){
            if(id==0){
                for(int i=left;i<=right;i++){
                    ans.push_back(matrix[up][i]);
                }
                up++;
            }
            else if(id==1){
                for(int i=up;i<=down;i++){
                    ans.push_back(matrix[i][right]);
                }
                right--;
            }
            else if(id==2){
                for(int i=right;i>=left;i--){
                    ans.push_back(matrix[down][i]);
                }
                down--;
            }
            else{
                for(int i=down;i>=up;i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
            id = (id+1)%4;
            // index++;
        }
        return ans;
    }
};