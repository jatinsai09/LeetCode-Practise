class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (auto& c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                if (st.empty()) {
                    return false;
                }
                char op = st.top();
                st.pop();

                if ((op == '(' && c != ')') || (op == '[' && c != ']') ||
                    (op == '{' && c != '}')) {
                    return false;
                }
            }
        }

        return st.empty();
    }
};