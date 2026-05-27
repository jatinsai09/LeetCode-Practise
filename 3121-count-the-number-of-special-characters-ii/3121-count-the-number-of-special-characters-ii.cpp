class Solution {
public:
    int numberOfSpecialChars(string s) {
        int n = s.size();
        vector<int> lower(26, n), upper(26);

        for (int i = 0; i < n; i++) {
            if (islower(s[i])) {
                lower[s[i] - 'a'] = i;
            }
            if (isupper(s[n - 1 - i])) {
                upper[s[n - 1 - i] - 'A'] = n - 1 - i;
            }
        }

        int res = 0;
        for (int i = 0; i < 26; i++) {
            if (lower[i] < upper[i]) {
                res++;
            }
        }

        return res;
    }
};