class Solution {
public:
    const int mod = 1e9 + 7;
    int numberOfStableArrays(int zero, int one, int limit) {
        vector<vector<vector<long long>>> dp(
            one + 1, vector<vector<long long>>(zero + 1, vector<long long>(2)));
        dp[0][0][0] = dp[0][0][1] = 1;

        for (int i = 0; i <= one; i++) {
            for (int j = 0; j <= zero; j++) {
                for (int k = 1; k <= limit; k++) {
                    if (i >= k) {
                        dp[i][j][1] = (dp[i][j][1] + dp[i - k][j][0]) % mod;
                    }
                    if (j >= k) {
                        dp[i][j][0] = (dp[i][j][0] + dp[i][j - k][1]) % mod;
                    }
                }
            }
        }
        return (dp[one][zero][0] + dp[one][zero][1]) % mod;
    }
};