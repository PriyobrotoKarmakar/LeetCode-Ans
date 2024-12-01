class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int,int>exit;
        for(auto ele: arr){
            if(exit.count(ele*2))
                return true;
            else if((ele&1)==0 && exit.count(ele/2))
                return true;
            else
                exit[ele]++;
        }
        return false;
    }
};