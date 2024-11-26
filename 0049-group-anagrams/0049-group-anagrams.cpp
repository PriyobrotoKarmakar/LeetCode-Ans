class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> map;
        for(auto str: strs){
            string ogstr = str;
            sort(str.begin(),str.end());
            map[str].push_back(ogstr);
        }
        vector<vector<string>>ans;
        for(auto pair : map){
            ans.push_back(pair.second);
        }
        return ans;
    }
};