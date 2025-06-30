class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> nge(n);
        stack<int> st;

        for (int i = 2*n - 1; i >= 0; i--) {
            int realIndex = i%n;
            while (!st.empty() && st.top() <= arr[realIndex]) {
                st.pop();
            }
            if (st.empty()) {
                nge[realIndex] = -1;
            } else {
                nge[realIndex] = st.top();
            }
            st.push(arr[realIndex]);
        }

        return nge;
    }
};