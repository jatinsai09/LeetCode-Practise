class Solution {
public:
    int missingMultiple(vector<int>& a, int k) {
        vector<bool> vis(102);
        for (const auto &i:a){
            if (i % k == 0) {
                vis[i / k] = true;
            }
        }

        for (int i = 1; i <= 101; i++) {
            if(!vis[i]) {
                return i * k;
            }
        }
        return 0;
    }
};