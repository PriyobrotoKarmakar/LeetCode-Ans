class Solution {
public:
    void solve(string& digits,unordered_map<char,string>& number,vector<string>& ans,string& temp,int i = 0){
        if(i>=digits.length()){
            ans.push_back(temp);
            return;
        }

        char num = digits[i];
        string keys = number[num];
        for(char ele: keys){
            temp.push_back(ele);
            solve(digits,number,ans,temp,i+1);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> number;
        number['2'] ="abc";
        number['3'] ="def";
        number['4'] ="ghi";
        number['5'] ="jkl";
        number['6'] ="mno";
        number['7'] ="pqrs";
        number['8'] ="tuv";
        number['9'] ="wxyz";

        vector<string> ans;
        string temp = "";
        
        solve(digits,number,ans,temp);
        return ans;
    }
};