class Solution {
public:
    int minDistance(string word1, string word2) {
        int maxi = longestCommonSubsequence(word1, word2);
        int r1 = word1.size() - maxi;
        int r2 = word2.size() - maxi;

        return r1 + r2;
    }
    int longestCommonSubsequence(string text1, string text2) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int m = text1.size(), n = text2.size();
        vector<int> prev(n + 1), cur(n + 1);

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