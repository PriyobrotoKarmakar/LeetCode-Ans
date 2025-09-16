class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> res;
        for (auto num : nums) {
            while (!res.empty()) {
                int prev = res.back();
                int curr = num;

                int GCD = gcd(prev, curr);
                if (GCD == 1)
                    break;

                int LCM = prev / GCD * curr;
                res.pop_back();
                num = LCM;
            }
            res.push_back(num);
        }
        return res;
    }
};