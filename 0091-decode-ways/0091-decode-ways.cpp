class Solution {
public:
    int numDecodings(string s) {
        int n = s.size(), _1, _2;
        if(n == 1) {
            return s[0] != '0';
        }
        if (s[0] == '0') {
            return false;
        }

        vector<int> dp(n, 0);
        dp[0] = 1;
        for (int i = 1; i < n; i++) {
            _1 = (s[i] == '0' ? 0 : dp[i - 1]);
            _2 = 0;

            if (s[i - 1] > '0' && (s[i - 1] - '0') * 10 + (s[i] - '0') < 27) {
                _2 = (i >= 2 ? dp[i - 2] : 1);
            }
            dp[i] = _1 + _2;
        }
        return dp[n - 1];
    }
};