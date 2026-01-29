class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        // vector<int> di = {2, 2, 1, 1, -1, -1, -2, -2};
        // vector<int> dj = {-1, 1, -2, 2, -2, 2, -1, 1};
        vector<int> dir = {-1, 2, 1, -2, -1, -2, 1, 2, -1};


        function<bool(int, int, int)> dfs = [&](int i, int j, int time) -> bool {
            if (grid[i][j] != time) {
                return false;
            }

            if (time == n * n - 1) {
                return true;
            }

        
            for (int k = 1; k < dir.size(); k++) {
                int ii = dir[k - 1] + i;
                int jj = dir[k] + j;

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