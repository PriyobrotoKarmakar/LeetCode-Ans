class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> result;

        for (int i = 0; i <= n - k; i++) {
            unordered_map<int, int> freqMap;
            for (int j = i; j < i + k; j++) {
                freqMap[nums[j]]++;
            }
            map<int, vector<int>, greater<int>> freqSortedMap;
            for (const auto& entry : freqMap) {
                freqSortedMap[entry.second].push_back(entry.first);
            }

            vector<int> topElements;
            for (auto& entry : freqSortedMap) {
                auto& elements = entry.second;
                sort(elements.rbegin(), elements.rend());
                for (int num : elements) {
                    topElements.push_back(num);
                    if (topElements.size() >= x)
                        break;
                }
                if (topElements.size() >= x)
                    break;
            }

            int xSum = 0;
            for (int num : topElements) {
                xSum += num * freqMap[num];
            }

            result.push_back(xSum);
        }

        return result;
    }
};
