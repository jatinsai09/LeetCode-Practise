class Solution {
public:
    vector<string> generateValidStrings(int n, int k) {
        vector<string> res;
        string s(n, '0');

        function<void(int, string, int)> f = [&](int i, string s, int cur) {
            if (i == n) {
                if (cur <= k) {
                    res.emplace_back(s);
                }
                return;
            }

            char prev = '0';
            if (i) {
                prev = s[i - 1];
            }

            if (prev == '1') {
                f(i + 1, s, cur);
            } else {
                s[i] = '1';
                f(i + 1, s, cur + i);

                s[i] = '0';
                f(i + 1, s, cur);
            }
        };

        f(0, s, 0);
        return res;
    }
};