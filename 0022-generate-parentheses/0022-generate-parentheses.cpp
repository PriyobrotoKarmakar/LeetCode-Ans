class Solution {
public:
    // void solve(int n,string tempAns, int closingBrac,vector<string>& ans){
    //     if(n<0 || closingBrac<0) return;

    //     if(n==0 && closingBrac==0){
    //         ans.push_back(tempAns);
    //         return;
    //     }

    //     solve(n-1,tempAns+'(',closingBrac, ans);
    //     if(closingBrac<n && n!=closingBrac)
    //         solve(n,tempAns+')',closingBrac-1,ans);


    // }
    void solve(string tempAns, int closingBrac,int openingBrac,vector<string>& ans){
        // if(openingBrac<0 || closingBrac<0) return;
        if(openingBrac==0 && closingBrac==0){
            ans.push_back(tempAns);
            return;
        }
        if(openingBrac!=0)
            solve(tempAns+'(',closingBrac,openingBrac-1 ,ans);
        if(closingBrac>openingBrac && closingBrac!=openingBrac)
            solve(tempAns+')',closingBrac-1,openingBrac, ans);

    }

    vector<string> generateParenthesis(int n) {
        string tempAns = "";
        vector<string> ans;
        int closingBrac = n;
        int openingBrac = n;
        solve(tempAns,closingBrac,openingBrac, ans);
        return ans;

    }
};