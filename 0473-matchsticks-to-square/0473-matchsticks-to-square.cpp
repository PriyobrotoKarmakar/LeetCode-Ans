class Solution {
public:
    bool solve(vector<int>& mstks, int& target, vector<int>& side, int idx) {
        
        if (idx >= mstks.size()) {
            if (side[0] == side[1] && side[1] == side[2] && side[2] == side[3])
                return true;
            return false;
        }
        if(mstks[idx]>target) return false;
        for (int i = 0; i < 4; i++) {
            // take
            
            if ((side[i] + mstks[idx]) > target)
                continue;

            side[i] += mstks[idx];

            if (solve(mstks, target, side, idx + 1))
                return true;
            side[i] -= mstks[idx];
        }

        return false;
    }

    bool makesquare(vector<int>& mstks) {
        if (mstks.size() == 0)
            return false;
        sort(mstks.begin(),mstks.end(),greater<int>());
        int sum = 0;
        for (auto ele : mstks)
            sum += ele;
        if (sum % 4 != 0)
            return false;
        int target = sum / 4;
        vector<int> side(4);
        return solve(mstks, target, side, 0);
    }
};