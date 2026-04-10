class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int res = INT_MAX, n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) 
            {
                if(nums[i] == nums[j]) {
                    for (int k = j + 1; k < n; k++) 
                    {
                        if(nums[k] == nums[j]) {
                            res = min(res, 2 * (k - i));
                        }
                    }
                }
            }
        }

        return (res == INT_MAX ? -1 : res);
    }
};