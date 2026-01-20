class Solution {
public:
    int minPathCost(vector<vector<int>>& g, vector<vector<int>>& moveCost) {
        int n = g.size(), m = g[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));

        dp[0] = g[0];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < m; k++) {
                    dp[i][k] = min(dp[i][k], dp[i - 1][j] + g[i][k] +
                                                moveCost[g[i - 1][j]][k]);
                }
            }
        }

        return *min_element(begin(dp[n - 1]), end(dp[n - 1]));
    }
};