class Solution {
public:
#define ll long long int
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, INT_MIN));
        dp[0][0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                dp[i][j] = max(dp[i][j], a[i - 1] * b[j - 1] +
                                             max(0LL, dp[i - 1][j - 1]));
            }
        }

        return dp[n][m];
    }
};