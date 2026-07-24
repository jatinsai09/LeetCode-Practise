class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        
        int f[256] = {0};
        for (const auto& c : t) {
            f[c]++;
        }

        int ms = INT_MAX, st = -1, c = 0;
        for (int l = 0, r = 0; r < n; r++) {
            if (--f[s[r]] >= 0) {
                c++;
            }

            while (c == m) {
                if (r - l + 1 < ms) {
                    ms = r - l + 1;
                    st = l;
                }

                c -= (++f[s[l++]] > 0);
            }

            if (ms == m) {
                break;
            }
        }

        return (st == -1) ? "" : s.substr(st, ms);
    }
};