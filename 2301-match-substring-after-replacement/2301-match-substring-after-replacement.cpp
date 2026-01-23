class Solution {
public:
    bool matchReplacement(string& s, string& sub, vector<vector<char>>& mappings) {
        int n = s.size(), m = sub.size();
        unordered_map<char, unordered_map<char, char>> mp;

        for (auto &m: mappings) {
            mp[m[0]][m[1]] = 1;
        }

        auto can = [&](int st) -> bool {
            for (int i = 0; i < m; i++) {
                if (sub[i] == s[i + st] || mp[sub[i]][s[i + st]]) {
                    continue;
                }
                return false;
            }
            return true;
        };

        for (int i = 0; i + m <= n; i++) {
            if (can(i)) {
                return true;
            }
        }

        return false;
    }
};