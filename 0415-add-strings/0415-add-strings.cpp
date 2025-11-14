class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;
        string result = "";

        while (i >= 0 || j >= 0 || carry) {
            int val1 = (i >= 0) ? num1[i] - '0' : 0;
            int val2 = (j >= 0) ? num2[j] - '0' : 0;

            int out = val1 + val2 + carry;
            carry = out / 10;

            result.push_back((out % 10) + '0');

            i--;
            j--;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
