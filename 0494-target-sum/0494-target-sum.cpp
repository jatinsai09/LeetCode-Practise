class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int ts = 0;
        for (const auto& i: nums) {
            ts += i;
        }

        if (abs(target) > ts || (ts - target) % 2) {
            return false;
        }

        int req = (ts + target) / 2;
        vector<int> dp(req + 1);

        dp[0] = 1;
        for (const auto& c: nums) {
            for (int s = req; s >= c; s--) {
                dp[s] += dp[s - c];
            }
        }

        return dp[req];
    }
};