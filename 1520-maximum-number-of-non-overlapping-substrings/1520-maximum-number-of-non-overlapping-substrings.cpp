class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        unordered_map<char, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            if (!mp.count(s[i])) {
                mp[s[i]] = {i, i};
            } else {
                mp[s[i]][1] = i;
            }
        }

        for (auto &[c, ivl]: mp) {
            while (1) {
                int l = ivl[0], r = ivl[1];
                for (int i = ivl[0]; i <= ivl[1]; i++) {
                    l = min(l, mp[s[i]][0]);
                    r = max(r, mp[s[i]][1]);
                }

                if (l == ivl[0] && r == ivl[1]) {
                    break;
                }

                ivl[0] = l;
                ivl[1] = r;
            }
        }

        vector<vector<int>> ivls;
        for (const auto &[c, ivl]: mp) {
            ivls.push_back(ivl);
        }
        sort(begin(ivls), end(ivls), [&](auto& a, auto& b){
            return a[1] < b[1];
        });

        vector<string> res;

        int prev = -1;
        for (const auto &ivl: ivls) {
            if (ivl[0] > prev) {
                res.push_back(s.substr(ivl[0], ivl[1] - ivl[0] + 1));
                prev = ivl[1];
            }
        }

        return res;
    }
};