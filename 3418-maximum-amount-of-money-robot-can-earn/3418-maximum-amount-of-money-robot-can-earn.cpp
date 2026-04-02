class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size(), m = coins[0].size();

        vector<vector<vector<int>>> dp(n,
                                       vector<vector<int>>(m, vector<int>(3, INT_MIN)));
        dp[0][0][0] = coins[0][0];
        dp[0][0][1] = dp[0][0][2] = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < 3; k++) {
                    if (i) {
                        dp[i][j][k] =
                            max(dp[i][j][k], coins[i][j] + dp[i - 1][j][k]);
                    }
                    if (j) {
                        dp[i][j][k] =
                            max(dp[i][j][k], coins[i][j] + dp[i][j - 1][k]);
                    }
                    if (coins[i][j] < 0 && k) {
                        if (i) {
                            dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1]);
                        }
                        if (j) {
                            dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k - 1]);
                        }
                    }
                }
            }
        }

        return max(
            {dp[n - 1][m - 1][0], dp[n - 1][m - 1][1], dp[n - 1][m - 1][2]});
    }
};