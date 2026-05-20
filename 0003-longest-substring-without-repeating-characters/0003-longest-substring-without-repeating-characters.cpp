class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> f(256, -1);
        int l = 0, r = 0, maxlen = 0;
        int n = s.size();

        while (r < n) {
            if (l <= f[s[r]]) {
                l = f[s[r]] + 1;
            }

            f[s[r]] = r;
            maxlen = max(maxlen, r - l + 1);
            r++;
        }
        return maxlen;
    }
};