class Solution {
public:
    bool isSubsequence(string s, string t) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int m = s.size(), n = t.size();
        int ind = 0;
        for (int i = 0; i < n; i++) {
            if (t[i] == s[ind])
                ind++;
        }
        if (ind == m)
            return true;
        return false;
    }
};