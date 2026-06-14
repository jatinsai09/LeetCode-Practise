class Solution {
public:
    int getLength(vector<int>& nums) {
        int n = nums.size(), res = 1;

        for (int i = 0; i < n; i++) {
            unordered_map<int, int> f, bf;
            for (int j = i; j < n; j++) {
                int k = nums[j];
                if (f[k]) {
                    if (--bf[f[k]] == 0) {
                        bf.erase(f[k]);
                    }
                }
                f[k]++;
                bf[f[k]]++;

                if (f.size() == 1) {
                    res = max(res, j - i + 1);
                } else if (bf.size() == 2) {
                    auto it = bf.begin();
                    int f1 = it->first, f2 = next(it)->first;
                    if (f1 > f2) {
                        swap(f1, f2);
                    }

                    if (f1 * 2 == f2) {
                        res = max(res, j - i + 1);
                    }
                }
            }
        }

        return res;
    }
};