class Solution {
public:
    vector<string> generateValidStrings(int n, int k) {
        vector<string> res;
        string s(n, '0');

        function<void(int, char, int)> f = [&](int i, char prev, int cur) {
            if (i == n) {
                if (cur <= k) {
                    res.emplace_back(s);
                }
                return;
            }

            if (prev == '1') {
                f(i + 1, '0', cur);
            } else {
                s[i] = '1';
                f(i + 1, '1', cur + i);

                s[i] = '0';
                f(i + 1, '0', cur);
            }
        };

        f(0, '0', 0);
        return res;
    }
};