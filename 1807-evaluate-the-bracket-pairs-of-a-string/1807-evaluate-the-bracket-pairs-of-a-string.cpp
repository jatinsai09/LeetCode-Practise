class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.size();

        unordered_map<string, string> mp;
        for (const auto &v: knowledge) {
            mp[v[0]] = v[1];
        }

        string res = "";
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                int j = i + 1;
                string key = "";

                while (j < n) {
                    if (s[j] == ')') {
                        break;
                    }
                    key += s[j++];
                }

                auto it = mp.find(key);
                if (it != mp.end()) {
                    res += it->second;
                } else {
                    res += "?";
                }

                i = j;
            } else {
                res += s[i];
            }
        }

        return res;
    }
};