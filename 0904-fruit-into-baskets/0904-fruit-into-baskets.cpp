class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> f;
        
        int c = 0, n = fruits.size(), res = 0;
        for (int l = 0, r = 0; r < n; r++) {
            c += (++f[fruits[r]] == 1);
            if (c >= 3) {
                c -= (--f[fruits[l]] == 0);
                if (f[fruits[l]] == 0) {
                    f.erase(fruits[l]);
                }
                l++;
            }
            if(c <= 2) {
                res = max(res, r - l + 1);
            }
        }
        return res;
    }
};
