class Solution {
public:
    int minChanges(string s) {
        int n = s.size(), res = 0;

        for (int i = 0; i + 1 < n; i += 2) {
            res += (s[i] != s[i + 1]);
        }

        return res;
    }
};