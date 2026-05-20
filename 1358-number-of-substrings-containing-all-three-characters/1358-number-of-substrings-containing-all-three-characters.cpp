class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size(), res = 0, prev[3] = {-1, -1, -1};
        for (int i = 0; i < n; i++) {
            prev[s[i] - 'a'] = i;
            res += 1 + min({prev[0], prev[1], prev[2]});
        }
        return res;
    }
};