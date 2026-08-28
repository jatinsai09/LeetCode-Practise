class Solution {
public:
    string lexPalindromicPermutation(string s, string t) {
        int n = s.size(), f[26] = {0};
        for (const auto& c : s) {
            f[c - 'a']++;
        }

        int oc = 0;
        for (auto& i : f) {
            oc += (i & 1);
        }
        if (oc > 1) {
            return "";
        }

        char oddc = ' ';
        for (int i = 0; i < 26; i++) {
            if (f[i] & 1) {
                oddc = char('a' + i);
            }
            f[i] /= 2;
        }

        string res = "";
        for (int i = 0; i < n / 2; i++) {
            bool valid = false;
            for (int ci = 0; ci < 26; ci++) {
                char c = char('a' + ci);

                if (c < t[i] || f[ci] == 0) {
                    continue;
                }

                if (c > t[i]) {
                    f[ci]--;
                    res.push_back(c);
                    for (int cci = 0; cci < 26; cci++) {
                        for (int j = 0; j < f[cci]; j++) {
                            res.push_back(char('a' + cci));
                        }
                    }

                    string rev = res;
                    reverse(begin(rev), end(rev));

                    if (oddc != ' ') {
                        res.push_back(oddc);
                    }

                    return res + rev;
                }

                f[ci]--;
                res.push_back(c);

                string copy = res;
                for (int cci = 25; cci >= 0; cci--) {
                    for (int j = 0; j < f[cci]; j++) {
                        copy.push_back(char('a' + cci));
                    }
                }
                string revc = copy;
                reverse(begin(revc), end(revc));

                if (oddc != ' ') {
                    copy.push_back(oddc);
                }
                if (copy + revc > t) {
                    valid = true;
                    break;
                }

                f[ci]++;
                res.pop_back();
            }
            if (!valid) {
                return "";
            }
        }

        string rev = res;
        reverse(begin(rev), end(rev));

        if (oddc != ' ') {
            res.push_back(oddc);
        }
        string out = res + rev;

        return (out > t ? out : "");
    }
};