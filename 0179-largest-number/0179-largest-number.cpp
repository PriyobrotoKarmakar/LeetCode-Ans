class Solution {
public:
    string largestNumber(vector<int>& nums) {
        auto Comparator = [](int& a,int&b){
            string s1 = to_string(a);
            string s2 = to_string(b);
            return s1+s2>s2+s1;
        };
        sort(nums.begin(),nums.end(),Comparator);
        string ans="";
        for(const int& N:nums){
            ans+=to_string(N);
        }
        if(ans[0]=='0'){
            return "0";
        }
        return ans;
    }
};