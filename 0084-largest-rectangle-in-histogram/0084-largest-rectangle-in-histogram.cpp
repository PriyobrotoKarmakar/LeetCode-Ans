class Solution {
public:
    void NextSmaller(vector<int>& heights, vector<int>& nextSmaller) {
        stack<int> st;
        int n = heights.size();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[i] <= heights[st.top()]) {
                st.pop();
            }
            if (st.empty()) {
                nextSmaller.push_back(n);
            } else {
                nextSmaller.push_back(st.top());
            }
            st.push(i);
        }
        reverse(nextSmaller.begin(), nextSmaller.end());
    }

    void PrevSmaller(vector<int>& heights, vector<int>& prevSmaller) {
        stack<int> st;
        int n = heights.size();
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[i] <= heights[st.top()]) {
                st.pop();
            }
            if (st.empty()) {
                prevSmaller.push_back(-1);
            } else {
                prevSmaller.push_back(st.top());
            }
            st.push(i);
        }
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> prevSmaller;  
        vector<int> nextSmaller;  

        NextSmaller(heights, nextSmaller);
        PrevSmaller(heights, prevSmaller);

        long long ans = 0;  
        for (int i = 0; i < n; i++) {
            int prev = prevSmaller[i];
            int next = nextSmaller[i];
            int curr = heights[i];
            long long area = (long long)((next - prev - 1) * curr);
            ans = max(ans, area);
        }

        return ans;
    }
};
