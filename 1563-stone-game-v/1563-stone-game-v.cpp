class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> ps(n + 1);

        for (int i = 1; i <= n; i++) {
            ps[i] = ps[i - 1] + stoneValue[i - 1];
        }

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));
        function<int(int, int)> f = [&](int l, int r) -> int {
            if (dp[l][r] != -1) {
                return dp[l][r];
            }

            int res = 0;
            for (int m = l; m < r; m++) {
                int ls = ps[m + 1] - ps[l], rs = ps[r + 1] - ps[m + 1];

                if (ls <= rs) {
                    res = max(res, ls + f(l, m));
                } 
                if (rs <= ls) {
                    res = max(res, rs + f(m + 1, r));
                }

                if (2 * min(ls, rs) <= res) {
                    break;
                }
            }
            return dp[l][r] = res;
        };

        return f(0, n - 1);
    }
};