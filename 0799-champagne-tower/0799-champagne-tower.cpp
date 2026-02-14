class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> cur(1, poured);

        for (int i = 1; i - 1 <= query_row; i++) {
            vector<double> next(i + 1);
            for (int j = 0; j < i; j++) {
                if (cur[j] >= 1) {
                    next[j] += (cur[j] - 1) / 2.0;
                    next[j + 1] += (cur[j] - 1) / 2.0;
                    cur[j] = 1;
                }
            }
            if (i <= query_row) cur = next;
        }

        return cur[query_glass];
    }
};