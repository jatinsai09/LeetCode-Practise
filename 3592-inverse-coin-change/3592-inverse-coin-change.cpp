class Solution {
public:
    vector<int> findCoins(vector<int>& numWays) {
        int n = numWays.size();
        vector<int> dp(n + 1), res;
        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            int given = numWays[i - 1];
            if (dp[i] != given) {
                if (given - dp[i] != 1) {
                    return {};
                }
                
                res.push_back(i);
                for (int j = i; j <= n; j++) {
                    dp[j] += dp[j - i];
                }
            }
        }
        return res;
    }
};