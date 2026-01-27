class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        if (k == 0) {
            return nums;
        }
        int n = nums.size();
        vector<int> v;

        for (auto &i: nums) {
            if (i >= 0) {
                v.push_back(i);
            }
        }

        int m = v.size();
        if (m == 0) {
            return nums;
        } 
        k %= m;

        vector<int> r;
        for (int i = k; i < m; i++) {
            r.push_back(v[i]);
        }
        for (int i = 0; i < k; i++) {
            r.push_back(v[i]);
        }

        int j = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] >= 0) {
                nums[i] = r[j++];
            }
        }

        return nums;
    }
};