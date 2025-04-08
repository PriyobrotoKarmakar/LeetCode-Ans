// class Solution {
// public:
//     int dp[1001][1001];
//     int solve(vector<vector<int>>& pairs,int prev,int i){
//         if(i>=pairs.size())return 0;
//         if(prev!=-1 && dp[prev][i]!=-1)return dp[prev][i];
//         int take = 0;
//         if(prev==-1 || pairs[prev][1]<pairs[i][0]){
//             take  = 1 + solve(pairs,i,i+1);
//         }
//         int nonTake = solve(pairs,prev,i+1);

//         if(prev==-1){
//             dp[prev][i] = max(take,nonTake);
//         }
//         return max(take,nonTake);
//     }
//     int findLongestChain(vector<vector<int>>& pairs) {
//         sort(pairs.begin(),pairs.end());
//         memset(dp,-1,sizeof(dp));
//         return solve(pairs,-1,0);
//     }
// };

class Solution {
public:
    int findLongestChain(std::vector<std::vector<int>>& pairs) {
        std::sort(pairs.begin(), pairs.end(),
                  [](const std::vector<int>& a, const std::vector<int>& b) {
                      return a[1] < b[1];
                  });

        int cur = INT_MIN, ans = 0;

        for (const auto& pair : pairs) {
            if (cur < pair[0]) {
                cur = pair[1];
                ans++;
            }
        }

        return ans;
    }
};