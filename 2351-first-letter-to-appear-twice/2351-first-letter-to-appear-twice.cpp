class Solution {
public:
    char repeatedCharacter(string s) {
        int mask = 0;  
        for (char ch : s) {
            int val = ch - 'a';
            if ((mask >> val) & 1) {
                return ch;
            }
            mask |= (1 << val);
        }
        return ' ';
    }
};