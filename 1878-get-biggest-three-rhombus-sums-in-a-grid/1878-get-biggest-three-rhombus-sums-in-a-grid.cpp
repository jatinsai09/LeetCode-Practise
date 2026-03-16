class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), mx = (min(m, n) + 1) >> 1;
        set<int> s;

        for (auto& v : grid) {
            for (auto& i : v) {
                s.insert(i);
                if (s.size() > 3) {
                    s.erase(begin(s));
                }
            }
        }

        for (int l = 1; l < mx; l++) {
            for (int i = l; i + l < n; i++) {
                for (int j = l; j + l < m; j++) {
                    int sum = 0;

                    for (int k = 0; k <= l; k++) {
                        sum += grid[i - l + k][j + k];
                        sum += grid[i - l + k][j - k];
                        sum += grid[i + l - k][j + k];
                        sum += grid[i + l - k][j - k];
                    }

                    sum -= (grid[i - l][j] + grid[i + l][j] + grid[i][j - l] +
                            grid[i][j + l]);

                    s.insert(sum);
                    if (s.size() > 3) {
                        s.erase(begin(s));
                    }
                }
            }
        }

        return vector<int>(rbegin(s), rend(s));
    }
};