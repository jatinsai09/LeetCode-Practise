class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int pos = 0, neg = 0, res = 0;

        for (const auto &i: nums) {
            if (i == 0) {
                pos = 0;
                neg = 0;
                continue;
            }
        
            pos++;
            (neg ? neg++ : 1);

            if (i < 0) {
                swap(pos, neg);
            }

            res = max(res, pos);
        }
        return res;
    }
};