class Solution {
const int mod = 1e9 + 7;
public:
    int interleaveCharacters(string word1, string word2, string target) {
        int n1 = word1.size(), n2 = word2.size(), m = target.size();

        int dp[101][101][101];
        memset(dp, -1, sizeof(dp));

        function<int(int, int, int)> dfs = [&](int i, int j, int k) -> int {
            if (k == m) {
                return (i > 0) && (j > 0);
            }

            if (i == n1 && j == n2) {
                return 0;
            }

            if (dp[i][j][k] != -1) {
                return dp[i][j][k];
            }

            long long res = 0;

            for (int ii = i; ii < n1; ii++) {
                if (word1[ii] == target[k]) {
                    res += dfs(ii + 1, j, k + 1);
                    res %= mod;
                }
            }

            for (int jj = j; jj < n2; jj++) {
                if (word2[jj] == target[k]) {
                    res += dfs(i, jj + 1, k + 1);
                    res %= mod;
                }
            }

            return dp[i][j][k] = res;
        };

        return dfs(0, 0, 0);
    }
};