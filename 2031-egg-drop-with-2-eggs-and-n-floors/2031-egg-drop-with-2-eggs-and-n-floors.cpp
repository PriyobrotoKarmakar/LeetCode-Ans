class Solution {
public:
    int twoEggDrop(int n) {
        int x = 1;
        while (true) {
            if (x * (x + 1) / 2 >= n)
                return x;
            else
                x++;
        }
        return 1;
    }
};