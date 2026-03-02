class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(auto curr: asteroids){
            bool alive = true;

            while(alive && curr<0 && !st.empty() && st.top()>0){
                //upcoming astroid is larger
                int prev = st.top();
              

                if(prev<abs(curr)){
                    st.pop();
                }else if(prev==abs(curr)){
                    st.pop();
                    alive = false;
                }else{
                    alive = false;
                }
            }

            if(alive){
                st.push(curr);
            }
        }

        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top()); st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};