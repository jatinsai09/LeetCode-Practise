class Solution {
public:
    int minInsertions(string s) {
        int maxi = longestPalindromeSubseq(s);

        return s.size() - maxi;
    }
    int longestPalindromeSubseq(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        string s1 = s;
        reverse(begin(s1), end(s1));

        return longestCommonSubsequence(s, s1);
    }

    int longestCommonSubsequence(string text1, string text2) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int m = text1.size(), n = text2.size();
        vector<int> prev(n + 1, 0), cur(n + 1, 0);

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    cur[j] = 1 + prev[j - 1];
                } else {
                    cur[j] = max(prev[j], cur[j - 1]);
                }
            }
            prev = cur;
        }
        return cur[n];
    }
};