class Solution {
public:
    long long minimumCost(string s, string t, int flipCost, int swapCost,
                          int crossCost) {
        int n = s.size();
        long long res = 0;

        if (2 * flipCost <= swapCost) {
            for (int i = 0; i < n; i++) {
                if (s[i] != t[i]) {
                    res += flipCost;
                }
            }
            return res;
        }

        long long s0 = 0, t0 = 0;
        for (int i = 0; i < n; i++) {
            s0 += (s[i] == '0');
            t0 += (t[i] == '0');
        }

        res = min(t0, s0) * swapCost;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0' && s[i] == t[i]) {
                res -= swapCost;
            }
        }

        if (2 * flipCost <= swapCost + crossCost) {
            res += abs(s0 - t0) * flipCost;
        } else {
            res += (abs(s0 - t0) / 2) * (swapCost + crossCost);
            if (abs(s0 - t0) & 1) {
                res += flipCost;
            }
        }
        return res;
    }
};