class Solution {
public:
    int residuePrefixes(string s) {
        vector<int> f(26);
        int d = 0, res = 0, n = s.size();

        for (int i = 0; i < n; i++) {
            if (++f[s[i] - 'a'] == 1) {
                d++;
            }
            if (d > 2) {
                return res;
            }
            res += ((i + 1) % 3 == d % 3);
        } 
        return res;
    }
};