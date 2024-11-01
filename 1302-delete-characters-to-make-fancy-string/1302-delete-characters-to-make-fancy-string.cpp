class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        for (int i=0;i<s.length();i++){
            char currChar = s[i];
            if(ans.length()!=0 and ans[ans.size()-1]==currChar){
                char temp = ans[ans.size()-1];
                ans.pop_back();
                if(ans.length()!=0 and ans[ans.size()-1]==currChar){
                    ans.pop_back();
                }
                ans.push_back(temp);
            }
            ans.push_back(currChar);
        }
        return ans;
    }
};