class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();

        vector<int> fc(26);
        int mx = 0;
        for (const auto& c: word) {
            fc[c - 'a']++;
            mx = max(mx, fc[c - 'a']);
        }

        vector<int> fb(mx + 1);
        for (int i = 0; i < 26; i++) {
            if (fc[i]) {
                fb[fc[i]]++;
            }
        }

        int res = 0, c = 0;
        for (int f = mx; f > 0; f--) {
            for (int k = 0; k < fb[f]; k++) {
                res += (1 + c / 8) * f;
                c++;
            }
        }
        return res;
    }
};