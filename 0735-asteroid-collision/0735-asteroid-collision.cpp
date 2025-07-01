class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int> st;
        for (int i = 0; i < ast.size(); ++i) {
            int curr = ast[i];
            bool alive = true;
            while (alive && curr < 0 && !st.empty() && st.top() > 0) {
                if (abs(st.top()) < abs(curr)) {
                    st.pop();
                } else if (abs(st.top()) == abs(curr)) {
                    st.pop();
                    alive = false;
                } else {
                    alive = false;
                }
            }
            if (alive) {
                st.push(curr);
            }
        }
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
