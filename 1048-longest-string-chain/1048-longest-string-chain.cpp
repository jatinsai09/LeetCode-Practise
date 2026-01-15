class Solution {
public:
     bool check(string &s1, string &s2) {
        if (s2.size() + 1 != s1.size()) {
            return false;
        }

        int f = 0, s = 0;
        while (f < s1.size()) {
            if (s < s2.size() && s1[f] == s2[s]) {
                ++f;
                ++s;
            } else {
                ++f;
            }
        }
        if (f == s1.size() && s == s2.size()) {
            return true;
        }
        return false;
    }

    static bool compare(const string &s1, const string &s2) { return s1.length() < s2.length(); }

    int longestStrChain(vector<string>& words) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int maxi = 1, n = words.size();
        vector<int> dp(n, 1);
        sort(words.begin(), words.end(), compare);

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (check(words[i], words[j]) && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};