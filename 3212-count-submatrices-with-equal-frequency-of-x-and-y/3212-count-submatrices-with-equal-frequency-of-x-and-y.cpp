auto speedup = []() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return NULL;
}();

class Solution {
public:
    vector<vector<int>> gridBlockSum(vector<vector<char>>& grid, char ch) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> pre(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                pre[i][j] = (grid[i][j] == ch);
                if (i > 0)
                    pre[i][j] += pre[i - 1][j];
                if (j > 0)
                    pre[i][j] += pre[i][j - 1];
                if (i > 0 && j > 0)
                    pre[i][j] -= pre[i - 1][j - 1];
            }
        }
        return pre;
    }

    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> xc = gridBlockSum(grid, 'X');
        vector<vector<int>> yc = gridBlockSum(grid, 'Y');

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res += ((xc[i][j] == yc[i][j]) && xc[i][j] > 0);
            }
        }
        return res;
    }
};