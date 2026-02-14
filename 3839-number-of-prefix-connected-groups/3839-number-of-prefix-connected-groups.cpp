class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        int res = 0;
        unordered_map<string, int> mp;

        for (auto &w: words) {
            if (w.size() < k) {
                continue;
            }
            string ss = w.substr(0, k);
            mp[ss]++;
        }

        for (auto it: mp) {
            if (it.second > 1) {
                res++;
            }
        }

        return res;
    }
};