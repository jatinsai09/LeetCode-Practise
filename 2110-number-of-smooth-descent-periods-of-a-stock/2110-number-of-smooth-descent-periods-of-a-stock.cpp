class Solution {
#define ll long long int    
public:
    long long getDescentPeriods(vector<int>& prices) {
        ll n = prices.size(), res = 1;

        vector<ll> dp(n, 1);
        for (int i = 1; i < n; i++) {
            if (prices[i] + 1 == prices[i - 1]) {
                dp[i] = 1 + dp[i - 1];
            }
            res += dp[i];
        }

        return res;
    }
};