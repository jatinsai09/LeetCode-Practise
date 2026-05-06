class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int m = box.size(), n = box[0].size();
        vector<vector<char>> res(m, vector<char>(n));
        int c = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] = box[i][j];
                if (box[i][j] == '#') {
                    c++;
                    res[i][j] = '.';
                } else if (box[i][j] == '*') {
                    for (int k = j - 1; c > 0; k--, c--) {
                        res[i][k] = '#';
                    }
                }

                if (j == n - 1) {
                    for (int k = j; c > 0; k--, c--) {
                        res[i][k] = '#';
                    }
                }
            }
        }
        vector<vector<char>> ans(n, vector<char>(m));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[j][m - i - 1] = res[i][j];
            }
        }
        return ans;
    }
};