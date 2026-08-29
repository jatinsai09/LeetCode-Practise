class Solution {
#define ll long long int
const ll mod = 1e9 + 7;
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        ll res = 0;

        vector<ll> dp(high + 1);
        dp[0] = 1;
        for (int i = min(zero, one); i <= high; i++) {
            if (i >= zero) {
                dp[i] = (dp[i] + dp[i - zero]) % mod;
            }
            if (i >= one) {
                dp[i] = (dp[i] + dp[i - one]) % mod;
            }

            if (i >= low) {
                res += dp[i];
                res %= mod;
            }
        }        

        return res;
    }
};