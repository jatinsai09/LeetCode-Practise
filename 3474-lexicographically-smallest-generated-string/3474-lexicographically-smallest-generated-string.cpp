class Solution {
public:
    string generateString(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        string res(n + m - 1, 'a');
        vector<bool> fixed(n + m - 1, false); 

        for (int i = 0; i < n; i++) {
            if (s1[i] == 'T') {
                for (int j = i; j < i + m; j++) {
                    if (fixed[j] && res[j] != s2[j - i]) {
                        return "";
                    }
                    res[j] = s2[j - i];
                    fixed[j] = true;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (s1[i] == 'F') {
                bool yes = false;
                int ind = -1;
                for (int j = i; j < i + m; j++) {
                    if (res[j] != s2[j - i]) {
                        yes = true;
                        break;
                    }
                    if (!fixed[j]) {
                        ind = j;
                    }
                }
                if (!yes) {
                    if (ind == -1) {
                        return "";
                    } else {
                        res[ind] = 'b';
                    }
                }
            }
        }

        return res;
    }
};