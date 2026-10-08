class Solution {
public:
    string removeOuterParentheses(string s) {
        string res = "";

        int b = 0;
        for (const auto &c: s) {
            b += (c == '(' ? 1 : -1);

            if (c == '(' && b != 1) {
                res += c;
            } else if (c == ')' && b != 0) {
                res += c;
            }
        }
        return res;
    }
};