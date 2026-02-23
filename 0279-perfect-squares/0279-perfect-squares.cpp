class Solution {
#define ll long long int    
public:
    int numSquares(int n) {
        vector<ll> dp(n + 1, n);
        dp[0] = 0;

        for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j * j <= i; j++) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }

        return dp[n];
    }
};