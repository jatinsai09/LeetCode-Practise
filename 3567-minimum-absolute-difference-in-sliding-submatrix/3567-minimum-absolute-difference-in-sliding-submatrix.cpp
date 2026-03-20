class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();

        int rows = m - k + 1, cols = n - k + 1;
        vector<vector<int>> res(rows, vector<int>(cols, 0));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                vector<int> val(k * k);
                int ind = 0;
                for (int x = i; x < i + k; x++) {
                    for (int y = j; y < j + k; y++) {
                        val[ind++] = grid[x][y];
                    }
                }
                sort(begin(val), end(val));

                int mn = INT_MAX;
                for (int t = 1; t < k * k; t++) {
                    if (val[t] != val[t - 1]) {
                        int del = val[t] - val[t - 1];
                        if (del < mn) {
                            mn = del;
                        }
                    }
                }
                res[i][j] = (mn == INT_MAX ? 0 : mn);
            }
        }
        return res;
    }
};