class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s;
        int open = n, close = n;

        function<void()> f = [&]() -> void {
            if (open + close == 0) {
                res.push_back(s);
            }

            if (open) {
                s.push_back('(');
                open--;

                f();

                open++;
                s.pop_back();
            }
            if (close > open) {
                s.push_back(')');
                close--;

                f();

                close++;
                s.pop_back();
            }
        };

        f();
        return res;
    }
};