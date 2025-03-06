class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int missingNumber,repeatedNumber,sum = 0;
        int expectedSum = (n*n) * ((n*n)+1)/2;
        unordered_map<int,int> freq;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                sum+=grid[i][j];
                freq[grid[i][j]]++;
            }
        }
        for(const pair<int,int>&p:freq){
            if(p.second==2){
                repeatedNumber = p.first;
                break;
            }
        }
        missingNumber = expectedSum - sum + repeatedNumber;
        return {repeatedNumber,missingNumber};
        
    }
};