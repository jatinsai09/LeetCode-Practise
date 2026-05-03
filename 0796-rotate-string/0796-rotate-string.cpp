class Solution {
public:
    vector<int> build(string pattern) {
        int n = pattern.size();
        vector<int> lps(n);

        int len = 0, i = 1;
        while (i < n) {
            if (pattern[i] == pattern[len]) {
                lps[i++] = ++len;
            } else { 
                if (len == 0) {
                    lps[i++] = 0;
                } else {
                    len = lps[len - 1];
                }
            }
        }

        return lps;
    }
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) {
            return false;
        }

        string text = s + s;
        vector<int> lps = build(goal);

        int i = 0, j = 0;

        while (i < text.size()) {
            if (text[i] == goal[j]) {
                i++;
                j++;
            }

            if (j == goal.size()) {
                return true;
            }

            if (i < text.size() && text[i] != goal[j]) {
                if (j == 0) {
                    i++;
                } else {
                    j = lps[j - 1];
                }
            }
        }
        
        return false;
    }
};