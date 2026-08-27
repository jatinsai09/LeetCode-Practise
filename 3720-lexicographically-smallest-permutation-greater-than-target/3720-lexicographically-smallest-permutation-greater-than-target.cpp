class Solution {
public:
    bool yes(int i, auto& c2, string& t) {
        int n = t.size();
        for (int j = i; j < n; j++) {
            int f = 0;
            for (int k = 25; k >= 0; k--) {
                if (!c2[k]) {
                    continue;
                }

                if (k > t[j] - 'a') {
                    return true;
                } else if (k == t[j] - 'a') {
                    f = 1;
                    c2[k]--;
                    break;
                }
            }
            if (!f) {
                return false;
            }
        }
        return false;
    }
    string lexGreaterPermutation(string s, string t) {
        int n = s.size();
        vector<int> f(26);
        for (auto& c : s) {
            f[c - 'a']++;
        }

        int got = 0;
        string res = "";

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 26; j++) {
                if (!f[j]) {
                    continue;
                }

                f[j]--;
                if (got) {
                    res.push_back('a' + j);
                    break;
                }

                if (j == t[i] - 'a') {
                    auto c2 = f;
                    if (yes(i + 1, c2, t)) {
                        res.push_back('a' + j);
                        break;
                    }
                } else if (j > t[i] - 'a') {
                    got = 1;
                    res.push_back('a' + j);
                    break;
                }
                f[j]++;
            }
            if (res.size() == i) {
                return "";
            }
        }
        return res;
    }
};