class Solution {
#define ll long long    
public:
    long long countPairs(vector<string>& words) {
        ll n = words.size(), m = words[0].size(), res = 0;
        unordered_map<string, ll> f;

        for (int i = 0; i < n; i++) {
            int df = words[i][0] - 'a';
            for (int j = 0; j < m; j++) {
                int key = words[i][j] - 'a';
                int newKey = (key - df + 26) % 26;
                words[i][j] = 'a' + newKey;
            }
            f[words[i]]++;
        }

        for (auto &[p, f]: f) {
            res += f * (f - 1) / 2; 
        }

        return res;
    }
};