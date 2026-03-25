class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        long long sum = 0;
        for (auto& vec : grid) {
            for (auto& i : vec) {
                sum += i;
            }
        }
        if (sum & 1) {
            return false;
        }

        long long got = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                got += grid[i][j];
            }
            if (sum - got == got) {
                return true;
            }
        }

        got = 0;
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                got += grid[i][j];
            }
            if (sum - got == got) {
                return true;
            }
        }
        
        return false;
    }
};