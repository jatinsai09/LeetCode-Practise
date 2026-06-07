class Solution {
public:
    vector<string> generateValidStrings(int n, int k) {
        vector<string> res;
        int lim = (1LL << n);

        for (int x = 0; x < lim; x++) {
            string s(n, '0');
            int t = x, j = n - 1;

            while (t) {
                if (t & 1) {
                    s[j] = '1';
                }
                j--;
                t >>= 1;
            }

            int score = 0;
            for (int i = 0; i < n; i++) {
                if (s[i] == '1') {
                    score += i;
                    if (i && s[i] == s[i - 1]) {
                        score = k + 1;
                        break;
                    }
                }
            }
            if (score <= k) {
                res.push_back(s);
            }
        }

        return res;
    }
};