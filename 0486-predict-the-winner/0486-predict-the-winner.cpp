class Solution {
public:
    bool solve(vector<int>& nums, int i, int j, int scoreA, int scoreB,
               bool chance) {

        if (j < i) {
            return scoreA >= scoreB;
        }
        // take the first element;
        
        if (chance) {
                bool take = solve(nums, i + 1, j, scoreA + nums[i], scoreB, false);
                bool nontake =
                    solve(nums, i, j - 1, scoreA + nums[j], scoreB, false);
                return take || nontake;
        } else {
                bool take = solve(nums, i + 1, j, scoreA, scoreB + nums[i], true);
                bool nontake = solve(nums, i, j - 1, scoreA, scoreB + nums[j], true);
                return take && nontake;
        }
        return false;
    }
    bool predictTheWinner(vector<int>& nums) {
        int scoreA = 0;
        int scoreB = 0;
        int n = nums.size();
        return solve(nums, 0, n - 1, scoreA, scoreB, true);
    }
};