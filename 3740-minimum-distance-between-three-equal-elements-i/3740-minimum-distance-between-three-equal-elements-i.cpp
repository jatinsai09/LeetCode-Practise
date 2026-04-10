class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int res = INT_MAX, n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if(nums[i] != nums[j]) {
                    continue;
                }

                for (int k = j + 1; k < n; k++) {
                    if(nums[k] != nums[j]) {
                        continue;
                    }

                    res = min(res, (k - i) * 2);
                }
            }
        }

        return (res == INT_MAX ? -1 : res);
    }
};