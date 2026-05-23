class Solution {
public:
    int maxDepth(string s) {
        int cur = 0, res = 0;
        for (auto &c: s) {
            if (c == '(') {
                res = max(res, ++cur);
            } else if (c == ')') {
                cur--;
            }
        }

        return res;
    }
};