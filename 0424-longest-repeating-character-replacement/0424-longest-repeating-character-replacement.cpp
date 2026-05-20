class Solution {
public:
    int characterReplacement(string s, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int f[26] = {0};
        int l = 0, r = 0, n = s.size(), mc = 0, res = 0;

        while (r < n) {
            f[s[r] - 'A']++;
            mc = max(mc, f[s[r] - 'A']);

            int len = r - l + 1;
            if (len - mc > k) {
                f[s[l++] - 'A']--;
            } else {
                res = max(res, len);
            }
            r++;
        }
        return res;
    }
};