class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> f(26), vis(26);
        for (auto &i: s) {
            f[i - 'a']++;
        }

        string res = "";
        for (auto &i: s) {
            f[i - 'a']--;
            if (vis[i - 'a']) {
                continue;
            }

            vis[i - 'a'] = 1;
            while (!res.empty() && res.back() > i && f[res.back() - 'a']) {
                vis[res.back() - 'a'] = 0;
                res.pop_back();
            }
            res.push_back(i);
        }

        return res;
    }
};