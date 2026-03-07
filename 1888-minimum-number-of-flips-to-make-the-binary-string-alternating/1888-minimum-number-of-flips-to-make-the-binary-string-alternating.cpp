class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        s += s;

        string p1, p2;
        for (int i = 0; i < 2 * n; i++) {
            if (i & 1) {
                p1 += '1';
                p2 += '0';
            } else {
                p1 += '0';
                p2 += '1';
            }
        }

        int res = n, l = 0;
        int c1 = 0, c2 = 0;
        for (int r = 0; r < 2 * n; r++) {
            c1 += (s[r] != p1[r]);
            c2 += (s[r] != p2[r]);

            if (r >= n) {
                c1 -= (s[l] != p1[l]);
                c2 -= (s[l] != p2[l]);
                l++;
            }

            if (r >= n - 1) {
                res = min({res, c1, c2});
            }
        }

        return res;
    }
};