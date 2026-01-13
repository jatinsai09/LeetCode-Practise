class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double lo = 0, hi = 2 * 1e9;

        auto f = [&](double line) -> double {
            double aAbove = 0, aBelow = 0;
            for (auto &s: squares) {
                int x = s[0], y = s[1], l = s[2];
                double total = (double)l * l;

                if (y >= line) {
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

        while (hi - lo > 1e-5) {
            double mid = (lo + hi) / 2.0;

            if (f(mid) > 0) {
                lo = mid;
            } else {
                hi = mid;
            }
        }

        return lo;
    }
};