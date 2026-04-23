class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> res(n, vector<int>(m, 0)), ut(res);

        queue<pair<int, int>> q;
        for (auto &v: sources) {
            int r = v[0], c = v[1], clr = v[2];
            res[r][c] = clr; 
            q.push({r, c});
        }

        vector<int> dir = {-1, 0, 1, 0, -1};

        int t = 0;
        while (!q.empty()) {
            t++;
            int sz = q.size();

            for (int i = 0; i < sz; i++) {
                auto [r, c] = q.front();
                int clr = res[r][c];
                q.pop();

                for (int j = 0; j < 4; j++) {
                    int nr = r + dir[j], nc = c + dir[j + 1];
                    if (nr < 0 || nc < 0 || nr >= n || nc >= m) {
                        continue;
                    }

                    if (res[nr][nc] == 0) {
                        res[nr][nc] = clr;
                        q.push({nr, nc});
                        
                        ut[nr][nc] = t;
                    } else if (ut[nr][nc] == t) {
                        res[nr][nc] = max(res[nr][nc], clr);
                    }
                }
            }
        }

        return res;
    }
};