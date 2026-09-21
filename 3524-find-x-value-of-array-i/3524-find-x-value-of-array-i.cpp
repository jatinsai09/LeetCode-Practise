class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> res(k, 0);
        vector<int> prev(k, 0);

        for (const auto &a : nums) {
            vector<int> cur(k, 0);

            cur[a % k]++;
            for (int i = 0; i < k; i++) {
                cur[1LL * i * a % k] += prev[i];
            }
            for (int i = 0; i < k; i++) {
                res[i] += cur[i];
            }
            
            prev = cur;
        }

        return res;
    }
};