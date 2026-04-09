class Solution {
public:
    int mirrorFrequency(string s) {
        int n = s.size();

        vector<int> f1(26), f2(10);

        for (auto &c: s) {
            if (c >= 'a' && c <= 'z') {
                f1[c - 'a']++;
            } else {
                f2[c - '0']++;
            }
        }

        int res = 0;
        for (int i = 0; i < 13; i++) {
            res += abs(f1[i] - f1[25 - i]);
        }

        for (int i = 0; i < 5; i++) {
            res += abs(f2[i] - f2[9 - i]);
        }
        return res;
    }
};