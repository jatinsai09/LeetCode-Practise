class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> a, b;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j]) {
                    a.push_back({i, j});
                }
                if (img2[i][j]) {
                    b.push_back({i, j});
                }
            }
        }

        int res = 0;

        vector<vector<int>> f(n * 2, vector<int>(n * 2));
        for (auto &c1: a) {
            int x1 = c1.first, y1 = c1.second;
            for (auto &c2: b) {
                int x2 = c2.first, y2 = c2.second;

                int dx = x2 - x1, dy = y2 - y1;
                res = max(res, ++f[dx + n][dy + n]); 
            }
        }

        return res;
    }
};