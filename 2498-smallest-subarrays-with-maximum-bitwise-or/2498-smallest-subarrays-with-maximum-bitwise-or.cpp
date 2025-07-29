class Solution {
    bool is_set(int num, int pos){
        if((num&(1<<pos)) == 0){return false;}
        return true;
    }
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        vector<int> suf(n);

        // suffix OR
        suf[n-1] = nums[n-1];
        for(int i = n - 2; i >= 0; i--) {
            suf[i] = suf[i + 1] | nums[i];
        }

        int l = 0, r = 0;
        int cur = nums[0];

        vector<int> freq(32, 0);  // freq of each bit

        // initial freq update
        for(int j = 0; j < 32; j++) {
            if(is_set(nums[0], j)) {
                freq[j]++;
            }
        }

        while (l < n) {
            while (r + 1 < n && cur != suf[l]) {
                r++;
                cur |= nums[r];  // update OR

                // update freq of bits
                for(int j = 0; j < 32; j++) {
                    if(is_set(nums[r], j)) {
                        freq[j]++;
                    }
                }
            }

            res[l] = max(1,r - l + 1);

            // now remove nums[l] contribution from cur
            for(int j = 0; j < 32; j++) {
                if(is_set(nums[l], j)) {
                    freq[j]--;
                    if(freq[j] == 0) {
                        cur = cur & (~(1 << j));  // properly unset bit
                    }
                }
            }

            l++;
        }

        return res;
    }
};