class Solution {
public:
    string generateString(string pattern, string sub) {
        int n = pattern.size(), m = sub.size(), L = n + m - 1;
        string result(L, '?');
        vector<bool> locked(L, false);

        for (int i = 0; i < n; i++) {
            if (pattern[i] == 'T') {
                for (int k = 0; k < m; k++) {
                    int pos = i + k;
                    if (result[pos] == '?') {
                        result[pos] = sub[k];
                        locked[pos] = true;
                    } else if (result[pos] != sub[k]) {
                        return "";
                    }
                }
            }
        }

        for (int i = 0; i < L; i++) {
            if (result[i] == '?') {
                result[i] = 'a';
            }
        }

        for (int i = 0; i < n; i++) {
            if (pattern[i] == 'F') {
                bool matches = true;
                vector<int> modifiable;

                for (int k = 0; k < m; k++) {
                    int pos = i + k;
                    if (result[pos] != sub[k]) {
                        matches = false;
                        break;
                    }
                    if (!locked[pos]) {
                        modifiable.push_back(pos);
                    }
                }

                if (matches) {
                    if (modifiable.empty()) {
                        return "";
                    }
                    int j = modifiable.back();
                    bool updated = false;
                    for (char c = result[j] + 1; c <= 'z'; c++) {
                        if (c != sub[j - i]) {
                            result[j] = c;
                            updated = true;
                            break;
                        }
                    }
                    if (!updated) {
                        return "";
                    }
                }
            }
        }

        return result;
    }
};