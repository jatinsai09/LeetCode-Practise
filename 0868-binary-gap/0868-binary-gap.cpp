class Solution {
public:
    int binaryGap(int n) {
        int res = 0, c = 0, f = 0;

        int t = n;

        while (t) {
            if (t & 1) {
                if (f) {
                    res = max(res, c + 1);
                }
                c = 0;
                f = 1;
            } else {
                c++;
            }
            t /= 2;
        }

        return res;
    }
};