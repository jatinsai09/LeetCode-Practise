class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        
        int f[256] = {0};
        for (auto& c : t) {
            f[c]++;
        }

        int l = 0, r = 0, ms = INT_MAX, st = -1, c = 0;
        while (r < n) {
            if (f[s[r]]-- > 0) {
                c++;
            }

            while (c == m) {
                if (r - l + 1 < ms) {
                    ms = r - l + 1;
                    st = l;
                }
                if(ms == m) break;

                if (++f[s[l]] > 0) c--;
                l++;
            }
            r++;
        }

        return (st == -1) ? "" : s.substr(st, ms);
    }
};