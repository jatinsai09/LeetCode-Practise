class Solution {
public:
    string removeOccurrences(string s, string part) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = s.size(), m = part.size(), j = 0;
        string str = s;
        for (int i = 0; i < n; i++) {
            str[j++] = s[i];
            if (j >= m && str.substr(j - m, m) == part) {
                j -= m;
            }
        }
        return str.substr(0, j);
    }
};