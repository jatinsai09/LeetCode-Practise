class Solution {
#define ll long long    
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<ll> dp(n + 1, LONG_MAX);
        dp[0] = 0;

        for(int i = 1; i <= n; i++) {
            for(int j = i - 1; j >= max(0, i - 3); j--) {
                dp[i] = min(dp[i], dp[j] + costs[i - 1] + (i - j) * (i - j));
            }
        }
        return (int)dp[n];
    }
};