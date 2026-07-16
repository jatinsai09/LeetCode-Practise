class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), res = 0;

        auto find = [&](int l, int r) -> int {
            int c = 0;
            while (l >= 0 && r < n) {
                if(s[l--] != s[r++]) {
                    return c;
                }
                c++;
            }
            return c;
        };

        for (int i = 0; i < n; i++) {
            res += find(i, i); // odd length palindromes with i as center
            res += find(i, i + 1); // even length palindromes with [i, i + 1] as center
        }
        return res;
    }
};