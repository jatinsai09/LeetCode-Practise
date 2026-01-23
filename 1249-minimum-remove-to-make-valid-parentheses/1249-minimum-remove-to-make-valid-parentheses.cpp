class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int op = 0, cl = 0;
        stack<char> st;

        for (auto &ch: s) {
            (ch == '(' ? op++ : (ch == ')' ? cl++ : 1));
            if (cl > op) {
                cl--;
            } else {
                st.push(ch);
            }
        }

        string res;
        while (!st.empty()) {
            char ch = st.top();
            st.pop();

            if (op > cl && ch == '(') {
                op--;
            } else {
                res += ch;
            }
        }

        reverse(begin(res), end(res));
        return res;
    }
};