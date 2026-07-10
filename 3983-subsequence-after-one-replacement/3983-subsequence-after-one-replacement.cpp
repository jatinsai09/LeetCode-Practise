class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n = s.size(), m = t.size();

        if (n > m) {
            return false;
        }
        
        vector<int> l(n, m), r(n, -1);
        
        int i = 0, j = 0, prev = -1;
        while (i < n && j < m) {
            if (s[i] == t[j]) {
                l[i] = j;
                i++;
            }
            j++;
        }

        if (l[n - 1] < m) {
            return true;
        }

        j = m - 1;
        i = n - 1;
        while (i >= 0 && j >= 0) {
            if (s[i] == t[j]) {
                r[i] = j;
                i--;
            }
            j--;
        }

        for (int i = 0; i < n; i++) {
            int li = (i == 0 ? -1 : l[i - 1]);
            int ri = (i == n - 1 ? m : r[i + 1]);

            if (ri - li >= 2) {
                return true;
            }
        }

        return false;
    }
};