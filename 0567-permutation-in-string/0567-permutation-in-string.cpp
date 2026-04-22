class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s2.size(), m = s1.size();
        vector<int> f1(26), f2(26);
        for (auto &c: s1) {
            f1[c - 'a']++;
        }

        for (int i = 0; i < n; i++) {
            if (i >= m) {
                f2[s2[i - m] - 'a']--;
            }

            f2[s2[i] - 'a']++;

            bool yes = true;
            for (int i = 0; i < 26; i++) {
                yes &= (f1[i] == f2[i]);
            }
            if (yes) {
                return true;
            }
        }

        return false;
    }
};