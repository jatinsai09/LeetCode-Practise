class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<int> dp(k + 1);

        int m = 0;
        while (dp[k] < n) {
            m++;
            for (int e = k; e > 0; e--) {
                dp[e] = 1 + dp[e] + dp[e - 1];
            }
        }

        return m;
    }
};