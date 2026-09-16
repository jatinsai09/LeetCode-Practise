class Solution {
#define ll long long int
const ll mod = 1e9 + 7;
public:
    int numberOfSets(int n, int k) {
        ll dp[n + 1][k + 1];
        memset(dp, 0, sizeof(dp));
        
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        
        for (int j = 1; j <= k; j++) {
            ll sum = 0;
            for (int i = 2; i <= n; i++) {
                sum += dp[i - 1][j - 1];
                sum %= mod;

                dp[i][j] = (dp[i - 1][j] + sum) % mod;
            }
        }

        return dp[n][k];
    }
};