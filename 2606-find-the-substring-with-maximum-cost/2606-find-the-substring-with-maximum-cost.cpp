class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        int n = s.size(), m = vals.size();
        unordered_map<char, int> mp;

        for (int i = 0; i < 26; i++) {
            mp[char('a' + i)] = i + 1;
        }

        for (int i = 0; i < m; i++) {
            mp[chars[i]] = vals[i];
        }

        int res = 0, p = 0;
        for (int i = 0; i < n; i++) {
            p = max(mp[s[i]], p + mp[s[i]]);
            res = max(res, p);
        }

        return res;
    }
};