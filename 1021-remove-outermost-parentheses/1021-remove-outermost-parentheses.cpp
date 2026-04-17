class Solution {
public:
    string removeOuterParentheses(string s) {
        string res = "";

        int op = 0;
        for (auto &c: s) {
            if (c == '(' && op > 0) {
                res += c;
            }
            if (c == ')' && op > 1) {
                res += c;
            }
            op += (c == '(' ? 1 : -1);
        }
        return res;
    }
};