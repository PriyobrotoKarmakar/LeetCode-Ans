class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int>minutes;
        for(auto time :timePoints){
            string hourSubstr = time.substr(0,2);
            string minSubstr = time.substr(3);
            int min = (60*stoi(hourSubstr)+stoi(minSubstr));
            minutes.push_back(min);
        }
        sort(minutes.begin(),minutes.end());
        int result = INT_MAX;
        for(int i=1;i<minutes.size();i++){
            result = min(result,minutes[i]-minutes[i-1]);
        }

        return min(result,(24*60-minutes[minutes.size()-1]+minutes[0]));
    }
};