class Solution {
public:
    string reverseParentheses(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = s.size();
        
        vector<int> open, pair(n);
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                open.push_back(i);
            } else if (s[i] == ')') {
                int j = open.back();
                open.pop_back();

                pair[i] = j;
                pair[j] = i;
            }
        }

        string res;
        for (int i = 0, d = 1; i < n; i += d) {
            if (s[i] == '(' || s[i] == ')') {
                i = pair[i], d = -d;
            } else {
                res += s[i];
            }
        }
        return res;
    }
};