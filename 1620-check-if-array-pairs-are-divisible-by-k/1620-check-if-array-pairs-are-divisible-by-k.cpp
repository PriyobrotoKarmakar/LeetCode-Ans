class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> freq(k,0);
        for (int i = 0; i < arr.size(); i++) {
            freq[((arr[i] % k)+k)%k]++;
        }
        if(freq[0]&1)return false;

        for (int i = 1; i <= k / 2; i++) {
            if (freq[i] != freq[k - i]) {
                return false;
            }
        }
        return true;
    }
};