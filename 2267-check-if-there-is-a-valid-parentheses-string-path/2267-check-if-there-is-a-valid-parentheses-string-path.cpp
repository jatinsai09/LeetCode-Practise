class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();

        if (grid[0][0] == ')') {
            return 0;
        }
        if (grid[n - 1][m - 1] == '(') {
            return 0;
        }

        int dp[101][101][202];
        memset(dp, -1, sizeof(dp));

        function<int(int, int, int)> f = [&](int i, int j, int bal) -> int {
            if (bal < 0) {
                return 0;
            }
            if (i == n - 1 && j == m - 1) {
                return bal == 0;
            }

            if (dp[i][j][bal] != -1) {
                return dp[i][j][bal];
            }

            int yes = 0;

            if (i + 1 < n) {
                int newBal = bal;
                newBal += (grid[i + 1][j] == '(' ? 1 : -1);

                yes |= f(i + 1, j, newBal);
            }

            if (j + 1 < m) {
                int newBal = bal;
                newBal += (grid[i][j + 1] == '(' ? 1 : -1);

                yes |= f(i, j + 1, newBal);
            }

            
            return dp[i][j][bal] = yes;
        };

        return f(0, 0, 1);
    }
};