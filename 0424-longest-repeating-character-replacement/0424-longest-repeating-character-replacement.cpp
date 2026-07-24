class Solution {
public:
    int characterReplacement(string s, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int f[26] = {0};
        int n = s.size(), mc = 0, res = 0;

        for (int l = 0, r = 0; r < n; r++) {
            mc = max(mc, ++f[s[r] - 'A']);

            int len = r - l + 1;
            if (len - mc > k) {
                f[s[l++] - 'A']--;
            } else {
                res = max(res, len);
            }
        }
        return res;
    }
};