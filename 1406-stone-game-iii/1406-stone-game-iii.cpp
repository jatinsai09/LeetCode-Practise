class Solution {
public:
    string stoneGameIII(vector<int>& a) {
        int n = a.size();

        int dp[4] = {0};
        for (int i = n - 1; i >= 0; i--) {
            dp[i % 4] = a[i] - dp[(i + 1) % 4];

            if (i + 2 <= n) {
                dp[i % 4] = max(dp[i % 4], a[i] + a[i + 1] - dp[(i + 2) % 4]);
            }
            if (i + 3 <= n) {
                dp[i % 4] = max(dp[i % 4], a[i] + a[i + 1] + a[i + 2] - dp[(i + 3) % 4]);
            }
        }

        if (dp[0] == 0) {
            return "Tie";
        }
        return (dp[0] > 0 ? "Alice" : "Bob");
    }
};