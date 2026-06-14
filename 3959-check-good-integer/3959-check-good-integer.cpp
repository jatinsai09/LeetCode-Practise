class Solution {
public:
    bool checkGoodInteger(int n) {
        int del = 0, t = n;

        while (t) {
            int r = t % 10;
            if (r > 1) {
                del += r * (r - 1);
            }
            t /= 10;
        }

        return del >= 50;
    }
};