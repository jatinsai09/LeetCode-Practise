class Solution {
public:
    int longestArithmetic(vector<int>& nums) {
        int n = nums.size();

        if (n <= 3) {
            return n;
        }

        vector<int> lc(n, 1), ld(n), rc(n, 1), rd(n);
        lc[0] = 1;
        lc[1] = 2;
        ld[1] = nums[1] - nums[0];

        for (int i = 2; i < n; i++) {
            int d = nums[i] - nums[i - 1];
            if (d == ld[i - 1]) {
                lc[i] += lc[i - 1];
            } else {
                lc[i]++;
            }
            ld[i] = d;
        }

        rc[n - 1] = 1;
        rc[n - 2] = 2;
        rd[n - 2] = nums[n - 1] - nums[n - 2];

        for (int i = n - 3; i >= 0; i--) {
            int d = nums[i + 1] - nums[i];
            if (d == rd[i + 1]) {
                rc[i] += rc[i + 1];
            } else {
                rc[i]++;
            }
            rd[i] = d;
        }

        int res = 3;

        for (int i = 0; i < n; i++) {
            if (i) {
                res = max(res, lc[i - 1] + 1);
            }
            if (i < n - 1) {
                res = max(res, rc[i + 1] + 1);
            }

            if (i && i < n - 1) {
                int t = nums[i + 1] - nums[i - 1];
                if (t % 2 != 0) {
                    continue;
                }

                t /= 2;

                int ll = (i - 1 == 0 || ld[i - 1] != t ? 1 : lc[i - 1]);
                int rr = (i + 1 == n - 1 || rd[i + 1] != t ? 1 : rc[i + 1]);
                res = max(res, ll + rr + 1);
            }
        }

        return res;
    }
};