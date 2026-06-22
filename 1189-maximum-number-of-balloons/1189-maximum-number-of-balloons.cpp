class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int res = INT_MAX;
        string req = "balloon";
        vector<int> f(26);

        for (auto &c: text) {
            if (req.find(c) != string::npos) {
                f[c - 'a']++;
            }
        }

        for (int i = 0; i < 26; i++) {
            char c = 'a' + i;
            if (req.find(c) != string::npos) {
                if (c == 'l' || c == 'o') {
                    res = min(res, f[i] / 2);
                } else {
                    res = min(res, f[i]);
                }
            }
        }

        return res;
    }
};