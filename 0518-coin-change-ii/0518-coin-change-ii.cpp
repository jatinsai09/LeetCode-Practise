class Solution {
#define ll unsigned long long int    
public:
    int change(int amount, vector<int>& coins) {
        sort(begin(coins), end(coins));
        ll n = coins.size();
        vector<ll> dp(amount + 1, 0);
        dp[0] = 1;

        for (auto &coin: coins) {
            for (int s = coin; s <= amount; s++) {
                dp[s] += dp[s - coin];
            }
        }
        return dp[amount];
    }
};