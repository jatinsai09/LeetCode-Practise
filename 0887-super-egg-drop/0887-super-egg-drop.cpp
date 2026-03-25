class Solution {
public:
    int superEggDrop(int k, int n) {
        // vector<int> dp(k + 1);

        // int m = 0;
        // while (dp[k] < n) {
        //     m++;
        //     for (int e = k; e > 0; e--) {
        //         dp[e] = 1 + dp[e] + dp[e - 1];
        //     }
        // }

        // return m;

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        int m = 0;
        while (dp[m][k] < n) {
            m++;
            for (int e = 1; e <= k; e++) {
                dp[m][e] = dp[m - 1][e - 1] + dp[m - 1][e] + 1;
            }
        }

        return m;
    }
};