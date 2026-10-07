class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int n = s.size(), ml = 0;
        vector<string> got;

        function<void(int, int, string)> f = [&](int i, int b, string cur) -> void {
            if (b < 0) {
                return;
            }

            if (i == n) {
                if (b == 0) {
                    got.push_back(cur);
                    ml = max(ml, (int)cur.size());
                }
                return;
            }

            if (s[i] != '(' && s[i] != ')') {
                f(i + 1, b, cur + s[i]);
                return;
            } 

            f(i + 1, b, cur);
            f(i + 1, b + (s[i] == '(' ? 1 : -1), cur + s[i]);
        };
        f(0, 0, "");

        set<string> st;
        for (const auto &str: got) {
            if (str.size() == ml) {
                st.insert(str);
            }
        }

        vector<string> res(begin(st), end(st));

        return res;
    }
};