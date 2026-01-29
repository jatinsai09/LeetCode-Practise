class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> di = {2, 2, 1, 1, -1, -1, -2, -2};
        vector<int> dj = {-1, 1, -2, 2, -2, 2, -1, 1};

        function<bool(int, int, int)> dfs = [&](int i, int j, int time) -> bool {
            if (grid[i][j] != time) {
                return false;
            }

            if (time == n * n - 1) {
                return true;
            }

        
            for (int k = 0; k < di.size(); k++) {
                int ii = di[k] + i;
                int jj = dj[k] + j;

                if (ii >= 0 && jj >= 0 && ii < n && jj < n) {
                    if (dfs(ii, jj, time + 1)) {
                        return true;
                    }
                }
            }
            
            return false;
        };

        return dfs(0, 0, 0);
    }
};