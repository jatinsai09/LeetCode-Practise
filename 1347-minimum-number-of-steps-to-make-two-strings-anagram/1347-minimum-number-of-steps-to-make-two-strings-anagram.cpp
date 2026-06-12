class Solution {
public:
    int minSteps(string s, string t) {
        int n = s.size();
        vector<int> del(26);
        for (int i = 0; i < n; i++) {
            del[s[i] - 'a']++;
            del[t[i] - 'a']--;
        }

        int res = 0;
        for (int i = 0; i < 26; i++) {
            if (del[i] > 0) {
                res += del[i];
            }
        }

        return res;
    }
};