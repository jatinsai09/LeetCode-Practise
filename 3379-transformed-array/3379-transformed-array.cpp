class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);

        for (int i = 0; i < n; i++) {
            int di = (i + nums[i]) % n;
            if (di < 0) {
                di += n;
            }
            res[i] = nums[di]; 
        }

        return res;
    }
};