class Solution {
public:
    string decodeString(const string& s, int& i) {
        int n = s.size();
        string res;

        while (i < n && s[i] != ']') {
            if (!isdigit(s[i])) {
                res += s[i++];
            } else {
                int f = 0;
                while (i < n && isdigit(s[i])) {
                    f = f * 10 + s[i++] - '0';
                }
                i++; //'['

                string t = decodeString(s, i);

                i++; //']'
                while (f-- > 0) {
                    res += t;
                }
            }
        }
        return res;
    }
    string decodeString(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int i = 0;
        return decodeString(s, i);
    }
};