class Solution {
public:
    vector<int> sumZero(int n) {
        // 1 -> 0
        // 2 -> 1 -1
        // 3 -> 1 0 -1
        // 4 -> -2 -1 1 2
        // 5 -> -2 -1 0 1 -2
        vector<int> ans;
        int start = -(n / 2);
        int end = n / 2;

        for (int i = start; i <= end; i++) {
            if (i == 0)
                if ((n & 1))
                    ans.push_back(i);
                else
                    continue;
            else
                ans.push_back(i);
        }

        return ans;
    }
};