class Solution {
public:
    // int dpp[2005];
    // bool isPal(string& s, int i, int j) {
    //     while (i < j) {
    //         if (s[i++] != s[j--]) {
    //             return false;
    //         }
    //     }
    //     return true;
    // }
    // int help(int i, int n, string& s) {
    //     if (i == n) {
    //         return 0;
    //     }

    //     if (dpp[i] != -1) {
    //         return dpp[i];
    //     }

    //     int minCost = INT_MAX;

    //     for (int k = i; k < n; k++) {
    //         if (isPal(s, i, k)) {
    //             int cost = 1 + help(k + 1, n, s);
    //             minCost = min(cost, minCost);
    //         }
    //     }
    //     return dpp[i] = minCost;
    // }
    int minCut(string s) {
        int n = s.size();
        //memset(dpp, -1, sizeof(dpp));
        vector<vector<int>> pal(n + 1, vector<int>(n + 1, 0));
        int dp[n + 1];
        dp[n] = 0;

        for (int i = n - 1; i >= 0; i--) {
            int minCost = INT_MAX;
            for (int k = i; k < n; k++) {
                if (s[i] == s[k] && (i + 1 >= k - 1 || pal[i + 1][k - 1])) {
                    pal[i][k] = 1;
                    int cost = 1 + dp[k + 1];
                    minCost = min(cost, minCost);
                }
            }
            dp[i] = minCost;
        }

        return dp[0] - 1;
    }
};