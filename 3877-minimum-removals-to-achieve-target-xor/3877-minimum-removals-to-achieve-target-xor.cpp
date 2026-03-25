class Solution {
const int m_x = 16384;
public:
    int minRemovals(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(m_x + 1, -1);
        dp[0] = 0;

        for (auto &i: nums) {
            vector<int> dp1 = dp;
            for (int x = 0; x <= m_x; x++) {
                if (dp[x] == -1) {
                    continue;
                }
                dp1[x ^ i] = max(dp1[x ^ i], dp[x] + 1);
            } 
            dp = dp1;
        }

        return  (dp[target] == -1 ? -1 : n - dp[target]);
    }
};