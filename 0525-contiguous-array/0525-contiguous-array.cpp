class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size(), res = 0, sum = 0;
        unordered_map<int, int> mp;
        mp[sum] = -1;

        for (int i = 0; i < n; i++) {
            sum += (nums[i] == 1 ? 1 : -1);

            if (mp.count(sum)) {
                res = max(res, i - mp[sum]);
            } else {
                mp[sum] = i;
            }
        }
        
        return res;
    }
};