class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> suf(n);
        suf[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suf[i] = piles[i] + suf[i + 1];
        }

        vector<vector<int>> dp(n, vector<int>(n, -1));

        function<int(int, int)> f = [&](int i, int m) -> int {
            if (i == n) {
                return 0;
            }
            if (i + 2 * m >= n) {
                return suf[i];
            }

            if (dp[i][m] != -1) {
                return dp[i][m];
            }

            int res = INT_MIN;
            for (int x = 1; x <= 2 * m; x++) {
                res = max(res, suf[i] - f(i + x, max(m, x)));
            }

            return dp[i][m] = res;
        };
        return f(0, 1);
    }
};