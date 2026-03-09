class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        vector<int> f(26);
        for (auto &c: s) {
            f[c - 'a']++;
        }

        if (n == 1) {
            return 0;
        }

        if (n == 2) {
            return (s[0] <= s[1] ? 0 : -1);
        }

        string t = s;
        sort(begin(t), end(t));

        if (s == t) {
            return 0;
        }

        if (s[0] == t[n - 1] && s[n - 1] == t[0] && f[s[0] - 'a'] == 1 && f[t[0] - 'a'] == 1) {
            return 3;
        }
        if (s[0] == t[0] || s[n - 1] == t[n - 1]) {
            return 1;
        }

        return 2;
    }
};