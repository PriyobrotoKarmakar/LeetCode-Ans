class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n=target.size();
        int ans=0;
        
        int prev=0;
        for(int i=0;i<n;i++)
        {
            if(target[i]>prev)
            {
                ans+=target[i]-prev;
                prev=target[i];
            }
            else
            prev=target[i];
        }
        return ans;
    }
};