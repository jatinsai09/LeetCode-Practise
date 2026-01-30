class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<int> dr = {-2, -2, 2, 2, -1, -1, 1, 1};
        vector<int> dc = {-1, 1, -1, 1, -2, 2, -2, 2};
        unordered_map<string, double> dp;

        function<double(int, int, int)> f = [&](int r, int c, int k) -> double {
            if (r < 0 || c < 0 || r >= n || c >= n) {
                return 0;
            }

            if (k == 0) {
                return 1;
            }

            string hash = to_string(r) + "#" + to_string(c) + "#" + to_string(k);
            if (dp.count(hash)) {
                return dp[hash];
            }

            double p = 0;
            for (int i = 0; i < dr.size(); i++) {
                int rr = r + dr[i];
                int cc = c + dc[i];

                p += f(rr, cc, k - 1) / 8.0;
            }

            return dp[hash] = p;
        };

        return f(row, column, k);
    }
};