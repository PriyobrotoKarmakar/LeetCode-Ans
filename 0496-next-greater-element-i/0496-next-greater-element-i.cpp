class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int, int> mpp;
        stack<int> st;
        int n = nums2.size();

        for (int i = n - 1; i >= 0; i--) {
            int current = nums2[i];

            while (!st.empty() && st.top() <= current) {
                st.pop();
            }

            if (st.empty()) {
                mpp[current] = -1;
            } else {

                mpp[current] = st.top();
            }

            st.push(current);
        }

        vector<int> ans;
        for (int num : nums1) {
            ans.push_back(mpp[num]);
        }

        return ans;
    }
};