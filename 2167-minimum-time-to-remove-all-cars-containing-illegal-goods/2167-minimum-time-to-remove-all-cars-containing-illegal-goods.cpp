class Solution {
public:
    int minimumTime(string s) {
        int n = s.size();

        vector<int> dpl(n), dpr(n);
        dpl[0] = (s[0] == '1');
        for (int i = 1; i < n; i++) {
            if (s[i] == '1') {
                dpl[i] = min(dpl[i - 1] + 2, i + 1);
            } else {
                dpl[i] = dpl[i - 1];
            }
        }

        dpr[n - 1] = (s[n - 1] == '1');
        for (int i = n - 2; i >= 0; i--) {
            if (s[i] == '1') {
                dpr[i] = min(dpr[i + 1] + 2, n - i);
            } else {
                dpr[i] = dpr[i + 1];
            }
        }

        int res = min(dpl[n - 1], dpr[0]);
        for (int i = 0; i + 1 < n; i++) {
            res = min(res, dpl[i] + dpr[i + 1]);
        }

        return res;
    }
};