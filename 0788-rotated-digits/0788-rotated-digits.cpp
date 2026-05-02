class Solution {
public:
    int rotatedDigits(int n) {
        set<int> valid = {0, 1, 2, 5, 6, 8, 9};
        set<int> can = {2, 5, 6, 9};
        int res = 0;

        for (int i = 1; i <= n; i++) {
            int t = i, f = 1;
            while (t) {
                if (!valid.count(t % 10)) {
                    f = 0;
                    break;
                }
                if (can.count(t % 10)) {
                    f = 2;
                }
                t /= 10;
            }

            res += (f == 2);
        }

        return res;
    }
};