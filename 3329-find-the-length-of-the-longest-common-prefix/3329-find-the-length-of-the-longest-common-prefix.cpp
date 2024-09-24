class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        if (arr1.size() > arr2.size()) {
            arr1.swap(arr2);
        }

        unordered_set<string> st;

        
        for (auto num : arr1) {
            string numStr = to_string(num);
            for (int i = 1; i <= numStr.size(); ++i) {
                st.insert(numStr.substr(0, i));
            }
        }

        int res = 0;

        
        for (auto num : arr2) {
            string numStr = to_string(num);
            for (int i = 1; i <= numStr.size(); ++i) {
                string prefix = numStr.substr(0, i);
                if (st.count(prefix)) {
                    res = max(res, (int)prefix.size());
                }
            }
        }

        return res;
    }
};