class Solution {
public:
    bool consecutiveSetBits(int n) {
        int prev = 0, c = 0;

        while (n) {
            int cur = n & 1;
            if (cur + prev == 2) {
                c++;
            }
            prev = cur;
            n >>= 1;
        }
        return c == 1;
    }
};