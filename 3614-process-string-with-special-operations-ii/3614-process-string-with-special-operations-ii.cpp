class Solution {
#define ll long long int
public:
    char processStr(string s, long long k) {
        ll len = 0;
        k++;

        for (auto &c : s) {
            if (c >= 'a') {
                len++;
            } else if (c == '#') {
                len *= 2LL;
            } else if (c == '*' && len) {
                len--;
            }
        }

        if (k > len) {
            return '.';
        }

        int n = s.size();
        for (int i = n - 1; i >= 0; i--) {
            char op = s[i];
            if (op >= 'a') {
                if (len == k) {
                    return op;
                }
                len--;
            } else if (op == '*') {
                len++;
            } else if (op == '#') {
                len /= 2;
                if (k > len) {
                    k -= len;
                }
            } else if (op == '%') {
                k = len - k + 1;
            }
        }

        return '.';
    }
};