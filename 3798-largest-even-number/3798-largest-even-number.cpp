class Solution {
public:
    string largestEven(string s) {
        string res = s;
        while (!res.empty()) {
            if (res.back() == '2') {
                break;
            }
            res.pop_back();
        }

        return res;
    }
};