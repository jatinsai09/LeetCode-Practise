class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = grid.size(), res = 0;

        map<vector<int>, int> mp;
        for (auto &row: grid) {
            mp[row]++;
        }

        for (int j = 0; j < n; j++) {
            vector<int> v;
            for (int i = 0; i < n; i++) {
                v.push_back(grid[i][j]);
            }
            res += mp[v];
        }

        return res;
    }
};