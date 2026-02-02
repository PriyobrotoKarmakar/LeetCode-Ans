class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        long long currentSum = 0;
        int target = k - 1;
        multiset<int> L, R;
        
        for (int i = 1; i <= dist + 1 && i < nums.size(); ++i) {
            L.insert(nums[i]);
            currentSum += nums[i];
            if (L.size() > target) {
                auto it = prev(L.end());
                currentSum -= *it;
                R.insert(*it);
                L.erase(it);
            }
        }
        
        long long minSum = currentSum;
        
        for (int i = dist + 2; i < nums.size(); ++i) {
            int out = nums[i - dist - 1];
            int in = nums[i];
            
            auto it = L.find(out);
            if (it != L.end()) {
                currentSum -= out;
                L.erase(it);
                if (!R.empty()) {
                    int val = *R.begin();
                    R.erase(R.begin());
                    L.insert(val);
                    currentSum += val;
                }
            } else {
                R.erase(R.find(out));
            }
            
            L.insert(in);
            currentSum += in;
            if (L.size() > target) {
                auto last = prev(L.end());
                currentSum -= *last;
                R.insert(*last);
                L.erase(last);
            }
            
            minSum = min(minSum, currentSum);
        }
        
        return minSum + nums[0];
    }
};