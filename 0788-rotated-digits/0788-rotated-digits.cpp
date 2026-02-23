class Solution {
public:
    int rotatedDigits(int n) {
        set<int> valid = {0, 1, 2, 5, 6, 8, 9};
        set<int> can = {2, 5, 6, 9};
        int res = 0;

        for (int i = 1; i <= n; i++) {
            int t = i, f = 1;
            while (t) {
                int r = t % 10;
                if (!valid.count(r)) {
                    f = 0;
                    break;
                }
                if (can.count(r)) {
                    f = 2;
                }
                t /= 10;
            }

            if (f == 2) {
                res++;
            }
        }

        return res;
    }
};