class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<char>> mp;
        unordered_map<string, bool> dp;
        for (auto& s : allowed) {
            mp[s.substr(0, 2)].push_back(s[2]);
        }

        function<bool(int, string, string)> f = [&](int i, string cur,
                                                    string b) -> bool {
            if (b.size() == 1) {
                return true;
            }
            if (i == b.size() - 1) {
                if (dp.count(cur)) {
                    return dp[cur];
                }
                return dp[cur] = f(0, "", cur);
            }

            string key = b.substr(i, 2);
            if (!mp.count(key)) {
                return false;
            }

            for (auto& ch : mp[key]) {
                if (f(i + 1, cur + ch, b)) {
                    return true;
                }
            }
            return false;
        };

        return f(0, "", bottom);
    }
};