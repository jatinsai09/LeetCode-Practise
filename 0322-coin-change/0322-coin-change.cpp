class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // sort(begin(coins), end(coins));
        int n = coins.size();
        vector<int> dp(amount + 1, amount + 1);

        dp[0] = 0;
        for (const auto &coin: coins) {
            for (int s = coin; s <= amount; s++) {
                if (dp[s - coin] <= amount) {
                    dp[s] = min(dp[s], 1 + dp[s - coin]);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};