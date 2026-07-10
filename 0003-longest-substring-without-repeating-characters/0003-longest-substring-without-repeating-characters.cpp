class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> prev(256, -1);
        int l = 0, r = 0, maxlen = 0;
        int n = s.size();

        while (r < n) {
            if (l <= prev[s[r]]) {
                l = prev[s[r]] + 1;
            }

            prev[s[r]] = r;
            maxlen = max(maxlen, r - l + 1);
            r++;
        }
        return maxlen;
    }
};