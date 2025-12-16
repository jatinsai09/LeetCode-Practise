class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size(), s = 0, mx = 0;
        for (auto &w: weights) {
            s += w;
            mx = max(mx, w);
        }

        int l = mx, r = s, m;

        auto possible = [&](int limit) -> bool {
            int time = 1, got = 0;

            for (auto &w: weights) {
                got += w;
                if (got > limit) {
                    time++;
                    got = w;
                }
            }

            return time <= days;
        };

        while (l <= r) {
            m = l + (r - l) / 2;

            if (possible(m)) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return l;
    }
};