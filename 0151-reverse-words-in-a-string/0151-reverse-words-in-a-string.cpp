class Solution {
public:
    string reverseWords(string s) {
        reverse(begin(s), end(s));

        int n = s.size(), l = 0, r = 0;
        for (int i = 0; i < n; i++, l = r) {
            while (i < n && s[i] == ' ') {
                i++;
            }
            if (i == n) {
                break;
            }

            while (i < n && s[i] != ' ') {
                s[r++] = s[i++];
            }
            reverse(begin(s) + l, begin(s) + r);
            s[r++] = ' ';
        }
        s.resize(r - 1);
        return s;
    }
};