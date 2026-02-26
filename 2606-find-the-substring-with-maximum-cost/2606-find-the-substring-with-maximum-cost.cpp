class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        int n = s.size(), m = vals.size();
        vector<int> mp(26);

        for (int i = 0; i < 26; i++) {
            mp[i] = i + 1;
        }

        for (int i = 0; i < m; i++) {
            mp[chars[i] - 'a'] = vals[i];
        }

        int res = 0, p = 0;
        for (int i = 0; i < n; i++) {
            p = max(mp[s[i] - 'a'], p + mp[s[i] - 'a']);
            res = max(res, p);
        }

        return res;
    }
};