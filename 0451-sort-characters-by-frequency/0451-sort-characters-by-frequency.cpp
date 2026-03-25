class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> f;
        for (auto& x : s) {
            f[x]++;
        }

        vector<pair<int, char>> vp;
        for (auto &it: f) {
            vp.push_back({it.second, it.first});
        }
        sort(begin(vp), end(vp), [&](auto& x, auto& y){
            if (x.first == y.first) {
                return x.second < y.second;
            }
            return x.first > y.first;
        });

        string res = "";
        for (auto& p: vp) {
            for (int i = 0; i < p.first; i++) {
                res += p.second;
            }
        }
        return res;
    }
};