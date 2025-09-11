class Solution {
public:
    int solveUsingMap(vector<int>& nums) {
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

    int LinearSearch(vector<int>& nums){
        vector<int> arr;
        arr.push_back(nums[0]);
        for(int i =1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]){
                arr.push_back(nums[i]);
            }
        }
        nums = arr;
        return nums.size();
    }
    int removeDuplicates(vector<int>& nums) {
        return LinearSearch(nums);
    }
};