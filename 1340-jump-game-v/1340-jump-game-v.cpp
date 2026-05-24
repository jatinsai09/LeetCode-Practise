class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size(), res = 1;
        vector<int> dp(n, -1);

        function<int(int)> dfs = [&](int i) -> int {
            if (dp[i] != -1) {
                return dp[i];
            }

            int mx = 1;

            for (int j = i + 1; j <= min(n - 1, i + d); j++) {
                if (arr[j] >= arr[i]) {
                    break;
                }
                mx = max(mx, 1 + dfs(j));
            }

            for (int j = i - 1; j >= max(0, i - d); j--) {
                if (arr[j] >= arr[i]) {
                    break;
                }
                mx = max(mx, 1 + dfs(j));
            }

            return dp[i] = mx;
        };

        for (int i = 0; i < n; i++) {
            res = max(res, dfs(i));
        }

        return res;
    }
};