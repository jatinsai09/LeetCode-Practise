class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
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
        if (s[0] == t[0] || s[n - 1] == t[n - 1]) {
            return 1;
        }

        for (int i = 1; i + 1 < n; i++) {
            if (s[i] == t[0] || s[i] == t[n - 1]) {
                return 2;
            }
        }

        return 3;
    }
};