class Solution {

public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1) {
            return s;
        }

        int ml = 1, st = 0, en = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int r = 0; r < n; r++) {
            for (int l = 0; l <= r; l++) {
                if (s[l] == s[r] && (r - l <= 2 || dp[l + 1][r - 1])) {
                    dp[l][r] = true;
                    if (r - l + 1 > ml) {
                        ml = r - l + 1;
                        st = l;
                        en = r;
                    }
                }
            }
        }
        return s.substr(st, en - st + 1);
    }
};