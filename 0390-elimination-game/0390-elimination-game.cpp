class Solution {
public:
    void shrink(int& i, int& j, int jump, bool& isLeft) {
        int len = (j - i) / jump + 1;
        if (isLeft) {
            if (len % 2 == 0) {
                i = i + jump;
            } else {
                i = i + jump;
                j = j - jump;
            }
            isLeft = false;
        } else {
            if (len % 2 == 0) {
                j = j - jump;
            } else {
                i = i + jump;
                j = j - jump;
            }
            isLeft = true;
        }
    }

    int lastRemaining(int n) {
        int i = 1;
        int j = n;
        int jump = 1;
        bool isLeft = true;

        while (i < j) {
            shrink(i, j, jump, isLeft);
            jump *= 2;
        }

        return i; 
    }
};
