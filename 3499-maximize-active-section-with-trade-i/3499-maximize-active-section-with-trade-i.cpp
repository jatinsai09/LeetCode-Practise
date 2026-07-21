class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size(), c1 = 0;
        for (auto &c: s) {
            c1 += (c - '0');
        }

        int prev0 = 0, cur0 = 0, mx = 0;
        for (auto &c: s) {
            if (c == '1') {
                if (prev0 && cur0) {
                    mx = max(mx, cur0 + prev0);
                } 
                if (cur0) {
                    prev0 = cur0;
                    cur0 = 0;
                }
            } else {
                cur0++;
            }
        }
        if (prev0 && cur0) {
            mx = max(mx, cur0 + prev0);
        }

        return c1 + mx;
    }
};