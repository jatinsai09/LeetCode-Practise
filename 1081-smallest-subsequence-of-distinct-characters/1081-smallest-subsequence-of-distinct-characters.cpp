class Solution {
public:
    string smallestSubsequence(string s) {
        string res = "";
        int n = s.size();
        vector<int> last(26), vis(26);
        for(int i = 0; i < n; i++) {
            last[s[i] - 'a'] = i;
        }

        for (int i = 0; i < n; i++) {
            if(vis[s[i] - 'a']) {
                continue;
            }
            vis[s[i] - 'a'] = 1;
            while(!res.empty() && res.back() > s[i] && last[res.back() - 'a'] > i) {
                vis[res.back() - 'a'] = 0;
                res.pop_back();
            }
            res.push_back(s[i]);
        }

        return res;
    }
};