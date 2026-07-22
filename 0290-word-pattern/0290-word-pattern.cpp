class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n = pattern.size();
        vector<string> v;

        string str = "";
        for (const auto& ch : s) {
            if (ch == ' ') {
                v.push_back(str);
                str = "";
            } else {
                str += ch;
            }
        }
        v.push_back(str);

        if (v.size() != n) {
            return false;
        }

        
        unordered_map<char, string> mp1; // pattern to string
        unordered_map<string, char> mp2; // string to pattern
        for (int i = 0; i < n; i++) {
            if (mp1.find(pattern[i]) == mp1.end()) { // not present
                mp1[pattern[i]] = v[i];
            }
            if (mp2.find(v[i]) == mp2.end()) { // not present
                mp2[v[i]] = pattern[i];
            }

            if (mp1[pattern[i]] != v[i]) {
                return false;
            }

            if (mp2[v[i]] != pattern[i]) {
                return false;
            }
        }
        return true;
    }
};