class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        int n = squares.size();
        double lo = 0, hi = 2 * 1e9;

        auto f = [&](double line) -> double {
            double aAbove = 0, aBelow = 0;
            for (int i = 0; i < n; i++) {
                int x = squares[i][0], y = squares[i][1];
                int l = squares[i][2];
                double total = (double)l * l;

                if (line <= y) {
                    aAbove += total;
                } else if (line >= y + l) {
                    aBelow += total;
                } else {
                    double aboveHeight = (y + l) - line;
                    double belowHeight = line - y;
                    aAbove += l * aboveHeight;
                    aBelow += l * belowHeight;
                }
            }
            return aAbove - aBelow;
        };

        for (int i = 0; i < 60; i++) {
            double mid = (lo + hi) / 2.0;
            double diff = f(mid);

            if (diff > 0) {
                lo = mid;
            } else {
                hi = mid;
            }
        }

        return lo;
    }
};