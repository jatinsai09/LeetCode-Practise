class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        unordered_set<string> st(begin(wordDict), end(wordDict));
        int n = s.size();
        vector<int> dp(n + 1);
        dp[n] = 1;

        for (int i = n - 1; i >= 0; i--) {
            string temp = "";
            for (int j = i; j < n; j++) {
                temp += s[j];
                if (dp[j + 1]) {
                    dp[i] = (st.count(temp) > 0);
                }
                if (dp[i]) {
                    break;
                }
            }
        }
        return dp[0];
    }
};