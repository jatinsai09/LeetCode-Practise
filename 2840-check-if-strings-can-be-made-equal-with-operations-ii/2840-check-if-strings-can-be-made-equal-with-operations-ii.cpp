class Solution {
public:
    bool checkStrings(string s1, string s2) {
        if (s1 == s2) {
            return true;
        }

        int n = s1.size();
        vector<int> fo(26), fe(26);
        for (int i = 0; i < n; i++) {
            if (i & 1) {
                fo[s1[i] - 'a']++;
                fo[s2[i] - 'a']--;
            } else {
                fe[s1[i] - 'a']++;
                fe[s2[i] - 'a']--;
            }
        }

        for (int i = 0; i < 26; i++) {
            if (fo[i] || fe[i]) {
                return false;
            }
        }

        return true;
    }
};