class Solution {
public:
    bool isSet(int& x, int& bit) { return x & (1 << bit); }
    void setBit(int& x, int& bit) { x = x | (1 << bit); }
    void unSetBit(int& x, int& bit) { x = x & (~(1 << bit)); }
    int minimizeXor(int num1, int num2) {
        int x = num1;
        int requiredSetBit = __builtin_popcount(num2);
        int currentSetBit = __builtin_popcount(num1);
        int bit = 0;

        if (currentSetBit < requiredSetBit) {
            while (currentSetBit < requiredSetBit) {
                if (!isSet(x, bit)) {
                    setBit(x, bit);
                    currentSetBit++;
                }
                bit++;
            }
        } else if (currentSetBit > requiredSetBit) {
            while (currentSetBit > requiredSetBit) {
                if (isSet(x, bit)) {
                    unSetBit(x, bit);
                    currentSetBit--;
                }
                bit++;
            }
        }

        return x;
    }
};