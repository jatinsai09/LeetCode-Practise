class Solution {
#define ll long long int
const ll mod = 1e9 + 7;
public:
    int countPalindromicSubsequences(string s) {
        ll n = s.size();
        vector<vector<ll>> dp(n, vector<ll>(n));

        for (int i = n - 1; i >= 0; i--) {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; j++) {
                if (s[i] != s[j]) {
                    dp[i][j] = ( 
                        dp[i + 1][j] + dp[i][j - 1] - 
                        dp[i + 1][j - 1] + mod) % mod;
                    continue;
                }

                int l = i + 1, r = j - 1;
                while (l <= r && s[l] != s[i]) {
                    l++;
                }
                while (l <= r && s[r] != s[j]) {
                    r--;
                }

                if (l < r) {
                    dp[i][j] = (dp[i + 1][j - 1] * 2 - dp[l + 1][r - 1] + mod) % mod;
                } else if (l == r) {
                    dp[i][j] = (dp[i + 1][j  - 1] * 2 + 1) % mod;
                } else {
                    dp[i][j] = (dp[i + 1][j - 1] * 2 + 2) % mod;
                }

            }
        }

        return dp[0][n - 1];
    }
};