class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int res = 0;

        for (auto& i : nums) {
            int ld = 0;
            for (auto d = 2; d * d <= i; ++d) {
                if (i % d) {
                    continue;
                }
                if (!ld) {
                    ld = d;
                } else {
                    ld = 0;
                    break;
                }
            }
            if (ld && ld * ld != i) {
                res += 1 + ld + (i / ld) + i;
            }
        }

        return res;
    }
};