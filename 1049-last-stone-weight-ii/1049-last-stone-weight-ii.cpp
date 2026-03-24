class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();

        int sum = 0;
        for (auto &i: stones) {
            sum += i;
        }
        int target = sum >> 1;

        vector<vector<int>> dp(n + 1, vector<int>(target + 1));

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= target; j++) {
                int notTake = dp[i - 1][j];
                int take = 0;
                if (j >= stones[i - 1]) {
                    take = stones[i - 1] + dp[i - 1][j - stones[i - 1]];
                }

                dp[i][j] = max(take, notTake);
            }
        }

        int s1 = dp[n][target], s2 = sum - s1;

        return s2 - s1;
    }
};