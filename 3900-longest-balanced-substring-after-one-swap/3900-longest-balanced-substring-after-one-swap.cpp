class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size(), res = 0;

        int t1 = 0;
        for (auto &c: s) {
            t1 += (c - '0');
        }
        int t0 = n - t1;

        unordered_map<int, int> mp;
        mp[0] = -1;

        unordered_map<int, int> mp0;
        unordered_map<int, int> mp1;

        int s1 = 0, c1 = 0, c0 = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                s1++; 
                c1++;
            } else {
                s1--;
                c0++;
            }

            if (mp.count(s1)) {
                res = max(res, i - mp[s1]);
            }

            int ta = s1 - 2; // replace 1 with 0
            if (mp.count(ta)) {
                if (c0 < t0) { // from suffix
                    res = max(res, i - mp[ta]);
                } else if (mp0.count(ta)) { // from prefix
                    res = max(res, i - mp0[ta]);
                }
            }

            int tb = s1 + 2; // replace 0 with 1
            if (mp.count(tb)) {
                if (c1 < t1) { // from suffix
                    res = max(res, i - mp[tb]);
                } else if (mp1.count(tb)) { // from prefix
                    res = max(res, i - mp1[tb]);
                }
            }

            if (!mp.count(s1)) {
                mp[s1] = i;
            }

            if (c0 && !mp0.count(s1)) {
                mp0[s1] = i;
            }
            if (c1 && !mp1.count(s1)) {
                mp1[s1] = i;
            }
        }

        return res;
    }
};