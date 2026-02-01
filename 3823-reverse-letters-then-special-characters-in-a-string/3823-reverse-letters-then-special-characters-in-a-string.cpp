class Solution {
public:
    string reverseByType(string s) {
        stack<char> st1, st2;
        for (auto &c: s) {
            if (isalpha(c)) {
                st1.push(c);
            } else {
                st2.push(c);
            }
        }

        for (auto &c: s) {
            if (isalpha(c)) {
                c = st1.top();
                st1.pop();
            } else {
                c = st2.top();
                st2.pop();
            }
        }

        return s;
    }
};