class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
     
        map<int,int> freq;
        for (int &ele : nums) {
            freq[ele]++;
        }

        int maxFreq = 0;
        for (auto &p : freq) {
            maxFreq = max(maxFreq, p.second);
        }

   
        int count = 0;
        for (auto &p : freq) {
            if (p.second == maxFreq) {
                count++;
            }
        }

     
        return count * maxFreq;
    }
};
