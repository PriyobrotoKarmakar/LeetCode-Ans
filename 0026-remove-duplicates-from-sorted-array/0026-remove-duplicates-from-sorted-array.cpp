class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int, bool> visited;
        int i = 0;
        int size = nums.size();
        while (i < size) {
            if (visited[nums[i]]) {
                nums.erase(nums.begin() + i);
                size = nums.size();
                continue;
            }
            visited[nums[i]] = true;
            i++;
        }

        return nums.size();
    }
};