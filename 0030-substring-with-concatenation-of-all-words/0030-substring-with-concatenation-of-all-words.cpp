class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> f;
        vector<int> res;
        for (const auto& w : words) {
            f[w]++;
        }
        int n = s.length(), num = words.size(), l = words[0].length();
        int window = l * num;

        for (int i = 0; i < l; i++) {
            unordered_map<string, int> mp = f;
            int left = i, req = num;
            for (int j = i; j < n; j += l) {
                string t = s.substr(j, l);
                if (--mp[t] >= 0) {
                    req--;
                }
                while (mp[t] < 0) {
                    if (++mp[s.substr(left, l)] > 0) {
                        req++;
                    }
                    left += l;
                }
                if (!req) {
                    res.push_back(left);
                }
            }
        }
        return res;
    }
};