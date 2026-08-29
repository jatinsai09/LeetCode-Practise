class Solution {
#define ll unsigned int
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<ll> dp(target + 1);

        dp[0] = 1;
        for (int s = 1; s <= target; s++) {
            for (const auto &i: nums) {
                if (i <= s) {
                    dp[s] += dp[s - i];
                }
            }
        }

        return dp[target];
    }
};