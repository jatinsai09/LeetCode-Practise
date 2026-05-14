class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        if (n < 3) {
            return 0;
        }

        int c1 = 0;
        for (auto &c: s) {
            c1 += (c - '0');
        }
        int c0 = n - c1;

        int res = c1 - (s[0] - '0') - (s[n - 1] - '0');
        res = min(res, c0);
        if (c1) {
            res = min(res, c1 - 1);
        }

        return res;
    }
};