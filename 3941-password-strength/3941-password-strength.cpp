class Solution {
public:
    int passwordStrength(string password) {
        unordered_map<char, int> f;
        int res = 0;
        for (auto &c: password) {
            if (++f[c] > 1) {
                continue;
            }

            if (c >= 'a' && c <= 'z') {
                res++;
            } else if (c >= 'A' && c <= 'Z') {
                res += 2;
            } else if (c >= '0' && c <= '9') {
                res += 3;
            } else {
                res += 5;
            }
        }

        return res;
    }
};