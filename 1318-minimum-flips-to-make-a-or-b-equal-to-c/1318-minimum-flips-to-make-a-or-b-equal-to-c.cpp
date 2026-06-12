class Solution {
public:
    int minFlips(int a, int b, int c) {
        int res = 0;

        for (int k = 31; k >= 0; k--) {
            int a1 = (a >> k) & 1;
            int b1 = (b >> k) & 1;
            int c1 = (c >> k) & 1;

            if (c1 != (a1 | b1)) {
                res += a1 + b1 + c1;
            }
        }

        return res;
    }
};