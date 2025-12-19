class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s;

        function<void(int, int)> f = [&](int op, int cl) -> void {
            if (op == 0 && cl == 0) {
                res.push_back(s);
            }

            if (op) {
                s.push_back('(');
                f(op - 1, cl);
                s.pop_back();
            }
            if (cl > op) {
                s.push_back(')');
                f(op, cl - 1);
                s.pop_back();
            }
        };

        f(n, n);
        return res;
    }
};