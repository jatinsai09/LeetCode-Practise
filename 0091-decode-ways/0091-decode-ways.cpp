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
            _1 = 0;
            _2 = 0;

            if (s[i] != '0') {
                _1 = dp[i - 1];
            }
            if ((s[i - 1] == '1') || (s[i - 1] == '2' && s[i] <= '6')) {
                _2 = (i == 1 ? 1 : dp[i - 2]);
            }
            dp[i] = _1 + _2;
        }
        return dp[n - 1];
    }
};