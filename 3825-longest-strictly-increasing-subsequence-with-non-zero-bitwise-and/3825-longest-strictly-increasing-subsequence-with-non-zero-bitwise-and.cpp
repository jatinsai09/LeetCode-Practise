class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        
        int n = nums.size(), res = 0;
        for (int b = 0; b <= 30; b++){
            vector<int> v;
            for (auto &i: nums) {
                if (i & (1 << b)) {
                    v.push_back(i);
                }
            }
            if (v.empty()) {
                continue;
            }

            vector<int> lis = {v[0]};
            int len = 1;
            for (int i = 1; i < v.size(); i++) {
                if (v[i] > lis.back()) {
                    lis.push_back(v[i]);
                    len++;
                } else {
                    int ind = lower_bound(begin(lis), end(lis), v[i]) - begin(lis);
                    lis[ind] = v[i];
                }
            }

            res = max(res, len);
        }

        return res;
    }
};