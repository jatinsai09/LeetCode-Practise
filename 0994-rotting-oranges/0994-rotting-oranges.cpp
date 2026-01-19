class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        vector<int> dir = {0, -1, 0, 1, 0};

        int r = grid.size(), c = grid[0].size();
        vector<int> vis(r * c);
 
        queue<pair<int, int>> q;
        int fresh = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                int key = i * c + j;
                if (grid[i][j] == 2) {
                    vis[key] = 2;
                    q.push({key, 0});
                } else if (grid[i][j] == 1) {
                    fresh++;
                    vis[key] = 1;
                } else {
                    vis[key] = 0;
                }
            }
        }

        int maxt = 0, rotten = 0;
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            int t = p.second, key = p.first;
            int ri = key / c, ci = key % c;
            maxt = max(t, maxt);

            for (int i = 0; i < 4; i++) {
                int dr = ri + dir[i];
                int dc = ci + dir[i + 1];
                int nkey = dr * c + dc;

                if (dr >= 0 && dr < r && dc >= 0 && dc < c &&
                    vis[nkey] == 1) {
                    vis[nkey] = 2;
                    q.push({nkey, t + 1});
                    rotten++;
                }
            }
        }

        return (fresh == rotten ? maxt : -1);
    }
};