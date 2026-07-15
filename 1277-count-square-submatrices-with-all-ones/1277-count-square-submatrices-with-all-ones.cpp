class Solution {
public:
    int countSquares(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();

        auto dp = g;
        int res = 0;
        {
            for (int i = 0; i < n; i++) {
                res += dp[i][0];
            }
            for (int j = 1; j < m; j++) {
                res += dp[0][j];
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (!dp[i][j]) {
                    continue;
                }

                dp[i][j] =
                    1 + min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});

                res += dp[i][j];
            }
        }

        return res;
    }
};