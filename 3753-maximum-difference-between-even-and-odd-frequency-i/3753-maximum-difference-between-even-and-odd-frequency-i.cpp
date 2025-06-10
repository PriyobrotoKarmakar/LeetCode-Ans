class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        int maxOdd = -1;
        int minEven = 101;

        for (int count : freq) {
            if (count > 0) {
                if ((count & 1) == 1 && count > maxOdd) {
                    maxOdd = count;
                }
                if ((count & 1) == 0 && count < minEven) {
                    minEven = count;
                }
            }
        }

        return maxOdd - minEven;
    }
};