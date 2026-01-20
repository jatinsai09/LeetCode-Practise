class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;

        for (auto &x: nums) {
            if (x == 2) {
                res.push_back(-1);
                continue;
            }
            for (int b = 0; b <= 30; b++) {
                if (x & (1 << b)) {
                    continue;
                }
                res.push_back(x - (1 << (b - 1)));
                break;
            }
        }

        return res;
    }
};