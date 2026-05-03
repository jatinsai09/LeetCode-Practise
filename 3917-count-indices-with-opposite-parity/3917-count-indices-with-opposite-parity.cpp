class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);

        int po = 0, pe = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] & 1) {
                res[i] = pe;
                po++;
            } else {
                res[i] = po;
                pe++;
            }
        }

        return res;
    }
};