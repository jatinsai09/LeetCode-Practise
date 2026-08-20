class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();

       vector<int> a0, a1;
       a0.push_back(nums[0]);
       a1.push_back(nums[1]);

        for (int i = 2; i < n; i++) {
            if (a0.back() > a1.back()) {
                a0.push_back(nums[i]);
            } else {
                a1.push_back(nums[i]);
            }
        }
        a0.insert(a0.end(), a1.begin(), a1.end());

        return a0;
    }
};