class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        int dp[1001][1001];
        memset(dp, -1, sizeof(dp));

        int sum = 0;
        for (const auto& i: stones) {
            sum += i;
        }

        function<int(int, int, int)> f = [&](int i, int j, int sum) -> int {
            if (i == j) {
                return 0;
            }

            if (dp[i][j] != -1) {
                return dp[i][j];
            }

            int l = (sum - stones[i]) - f(i + 1, j, sum - stones[i]);
            int r = (sum - stones[j]) - f(i, j - 1, sum - stones[j]);

            return dp[i][j] = max(l, r);
        };

        return f(0, n - 1, sum);
    }
};