class Solution {
#define ll long long    
public:
    long long countPairs(vector<string>& words) {
        ll n = words.size(), m = words[0].size(), res = 0;
        unordered_map<string, ll> f;

        for (int i = 0; i < n; i++) {
            string label = "";
            for (int j = 1; j < m; j++) {
                int del = words[i][j] - words[i][j - 1];
                if (del < 0) {
                    del = del + 26;
                }
                label += ('a' + del);
            }
            f[label]++;
        }

        for (auto &[label, freq]: f) {
            res += freq * (freq - 1) / 2; 
        }

        return res;
    }
};