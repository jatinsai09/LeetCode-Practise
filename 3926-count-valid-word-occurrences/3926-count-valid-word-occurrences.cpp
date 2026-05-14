class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        unordered_map<string, int> f;
        string s = "", cur = "";
        for (auto &str: chunks) {
            s += str;
        }

        int n = s.size();
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (ch >= 'a' && ch <= 'z') {
                cur += ch;
            } else if (ch == '-') {
                if (cur.size() && i + 1 < n && (s[i + 1] >= 'a' && s[i + 1] <= 'z')) {
                    cur += '-';
                } else {
                    if (cur.size()) {
                        f[cur]++;
                    }
                    cur = "";
                }
            } else {
                if (cur.size()) {
                    f[cur]++;
                }
                cur = "";
            }
        }
        if (cur.size()) {
            f[cur]++;
        }

        vector<int> res;
        for (auto &q: queries) {
            res.push_back(f[q]);
        }

        return res;
    }
};