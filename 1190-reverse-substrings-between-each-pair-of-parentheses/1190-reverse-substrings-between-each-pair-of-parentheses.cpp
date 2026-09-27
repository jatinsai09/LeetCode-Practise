class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();

        string st = "";
        for (auto &c: s) {
            if (c == ')') {
                string rev = "";

                while (st.back() != '(') {
                    rev += st.back();
                    st.pop_back();
                }
                st.pop_back();

                st += rev;
            } else {
                st += c;
            }
        }

        return st;
    }
};